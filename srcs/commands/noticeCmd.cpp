#include "ft_irc.hpp"

std::string		getMessageNotice(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":"), command.end());
	return (tmp);
}

std::string		getUserNotice(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + 7, command.begin() + command.find(":") - 1);
	return (tmp);
}

bool    toChannelNotice(std::string &command) {
    if (command.find_first_of("#") == std::string::npos)
        return (false);
    return (true);
}

std::string		setChannelNameNotice(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of(":") - 1);
	return (tmp);
}

std::string		setResponseNotice(Server &server, int index, std::string &destination, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), "!ircserv");
	str.insert(str.length(), " NOTICE ");
	str.insert(str.length(), destination.c_str());
	str.insert(str.length(), " ");
	str.insert(str.length(), reason.c_str());
	str.insert(str.length(), "\n");
    return (str);
}

void        noticeCmd(Server &server, int index, std::string &command) {
    std::string message = getMessageNotice(command);
    std::string response;
    if (toChannelNotice(command) == true) {
        std::string channelName = setChannelNameNotice(command);
        response = setResponseNotice(server, index, channelName, message);
        server.sendToOtherUsersInChannel(channelName, response, index);
    }
    else {
        std::string user = getUserNotice(command);
        response = setResponseNotice(server, index, user, message);
        int user_index = server.findUserIndex(user);
        if (user_index == -1)
            server.sendErrorServerUser(user.c_str(), NULL, NULL, ERR_NOSUCHNICK, index);
        else
            server.ssend(response, user_index);
    }
}