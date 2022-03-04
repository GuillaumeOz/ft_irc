#include "ft_irc.hpp"

std::string getAwayMessage(std::string &command) {
    std::string tmp;
	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":") + 1, command.end());
    return (tmp);
}

void    awayCmd(Server &server, int index, std::string &command) {
    std::string awayMessage = getAwayMessage(command);
    server.setUserAwayMessage(index, awayMessage);
}

//AWAY :I am now away