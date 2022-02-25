#include "ft_irc.hpp"

// "JOIN #toto"
// ":user JOIN #toto\n"
//channel name starts with # up to 50 characters

void	findChannelName(std::string &string, std::string &channel) {
	size_t i = string.find_first_of("#");
	size_t j = {0};

	while (j < string.length()) {
			if (string[j] ==  '\n')
				break;
			j++;
	}
	if (j > 50)
		PERR("ERROR: channel name too long.");//protect here
	channel.assign(string.begin() + i, string.begin() + j);
	return;
}

void    joinCmd(Server &server, User *user, std::string &string) {
	std::string str;
	std::string channelName;
	std::string channelTopic("topic not set");
	(void)server;


	findChannelName(string, channelName);
	str.insert(0, ":");
	str.insert(1, user->getNick().c_str());
	str.insert(str.length() - 1, " JOIN ");
	str.insert(str.length() - 1, channelName.c_str());
	str.insert(str.length() - 1, "\n");
	std::cout << str << std::endl;
	user->usend(str);
	if (server.findChannel((channelName)) == server.channel.end()) {
		server.addChannel((channelName), channelTopic, user);
	} else
		(*(server.findChannel(channelName)))->addUser(user);
    return ;
}
