#include "ft_irc.hpp"

std::string	getPass(std::string &command) {
	size_t i = getTokenPos(command, " ");

	if (i != std::string::npos) {
		std::string tmp = command.c_str() + i + 1;
		size_t pos = getTokenPos(tmp, "\r");
		tmp.erase(pos, tmp.length() - pos);
		return (tmp);
	}
	return (command);
}

void	passCmd(Server &server, int index, std::string &command) {
	std::string pass = getPass(command);
	std::string invalidPassword(":Invalid password\n");

	if (!isToken(command, " "))
		server.sendErrorUser(command.c_str(), NULL, NULL, ERR_NEEDMOREPARAMS, index);
	else if (server.isValidPass(pass) == true) {
		if (server.isRegistered(index) == false)
			server.sregister(index);
		else
			server.sendErrorUser(NULL , NULL, NULL, ERR_ALREADYREGISTRED, index);
	}
	else
		server.ssend(invalidPassword, index);
}
