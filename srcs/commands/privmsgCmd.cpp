#include "ft_irc.hpp"

std::string getMessage(parsed *parsedCommand)
{
	bool sum = {false};
	int charSkip = 1;
	std::string tmp("");

	for (size_t i = 1; i < parsedCommand->args.size(); i++) {
		if ((*parsedCommand->args[i])[0] == ':')
			sum = true;
		if (sum == true) {
			tmp += (parsedCommand->args[i]->c_str() + charSkip);
			charSkip = 0;
			tmp += " ";
		}
	}
	return (tmp);
}

bool toChannel(std::string &command)
{
	if (command.find_first_of("#") == std::string::npos)
		return (false);
	return (true);
}

std::string getAwayResponse(std::string user, std::string message)
{
	std::string tmp;
	tmp += "[" + user + "] is away (";
	message.insert(message.length() - 1, ")\n");
	tmp.insert(tmp.length(), message.c_str());
	return (tmp);
}

bool isVersion(std::string &command)
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

void	versionCmd(Server &server, int index) {
	std::string version = "Version: 108.114.99\n";
	server.ssend(version, index);
}

void privmsgCmd(Server &server, int index, parsed *parsedCommand) {
	std::string message = getMessage(parsedCommand);
	std::string response;

	if (isVersion(parsedCommand->rawCommand) == true) {
			versionCmd(server, index);
	}
	if (parsedCommand->channels.size() > 0) {
			std::string channelName = (*parsedCommand->channels[0]);
			response = privmsgResponse(server, index, channelName, message);
			server.sendToOtherUsersInChannel(channelName, response, index);
	} else {
		std::string user = (*parsedCommand->args[0]);
		response = privmsgResponse(server, index, user, message);
		int user_index = server.findUserIndex(user);
		if (user_index == -1) {
			server.sendErrorServerUser(user.c_str(), NULL, NULL, ERR_NOSUCHNICK, index);
			return ;
		}
		else {
			if (server.isUserAway(user_index) == true) {
				std::string awayMessage = server.getUserAwayMessage(user_index);
				std::string awayResponse = getAwayResponse(user, awayMessage);
				server.ssend(awayResponse, index);
			}
			server.ssend(response, user_index);
		}
	}
}
