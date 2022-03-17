#include "ft_irc.hpp"

void	joinBot(Server &server, int index) {
	parsed *parsedCommand;
	std::string joinBot("JOIN #bot\n");
	parsedCommand = getParsedCommandLine(joinBot);
	joinCmd(server, index, parsedCommand);
	delete parsedCommand;
}

void			setRandomNick(std::string nick, int index, Server &server) {
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
	std::cout << "Server: Nick " << nick << " is already taken, the new user will now be known as " << newNick << "." << std::endl << std::endl;
	response = nickResponse(newNick, nick);
	server.ssend(response, index);
	joinBot(server, index);
}

bool 			checkNickError(std::string &nick, int index, Server &server)
{
	if (nick.size() > 9) {
		server.sendErrorUser(nick.c_str(), NULL, NULL, ERR_ERRONEUSNICKNAME, index);
		server.setUserInvalidNick(index, nick);
		return (true);
	}
	for (size_t i = 0; i < server.getUsers().size(); i++)
	{
		if (server.getNick(i).compare(nick) == 0) {
			server.sendErrorUser(nick.c_str(), NULL, NULL, ERR_NICKNAMEINUSE, index);
			setRandomNick(nick, index, server);
			return (true);
		}
	}
	if (server.isUserModeOn(MODE_USER_R, index) == true) {
	    server.sendErrorUser(NULL, NULL, NULL, ERR_RESTRICTED, index);
	    return (true);
	}
	return (false);
}

void 			nickCmd(Server &server, int index, parsed *parsedCommand) {
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
