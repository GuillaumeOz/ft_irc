#include "ft_irc.hpp"

bool	isDisplayTopic(std::string &command) {
	return (command.find_first_of(":") == std::string::npos);
}

std::string getTopic(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":") , command.end() - 1);
	return (tmp);
}

std::string		getDisplayTopic(Server &server, int index, std::string &channelName, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), "!test");
	str.insert(str.length(), " PRIVMSG ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), " ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), " :");
	str.insert(str.length(), reason.c_str());
	str.insert(str.length(), "\n");
    return (str);
}

std::string		getTopicDisplayChannelName(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of("\n") - 1);
	return (tmp);
}

std::string		getTopicChannelName(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of(":") - 1);
	return (tmp);
}

std::string		getTopicResponse(Server &server, int index, std::string &channelName, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), "!test");
	str.insert(str.length(), " TOPIC ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), " ");
	str.insert(str.length(), reason.c_str());
	str.insert(str.length(), "\n");
    return (str);
}

void	topicChangeContent(Server &server, int index, std::string &command, std::string channel) {
	std::string response;
	std::vector<Channel *>::iterator	it;

	std::string topic = getTopic(command);
	size_t n = topic.find(0xD);
	topic.erase(topic.begin() + n);
	it = server.findChannel(channel);
	if (topic.compare("::") == 0) {
		std::string newTopic = "topic not set.";
		(*it)->setChannelTopic(newTopic);
		response = getTopicResponse(server, index, channel, (*it)->getChannelTopic());
		server.ssend(response, index);
	}
	else {
		(*it)->setChannelTopic(topic.c_str() + 2);
		response = getTopicResponse(server, index, channel, (*it)->getChannelTopic());
		server.ssend(response, index);
	}
}

void	topicCmd(Server &server, int index, std::string &command) {
	std::string channel;
	std::vector<Channel *>::iterator	it;

	if (server.getChannels().size() == 0) {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_NOSUCHCHANNEL, index);
		return ;
	}

	if (server.findChannel(channel) == server.getChannels().end()) {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_NOTONCHANNEL, index);
		return ;
	}

	if (isDisplayTopic(command) == true) {
		channel = getTopicDisplayChannelName(command);
		it = server.findChannel(channel);
		std::string displayTopic = getDisplayTopic(server, index, channel, (*it)->getChannelTopic());
		server.ssend(displayTopic, index);
		return ;
	}

	channel = getTopicChannelName(command);
	if (server.getUsers()[index]->isChannelUserModeOn(channel, MODE_CHANNEL_USER_O) == true) {
		topicChangeContent(server, index, command, channel);
	}
	else {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_CHANOPRIVSNEEDED, index);
		return ;
	}
}
