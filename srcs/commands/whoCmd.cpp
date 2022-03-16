#include "ft_irc.hpp"

bool					isWhoParams(parsed *parsedCommand) {
	if (parsedCommand->args.size() != 0)
		return (true);
	return (false);
}

bool					isOperParam(parsed *parsedCommand) {
	if (parsedCommand->args.size() > 1) {
		if (parsedCommand->args[1]->compare("o") == 0)
			return (true);
	}
	return (false);
}

findSubStringState		whichSubString(parsed *parsedCommand) {
	if (isWhoParams(parsedCommand)) {
		if ((*parsedCommand->args[0])[0] == '*')
			return (START);
		if ((*parsedCommand->args[0])[parsedCommand->args[0]->length() - 1] == '*')
			return (END);
	}
	return (NONE);
}

bool					isValidSubStr(parsed *parsedCommand, Server &server, int index, findSubStringState subStrFlag) {
	std::string nick = server.getNick(index);

	if (isWhoParams(parsedCommand)) {
		std::string subString = *parsedCommand->args[0];
		if (subStrFlag == START && strncmp(subString.c_str() + 1, nick.c_str(), subString.length() - 2) == 0)
			return (true);
		if (subStrFlag == END && strncmp(subString.c_str(), (nick.c_str() + (nick.length() - subString.length() + 1)), subString.length() - 2) == 0)
			return (true);
	}
	if (subStrFlag == NONE)
		return (true);
	return (false);
}

void					addUsersToList(Server &server, std::stringstream &userList, parsed *parsedCommand) {
	std::stringstream		tmp;
	findSubStringState		subStrFlag = whichSubString(parsedCommand);
	int						userCount =  server.userCount();

	for (int i = 0; i < userCount; i++) {
		if (!server.isUserModeOn(MODE_USER_I, i) && isValidSubStr(parsedCommand, server, i, subStrFlag)) {
			tmp << std::setw(15) << std::left << server.getHost(i) ;
			tmp << std::right << std::setw(15) << server.getUsername(i);
			tmp << std::right << std::setw(15) << server.getRealname(i);
			tmp << std::setw(15) << server.getNick(i);
			tmp << "\n";
		}
		tmp.clear();
	}
	userList << tmp.str();
}

std::string 			getUsersList(Server &server, parsed *parsedCommand) {
	std::stringstream userList;

	userList << std::setw(15) << std::left << "host" << std::right << std::setw(15) << "username" << std::right << std::setw(15) << "realename" << std::setw(15) << "nickname\n";
	for (int i = 0; i < 60 ; i++) { userList << "-"; }
		userList << "\n";
	addUsersToList(server, userList, parsedCommand);
	userList << "End of LIST\n\n";
	return (userList.str());
}

void					whoCmd(Server &server, int index, parsed *parsedCommand) {
	std::string userList;

	userList = getUsersList(server, parsedCommand);
	server.ssend(userList, index);
}
