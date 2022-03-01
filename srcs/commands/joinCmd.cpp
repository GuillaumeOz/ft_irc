#include "ft_irc.hpp"

void	findChannelName(std::string &string, std::string &channel) {
	size_t i = string.find_first_of("#");
	size_t j = {0};

	while (j < string.length()) {
			if (string[j] ==  '\n')
				break;
			j++;
	}
	// if (j > 50)
	// 	server.sendError()
	channel.assign(string.begin() + i, string.begin() + j - 1);
	return;
}

std::string		getResponse(Server &server, int index, std::string &channelName) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length() - 1, " JOIN ");
	str.insert(str.length() - 1, channelName.c_str());
	str.insert(str.length() - 1, "\n");
	return (str);
}

void    joinCmd(Server &server, int index, std::string &string) {
	std::string channelName;
	std::string response;
	std::string channelTopic("topic not set");

	findChannelName(string, channelName);
	response = getResponse(server, index, channelName);
	if (server.isValidChannel(channelName) == true) {
		server.joinChannel(index, channelName);
		if (channelName.compare(" ") == 0)
			server.sendError(string.c_str(), NULL, NULL, ERR_NEEDMOREPARAMS, index);
	}
	else {
		server.addChannel(channelName, channelTopic, index);
		if (channelName.find("#") == std::string::npos)
			server.sendError(channelName.c_str(), NULL, NULL, ERR_NOSUCHCHANNEL, index);
	}
	server.sendToAllUsersInChannel(channelName, response);
	return ;
}
