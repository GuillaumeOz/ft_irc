#include "ft_irc.hpp"

void	quitCmd(Server &server, int index, parsed *parsedCommand) {
	std::string reason = parsedCommand->getFullTwoPointsArgs();
	POUT(reason)
	std::vector<std::string> uchannel = server.getUsers()[index]->getUchannels();

	for (size_t i = 0; i < uchannel.size(); i++) {
		std::string response = quitResponse(server, index, uchannel[i], reason);
		server.sendToAllUsersInChannel(uchannel[i], response);
		server.delUserFromChannel(uchannel[i], index);
		if (server.isChannelEmpty(uchannel[i]) == true)
			server.delChannel(uchannel[i]);
	}
	server.closeUser(index);
}
