#include "ft_irc.hpp"

std::string getNick(std::string &command) {
    std::string tmp;
	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(" ") + 1, command.end());
    return (tmp);
}

void    nickCmd(Server &server, int index, std::string &command) {
    std::string newNick = getNick(command);

    server.setNick(index, newNick);
    std::string respones = 
}