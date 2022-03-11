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
	str.insert(str.length(), " PART ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), " ");
	str.insert(str.length(), reason.c_str());
	str.insert(str.length(), "\n");
    return (str);
}

void	partCmd(Server &server, int index, std::string &command) {
	std::string channelName = getChannelName(command);
	std::string reason = getReason(command);
	std::string	response = getResponse(server, index, channelName, reason);
    if (server.isExistingChannel(channelName)) {
        server.delUserFromChannel(channelName, index);
		server.delChannelFromUser(channelName, index);
		server.ssend(response, index);
        if (server.isChannelEmpty(channelName) == true)
            server.delChannel(channelName);
    } else
		server.sendErrorServer(channelName.c_str(), NULL, NULL, ERR_NOSUCHCHANNEL);
}
