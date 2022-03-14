#include "ft_irc.hpp"

void	userCmd(Server &server, int index, parsed *parsedCommand) {
	if (parsedCommand->args.size() < 4)
		server.sendErrorUser(parsedCommand->rawCommand.c_str(), NULL, NULL, ERR_NEEDMOREPARAMS, index);
	else {
		std::string tmp = parsedCommand->twoPointsArgs[0]->c_str() + 1;
		server.setUsername(index, *parsedCommand->args[0]);
		server.setHost(index, *parsedCommand->args[2]);
		server.setRealname(index, tmp);
	}
}
