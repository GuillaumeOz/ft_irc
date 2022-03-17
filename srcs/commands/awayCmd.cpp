#include "ft_irc.hpp"

std::string		getClientAwayMessage(parsed *parsedCommand) {
	std::string 	awayMessage;

	for (size_t i = 0; i < parsedCommand->args.size(); i++) {
		if (i == 0)
			awayMessage += parsedCommand->args[i]->c_str() + 1;
		else {
			awayMessage += " ";
			awayMessage += parsedCommand->args[i]->c_str();
		}
	}
	return (awayMessage);
}

void			awayCmd(Server &server, int index, parsed *parsedCommand) {
	std::string awayMessage;
	std::string response;

	if (parsedCommand->twoPointsArgs.size() == 0)
		awayMessage = "I am busy\n";
	else
		awayMessage = getClientAwayMessage(parsedCommand);
	server.setUserAwayMessage(index, awayMessage);
	userMode mode = MODE_USER_A;
	server.assignUserMode(mode, index);
	response = awayResponse();
	server.ssend(response, index);
}
