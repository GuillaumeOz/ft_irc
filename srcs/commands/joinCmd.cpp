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
	std::string keyword = "";
	if (parsedCommand->args.size() > 1)
		keyword += (*parsedCommand->args[1]);
	if (server.userIsinChannel(channelName, index))
		return ;
	response = joinResponse(server, index, channelName);
	if (server.isExistingChannel(channelName) == true) {
		int channel_index = server.findChannelIndex(channelName);
		if (server.isChannelModeOn(MODE_CHANNEL_K, channel_index)) {
			if (keyword.compare(server.channels[channel_index]->getKeyword()) != 0) {
				server.sendErrorServerUser(server.getNick(index).c_str(), NULL, NULL, ERR_BADCHANNELKEY, index);
				return ;
			}
		}
		if (server.isChannelModeOn(MODE_CHANNEL_L, channel_index)) {
			if (server.channels[channel_index]->getNumberofUsers() == server.channels[channel_index]->getUserLimit()) {
				server.sendErrorServerUser(server.getNick(index).c_str(), NULL, NULL, ERR_CHANNELISFULL, index);
				return ;
			}
		}
		server.joinChannel(index, channelName);
	} else {
		server.addChannel(channelName, channelTopic, index);
	}
	server.addChannelToUser(index, channelName);
	server.sendToAllUsersInChannel(channelName, response);
}
