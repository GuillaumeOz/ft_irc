#include "ft_irc.hpp"

void	findChannelName(std::string &string, std::string &channel) {
	size_t i = string.find_first_of("#");
	size_t j = {0};

	while (j < string.length()) {
			if (string[j] ==  '\n')
				break;
			j++;
	}
	channel.assign(string.begin() + i, string.begin() + j - 1);
	return;
}

std::string		getResponse(Server &server, int index, std::string &channelName) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), " JOIN ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), "\n");
	return (str);
}

void    joinCmd(Server &server, int index, std::string &string) {
	std::string channelName;
	std::string response;
	std::string channelTopic("topic not set.");

	findChannelName(string, channelName);
	response = getResponse(server, index, channelName);
	if (server.isValidChannel(channelName) == true) {
		server.joinChannel(index, channelName);
		if (channelName.compare(" ") == 0)
			server.sendErrorServer(string.c_str(), NULL, NULL, ERR_NEEDMOREPARAMS);
	}
	else {
		if (channelName.find("#") == std::string::npos)
			server.sendErrorServer(channelName.c_str(), NULL, NULL, ERR_NOSUCHCHANNEL);
		server.addChannel(channelName, channelTopic, index);
		server.getUsers()[index]->assignChannelUserMode(channelName, MODE_CHANNEL_USER_O);
	}
	server.addChannelToUser(index, channelName);
	server.sendToAllUsersInChannel(channelName, response);
	return ;
}
