#include "ft_irc.hpp"

void	topicChangeContent(Server &server, int index, std::string topic, std::string channel) {
	std::string							response;
	std::vector<Channel *>::iterator	it;
	std::string							cmd = "TOPIC";

	it = server.findChannel(channel);
	(*it)->setChannelTopic(topic.c_str());
	response = getCmdString(server, index, channel, (*it)->getChannelTopic(), cmd);
	server.ssend(response, index);
}

void	topicCmd(Server &server, int index, parsed *parsedCommand) {

	if (parsedCommand->channels.size() == 0) {
		server.sendErrorUser("IRC ", NULL, NULL, ERR_NOSUCHCHANNEL, index);
		return ;
	}

	std::string		channelName;
	channelName = *parsedCommand->channels[0];

	if (server.findChannel(channelName) == server.channels.end()) {
		server.sendErrorUser("IRC ", NULL, NULL, ERR_NOTONCHANNEL, index);
		return ;
	}

	std::vector<Channel *>::iterator	it;
	if (parsedCommand->twoPointsArgs.size() == 0) {
		it = server.findChannel(channelName);
		std::string displayTopic = getCmdString(server, index, channelName, (*it)->getChannelTopic(), "PRIVMSG");
		server.ssend(displayTopic, index);
		return ;
	}

	if (server.getUsers()[index]->isChannelUserModeOn(channelName, MODE_CHANNEL_USER_O) == true) {
		topicChangeContent(server, index, parsedCommand->getFullTwoPointsArgs(), channelName);
	}
	else {
		server.sendErrorUser("IRC ", NULL, NULL, ERR_CHANOPRIVSNEEDED, index);
		return ;
	}
}
