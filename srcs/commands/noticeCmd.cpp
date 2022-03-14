#include "ft_irc.hpp"

void noticeCmd(Server &server, int index, parsed *parsedCommand) {
	std::string message = parsedCommand->getFullTwoPointsArgs();
	std::string response;
	std::string user = *parsedCommand->args[0];
	response = noticeResponse(server, index, user, message);
	int user_index = server.findUserIndex(user);
	if (user_index == -1)
		server.sendErrorServerUser(user.c_str(), NULL, NULL, ERR_NOSUCHNICK, index);
	else
		server.ssend(response, user_index);
}
