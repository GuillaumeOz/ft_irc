#include "ft_irc.hpp"

std::string		setChannelName(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of(":") - 1);
	return (tmp);
}

std::string		getUser(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + 9, command.begin() + command.find_first_of(":") - 1);
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
	str.insert(str.length() - 1, "!test");
	str.insert(str.length() - 1, " PRIVMSG ");
	str.insert(str.length() - 1, destination.c_str());
	str.insert(str.length() - 1, " ");
	str.insert(str.length() - 1, reason.c_str());
	str.insert(str.length() - 1, "\n");
    return (str);
}

bool    toChannel(std::string &command) {
    if (command.find_first_of("#") == std::string::npos)
        return (false);
    return (true);
}

void    privmsgCmd(Server &server, int index, std::string &command) {
    std::string message = getMessage(command);
    std::string response;
    if (toChannel(command) == true) {
        std::string channelName = setChannelName(command);
        response = setResponse(server, index, channelName, message);
        POUT("Sending to a channel:")
        POUT(response)
        server.sendToAllUsersInChannel(channelName, response);
    }
    else {
        std::string user = getUser(command);
        response = setResponse(server, index, user, message);
        POUT("Sending to a user:")
        POUT(response)        
        server.ssend(response, index);
    }
}
