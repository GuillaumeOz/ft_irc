#include "ft_irc.hpp"

bool			toChannel(std::string &command)
{
	if (command.find_first_of("#") == std::string::npos)
		return (false);
	return (true);
}

std::string 	getAwayResponse(std::string user, std::string message)
{
	std::string tmp;
	tmp += "[" + user + "] is away (";
	message.insert(message.length(), ")\n");
	tmp.insert(tmp.length(), message.c_str());
	return (tmp);
}

bool 			isVersion(std::string &command)
{
	std::string test;
	test += "PRIVMSG ircserv :";
	test += static_cast<char>(129);
	test += "VERSION";
	test += static_cast<char>(129);
	test += "\r\n";
	if (command.compare(test) == -128)
		return (true);
	return (false);
}

void			versionCmd(Server &server, int index) {
	std::string version = "Version: 108.114.99\n";
	server.ssend(version, index);
}

bool			checkModeError(Server &server, int user_index, int channel_index, std::string channelName) {
	std::string  channelModes = server.getChannelModes(channel_index);
	if (channelModes.find("m") != std::string::npos) {
		if (server.isChannelUserModeOn(user_index, channelName, MODE_CHANNEL_USER_O) == false && server.isChannelUserModeOn(user_index, channelName, MODE_CHANNEL_USER_V) == false) {
			server.sendErrorServerUser(server.getNick(user_index).c_str(), NULL, NULL, ERR_CANNOTSENDTOCHAN, user_index);
			return (true);
		}
	}
	if (channelModes.find("n") != std::string::npos) {
		if (server.isUserInChannel(channelName, user_index) == false) {
			server.sendErrorServerUser(server.getNick(user_index).c_str(), NULL, NULL, ERR_CANNOTSENDTOCHAN, user_index);
			return (true);
		}
	}
	return (false);
}

void 			privmsgCmd(Server &server, int index, parsed *parsedCommand) {
	std::string message = parsedCommand->getFullTwoPointsArgs();
	std::string response;

	if (isVersion(parsedCommand->rawCommand) == true) {
			versionCmd(server, index);
	}
	if (parsedCommand->channels.size() > 0) {
		std::string channelName = (*parsedCommand->channels[0]);
		int channel_index = server.findChannelIndex(channelName);
		if (checkModeError(server, index, channel_index, channelName) == true)
			return ;
		response = privmsgResponse(server, index, channelName, message);
		server.sendToOtherUsersInChannel(channelName, response, index);
	}
	else {
		std::string user = (*parsedCommand->args[0]);
		response = privmsgResponse(server, index, user, message);
		int user_index = server.findUserIndex(user);
		if (user_index == -1) {
			server.sendErrorServerUser(user.c_str(), NULL, NULL, ERR_NOSUCHNICK, index);
			return ;
		}
		else {
			if (server.isUserModeOn(MODE_USER_A, user_index)) {
				std::string awayMessage = server.getUserAwayMessage(user_index);
				std::string awayResponse = getAwayResponse(user, awayMessage);
				server.ssend(awayResponse, index);
			}
			server.ssend(response, user_index);
		}
	}
}
