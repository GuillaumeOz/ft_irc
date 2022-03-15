#include "ft_irc.hpp"


void partCmd(Server &server, int index, parsed *parsedCommand) {
	std::string channelName = *parsedCommand->channels[0];
	std::string reason = parsedCommand->getFullTwoPointsArgs();
	std::string response = partResponse(server, index, channelName, reason);
	if (server.isExistingChannel(channelName)) {
		server.sendToAllUsersInChannel(channelName, response);
		server.delUserFromChannel(channelName, index);
		server.delChannelFromUser(channelName, index);
		if (server.isChannelEmpty(channelName) == true)
			server.delChannel(channelName);
	}
	else
		server.sendErrorServer(channelName.c_str(), NULL, NULL, ERR_NOSUCHCHANNEL);
}
