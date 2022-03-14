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
		response = newUserResponse((*parsedCommand->args[0]));
	}
	else
	{
		POUT("totem")
		if (checkNickError((*parsedCommand->args[0]), index, server) == true)
			return ;
	 	response = nickResponse((*parsedCommand->args[0]), oldNick);
	}
	server.setNick(index, (*parsedCommand->args[0]));
	server.ssend(response, index);
}

//NICK tgontier
