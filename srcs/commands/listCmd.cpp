#include "ft_irc.hpp"

bool	isListlParams(parsed *parsedCommand) {
	return (parsedCommand->args.size() != 0);
}

bool	isChannelParamUsed(parsed *parsedCommand) {
	for (size_t i = 0; i < parsedCommand->args.size(); i++) {
		if (parsedCommand->args[i]->compare("channel") == 0)
			return (true);
	}
	return (false);
}

bool	isChannelParam(parsed *parsedCommand) {
	return (parsedCommand->channels.size() != 0);
}

void		addNbOfUserAndTopic(std::string &string, std::vector<Channel *>::iterator it) {
	std::stringstream tmp;

	tmp << std::setw(30) << std::right << (*it)->getNumberofUsers() << std::setw(20) << (*it)->getChannelTopic();
	string += tmp.str();
}

void		addChannelsToChannelList(Server &server, bool channelsOnly, std::stringstream &channelList) {
	std::string tmp;

	for (std::vector<Channel *>::iterator it = server.channels.begin(); it != server.channels.end(); it++) {
		if ((*it)->isModeOn(MODE_CHANNEL_P))
				goto NEXT_CHANNEL;
		tmp = (*it)->getChannelName();
		if (channelsOnly == false) {
				addNbOfUserAndTopic(tmp, it);
		}
		tmp += "\n";
		channelList << tmp;
		NEXT_CHANNEL:
			;
	}
}

void		addListedChannelsToChannelList(Server &server, bool channelsOnly, std::stringstream &channelList, parsed *parsedCommand) {
	std::string tmp;

	for (size_t i = 0; i < parsedCommand->channels.size(); i++) {
		tmp += *parsedCommand->channels[i];
		if (server.isExistingChannel(*parsedCommand->channels[i]) == false)
			tmp += " :no such channel";
		else {
			std::vector<Channel *>::iterator it = server.findChannel(tmp); 
			if ((*it)->isModeOn(MODE_CHANNEL_P))
				i++;
			if (channelsOnly == false) {
				addNbOfUserAndTopic(tmp, it);
			}
		}
		tmp += "\n";
		channelList << tmp;
		tmp.clear();
	}
}

std::string getChannelsList(Server &server, parsed *parsedCommand) {
	std::stringstream channelList;
	bool		channelsOnly = false;

	channelList << std::setw(30) << std::left << "Channel" << std::right << std::setw(5) << "Users" << std::setw(20) << "Topics\n";
	for (int i = 0; i < 55; i++) { channelList << "-"; }
	channelList << "\n";
	if (isListlParams(parsedCommand)) {
		if (isChannelParamUsed(parsedCommand))
			channelsOnly = true;
		if (isChannelParam(parsedCommand))
			addListedChannelsToChannelList(server, channelsOnly, channelList, parsedCommand);
		else
			addChannelsToChannelList(server, channelsOnly, channelList);
	} else {
		if (isChannelParamUsed(parsedCommand))
			channelsOnly = true;
		addChannelsToChannelList(server, channelsOnly, channelList);
	}
	channelList << "End of LIST\n\n";
	return (channelList.str());
}

void	listCmd(Server &server, int index, parsed *parsedCommand) {
	std::string channelList;

	channelList = getChannelsList(server, parsedCommand);
	POUT(channelList);
	server.ssend(channelList, index);
}
