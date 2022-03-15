#include "ft_irc.hpp"

void	versionCmd(Server &server, int index) {
	std::string version = "Version: 108.114.99\n";
	server.ssend(version, index);
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

void    privmsgCmd(Server &server, int index, parsed *parsedCommand) {
    std::string message = parsedCommand->getFullTwoPointsArgs();
    std::string response;
    if (isVersion(parsedCommand->rawCommand) == true) {
        versionCmd(server, index);
        return ;
    }
    if (parsedCommand->channels.size() > 0) {
        std::string channelName = (*parsedCommand->channels[0]);
        int count = std::count(message.begin(), message.end(), '\n');
        if (count > 1) {
            size_t pos = message.find("\n");
            while (pos != std::string::npos) {
                std::string tmp;
                tmp.insert(tmp.begin(), message.begin(), message.begin() + pos);
				response = privmsgResponse(server, index, channelName, tmp);
                server.sendToOtherUsersInChannel(channelName, response, index);
                message.erase(0, message.find("\n") + 1);
                response.clear();
                pos = message.find("\n");
            }
        }
        else {
            response = privmsgResponse(server, index, channelName, message);
            server.sendToOtherUsersInChannel(channelName, response, index);
        }
    }
    else {
        std::string user = (*parsedCommand->args[0]);
        response = privmsgResponse(server, index, user, message);
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
