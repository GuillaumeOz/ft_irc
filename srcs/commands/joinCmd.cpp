#include "ft_irc.hpp"

bool	isAChannel(std::string string) {
	return (string[0] == '#');
}

bool	isValidJoinCmd(Server &server, parsed *parsedCommand) {
	if (parsedCommand->channels.size() == 0) {
		server.sendErrorServer(parsedCommand->args[0]->c_str(), NULL, NULL, ERR_NOSUCHCHANNEL);
		return false;
	}
	if (!isAChannel(*parsedCommand->args[0])) {
		return false;
	}
	return (true);
}

void	joinCmd(Server &server, int index, parsed *parsedCommand) {
	std::string channelTopic("topic not set.");
	std::string response;

	if (!isValidJoinCmd(server, parsedCommand))
		return ;
	std::string channelName = (*parsedCommand->args[0]);
	if (server.userIsinChannel(channelName, index))
		return ;
	response = joinResponse(server, index, channelName);
	if (server.isExistingChannel(channelName) == true) {
		server.joinChannel(index, channelName);
	} else {
		server.addChannel(channelName, channelTopic, index);
		server.getUsers()[index]->assignChannelUserMode(channelName, MODE_CHANNEL_USER_O);
	}
	server.addChannelToUser(index, channelName);
	server.sendToAllUsersInChannel(channelName, response);
}
