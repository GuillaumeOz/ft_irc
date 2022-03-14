#include "ft_irc.hpp"

std::string		setChannelName(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of(":") - 1);
	return (tmp);
}

std::string		getUser(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + 8, command.begin() + command.find(":") - 1);
	return (tmp);
}

std::string		getMessage(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":"), command.end());
	return (tmp);
}

std::string		setResponse(Server &server, int index, std::string &destination, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), "!ircserv");
	str.insert(str.length(), " PRIVMSG ");
	str.insert(str.length(), destination.c_str());
	str.insert(str.length(), " ");
	str.insert(str.length(), reason.c_str());
	str.insert(str.length(), "\n");
    return (str);
}

bool    toChannel(std::string &command) {
    if (command.find_first_of("#") == std::string::npos)
        return (false);
    return (true);
}

std::string     getAwayResponse(std::string user, std::string message) {
    std::string tmp;
    tmp += "[" + user + "] is away (";
    message.insert(message.length() - 1, ")\n");
    tmp.insert(tmp.length(), message.c_str());
    return (tmp);
}

bool        isVersion(std::string &command) {
    std::string test;
    test += "PRIVMSG ircserv :";
    test += static_cast<char> (129);
    test += "VERSION";
    test += static_cast<char> (129);
    test += "\r\n";
    if (command.compare(test) == -128)
        return (true);
    return (false);
}

void        versionCmd(Server &server, int index) {
    std::string version = "Version: 108.114.99\n";
    server.ssend(version, index);
}

void    privmsgCmd(Server &server, int index, std::string &command) {
    std::string message = getMessage(command);
    std::string response;
    if (isVersion(command) == true) {
        versionCmd(server, index);
        return ;
    }
    if (toChannel(command) == true) {
        std::string channelName = setChannelName(command);
        int count = std::count(message.begin(), message.end(), '\n');
        if (count > 1) {
            size_t pos = message.find("\n");
            while (pos != std::string::npos) {
                std::string tmp;
                tmp.insert(tmp.begin(), message.begin(), message.begin() + pos);
                response = setResponse(server, index, channelName, tmp);
                server.sendToOtherUsersInChannel(channelName, response, index);
                message.erase(0, message.find("\n") + 1);
                response.clear();
                pos = message.find("\n");
            }
        }
        else {
            response = setResponse(server, index, channelName, message);
            server.sendToOtherUsersInChannel(channelName, response, index);
        }
    }
    else {
        std::string user = getUser(command);
        response = setResponse(server, index, user, message);
        int user_index = server.findUserIndex(user);
        if (user_index == -1)
            server.sendErrorServerUser(user.c_str(), NULL, NULL, ERR_NOSUCHNICK, index);
        else {
            if (server.isUserAway(user_index) == true) {
                std::string     awayMessage = server.getUserAwayMessage(user_index);
                std::string     awayResponse = getAwayResponse(user, awayMessage);
                server.ssend(awayResponse, index);
            }
            server.ssend(response, user_index);
        }
    }
}
