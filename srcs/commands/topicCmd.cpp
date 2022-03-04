#include "ft_irc.hpp"

bool	isTopicInLobby(std::string &string) {
	if (string.find("#") == std::string::npos)
		return (true);
	return (false);
}

std::string parseChannelName(std::string &command) {
	std::string ret;
	char *str = const_cast<char *>(command.c_str() + command.find("#"));
	char *tmp;

	tmp = strtok(str, " ");
	ret = tmp;
	ret = eraseCarriageReturn(ret);
	ret = eraseLineBreak(ret);
	return (ret);
}

bool	isDisplayTopic(std::string &command) {
	if (command.find_first_of(":") == std::string::npos)
		return (true);
	return (false);
}

std::string	parseTopicContent(std::string &command) {

	std::string ret;
	char *str = const_cast<char *>(command.c_str() + command.find(":"));
	char *tmp;

	tmp = strtok(str, ":");
	ret = tmp;
	ret = eraseCarriageReturn(ret);
	ret = eraseLineBreak(ret);
	return (ret);
}

void	topicChangeContent(Server &server, int index, std::string &command, std::string channel) {
	std::string							response;
	std::vector<Channel *>::iterator	it;
	std::string							cmd = "TOPIC";

	std::string topic = parseTopicContent(command);
	it = server.findChannel(channel);
	(*it)->setChannelTopic(topic.c_str());
	response = getCmdString(server, index, channel, (*it)->getChannelTopic(), cmd);
	server.ssend(response, index);
}

void	topicCmd(Server &server, int index, std::string &command) {

	if (isTopicInLobby(command) == true) {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_NOSUCHCHANNEL, index);
		return ;
	}

	std::string		channelName;
	channelName = parseChannelName(command);

	if (server.findChannel(channelName) == server.channels.end()) {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_NOTONCHANNEL, index);
		return ;
	}

	std::vector<Channel *>::iterator	it;
	if (isDisplayTopic(command) == true) {
		it = server.findChannel(channelName);
		std::string cmd = "PRIVMSG";
		std::string displayTopic = getCmdString(server, index, channelName, (*it)->getChannelTopic(), cmd);
		server.ssend(displayTopic, index);
		return ;
	}

	if (server.getUsers()[index]->isChannelUserModeOn(channelName, MODE_CHANNEL_USER_O) == true) {
		topicChangeContent(server, index, command, channelName);
	}
	else {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_CHANOPRIVSNEEDED, index);
		return ;
	}
}
