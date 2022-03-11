#include "ft_irc.hpp"

std::string getNick(std::string &command) {
    std::string tmp;
	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(" ") + 1, command.end());
    tmp.erase(tmp.end() - 1);
    return (tmp);
}

void	parseUserNick(std::string &string, int index, Server &server) {
    std::string tmp;

    size_t		i = {5};

    while (i < string.length()) {
        if (string[i] == 0xD || string[i] == '\n') {
            break;
        }
        i++;
    }
    tmp.insert(tmp.begin(), string.begin() + 5, string.begin() + i);
    server.setNick(index, tmp);
}

void	welcomeNewUser(std::string &string, int index, Server &server) {
	std::string response;

    (void)string;
    response += "001 ";
    response += server.getNick(index);
    response += " :Welcome to the Internet Relay Network ";
    response += server.getNick(index);
    response += "\n";
    server.ssend(response, index);
}

std::string getResponse(std::string newNick, std::string oldNick) {
	std::string str;
    str.insert(0, ":");
	str.insert(1, oldNick);
	str.insert(str.length(), "!ircserv");
	str.insert(str.length(), " NICK ");
	str.insert(str.length(), newNick.c_str());
	str.insert(str.length(), "\n");
	return (str);
}

bool    checkNickError(std::string &nick, int index, Server &server) {
    (void)index;
    if (nick.size() > 9) {
        server.sendErrorServer(nick.c_str(), NULL, NULL, ERR_ERRONEUSNICKNAME);
        return (true);
    }
    for (size_t i = 0; i < server.getUsers().size(); i++) {
        if (server.getNick(i).compare(nick) == 0) {
            server.sendErrorServer(nick.c_str(), NULL, NULL, ERR_NICKNAMEINUSE);
            return (true);
        }
    }
    // if (server.getUsers()[index]->isModeOn(MODE_USER_R) == true) {
    //     server.sendErrorServer(nick.c_str(), NULL, NULL, ERR_RESTRICTED, index);
    //     return (true);
    // }
    return (false);
}

void    nickCmd(Server &server, int index, std::string &command) {
    if (server.getNick(index) == "") {
        parseUserNick(command, index, server);
        welcomeNewUser(command, index, server);
        return ;
    }
    else {
        std::string oldNick = server.getNick(index);
        std::string newNick = getNick(command);
        size_t n = newNick.find(0xD);
        newNick.erase(newNick.begin() + n);
        if (checkNickError(newNick, index, server) == true)
            return ;
        std::string response = getResponse(newNick, oldNick);
        server.setNick(index, newNick);
        server.ssend(response, index);
        return ;
    }
}
