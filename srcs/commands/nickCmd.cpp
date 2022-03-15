#include "ft_irc.hpp"

bool checkNickError(std::string &nick, int index, Server &server)
{
	(void)index;
	if (nick.size() > 9) {
		server.sendErrorServerUser(nick.c_str(), NULL, NULL, ERR_ERRONEUSNICKNAME, index);
		return (true);
	}
	for (size_t i = 0; i < server.getUsers().size(); i++)
	{
		if (server.getNick(i).compare(nick) == 0) {
			server.sendErrorServerUser(nick.c_str(), NULL, NULL, ERR_NICKNAMEINUSE, index);
			return (true);
		}
	}
	// if (server.getUsers()[index]->isModeOn(MODE_USER_R) == true) {
	//     server.sendErrorServer(nick.c_str(), NULL, NULL, ERR_RESTRICTED, index);
	//     return (true);
	// }
	return (false);
}

void	joinBot(Server &server, int index) {
	parsed *parsedCommand;
	std::string joinBot("JOIN #bot\n");
	parsedCommand = getParsedCommandLine(joinBot);
	joinCmd(server, index, parsedCommand);
}

void nickCmd(Server &server, int index, parsed *parsedCommand) {
	std::string response;
	static bool pending = {false};
	std::string oldNick = server.getNick(index);

	if (oldNick == "") {
		if (pending == true) {
			if (checkNickError(*parsedCommand->args[0], index, server) == true)
				return ;
			response = nickResponse(*parsedCommand->args[0], server.getUserInvalidNick(index));
			server.ssend(response, index);
		}
		if (checkNickError(*parsedCommand->args[0], index, server) == true) {
			pending = true;
			server.setUserInvalidNick(index, *parsedCommand->args[0]);
			return ;
		}
		server.setNick(index, (*parsedCommand->args[0]));
		response = newUserResponse((*parsedCommand->args[0]));
		joinBot(server, index);
	}
	else
	{
		if (checkNickError((*parsedCommand->args[0]), index, server) == true)
			return ;
		server.setNick(index, (*parsedCommand->args[0]));
	 	response = nickResponse((*parsedCommand->args[0]), oldNick);
	}
	server.ssend(response, index);
}

//NICK tgontier
