#include "ft_irc.hpp"

void	passCmd(Server &server, int index, parsed *parsedCommand) {
	std::string pass = *parsedCommand->args[0];
	std::string invalidPassword("Invalid password\n");

	if (parsedCommand->args.size() == 0)
		server.sendErrorUser(parsedCommand->rawCommand.c_str(), NULL, NULL, ERR_NEEDMOREPARAMS, index);
	else if (server.isValidPass(pass) == true) {
		if (server.isRegistered(index) == false)
			server.sregister(index);
		else
			server.sendErrorUser(NULL , NULL, NULL, ERR_ALREADYREGISTRED, index);
	}
	else
		server.ssend(invalidPassword, index);
}
