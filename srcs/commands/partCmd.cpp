#include "ft_irc.hpp"

std::string		getChannelName(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of(":") - 1);
	return (tmp);
}

std::string		getReason(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":"), command.end());
	return (tmp);
}

std::string		getResponse(Server &server, int index, std::string &channelName, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length() - 1, "!test");
	str.insert(str.length() - 1, " PART ");
	str.insert(str.length() - 1, channelName.c_str());
	str.insert(str.length() - 1, " ");
	str.insert(str.length() - 1, reason.c_str());
	str.insert(str.length() - 1, "\n");
    return (str);
}

void	partCmd(Server &server, int index, std::string &command) {
	std::string channelName = getChannelName(command);
	std::string reason = getReason(command);
	std::string	response = getResponse(server, index, channelName, reason);
    if (server.isValidChannel(channelName)) {
		std::cout << channelName << std::endl;
        server.delUserFromChannel(channelName, index);
		server.delChannelFromUser(channelName, index);
		std::cout << "Our Response :" << response << std::endl;
		server.ssend(response, index);
        if (server.isChannelEmpty(channelName) == true)
            server.delChannel(channelName);
    }
}
