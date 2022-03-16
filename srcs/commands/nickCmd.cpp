#include "ft_irc.hpp"

void	setRandomNick(std::string nick, int index, Server &server) {
	std::string 		newNick;
	std::stringstream	itoa;
	std::string			response;
	srand (time(NULL));

	GENNICK:
	itoa << rand() % 100;
	newNick = "Guest" + itoa.str();
	for (size_t i = 0; i < server.getUsers().size(); i++) {
		if (server.getNick(i).compare(newNick) == 0)
			goto GENNICK;
	}
	server.setNick(index, (newNick));
	response = nickResponse(newNick, nick);
	server.ssend(response, index);
}

bool checkNickError(std::string &nick, int index, Server &server)
{
	if (nick.size() > 9) {
		server.sendErrorServerUser(nick.c_str(), NULL, NULL, ERR_ERRONEUSNICKNAME, index);
		server.setUserInvalidNick(index, nick);
		return (true);
	}
	for (size_t i = 0; i < server.getUsers().size(); i++)
	{
		if (server.getNick(i).compare(nick) == 0) {
			server.sendErrorServerUser(nick.c_str(), NULL, NULL, ERR_NICKNAMEINUSE, index);
			setRandomNick(nick, index, server);
			return (true);
		}
	}
	if (server.isUserModeOn(MODE_USER_R, index) == true) {
	    server.sendErrorServerUser(NULL, NULL, NULL, ERR_RESTRICTED, index);
		POUT("nick error")
	    return (true);
	}
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
		if (checkNickError((*parsedCommand->args[0]), index, server) == true)
			return ;
	 	response = nickResponse((*parsedCommand->args[0]), oldNick);
	}
	server.setNick(index, (*parsedCommand->args[0]));
	server.ssend(response, index);
}

//NICK tgontier
