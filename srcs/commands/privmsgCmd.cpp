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
	str.insert(str.length(), "!test");
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

void    privmsgCmd(Server &server, int index, std::string &command) {
    std::string message = getMessage(command);
    std::string response;
    if (toChannel(command) == true) {
        std::string channelName = setChannelName(command);
        response = setResponse(server, index, channelName, message);
        server.sendToAllUsersInChannel(channelName, response);
    }
    else {
        std::string user = getUser(command);
        response = setResponse(server, index, user, message);
        int user_index = server.findUserIndex(user);
        if (user_index == -1)
            server.sendError(user.c_str(), NULL, NULL, ERR_NOSUCHNICK, index);
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

//[test] is away (message)