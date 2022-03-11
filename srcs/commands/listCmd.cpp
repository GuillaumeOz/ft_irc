#include "ft_irc.hpp"

bool	isListlParams(std::string &string) {
	return (string.find_first_of(" ") != std::string::npos);
}

bool	isChannelParamUsed(std::string &string) {
	return (string.find(" channel" ) != std::string::npos);
}

bool	isChannelParam(std::string &string) {
	return (string.find("#" ) != std::string::npos);
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

void		addListedChannelsToChannelList(Server &server, bool channelsOnly, std::stringstream &channelList, std::string &string) {
	std::string tmp;
	char *splitted;
	char *str = const_cast<char *>(string.c_str());

	splitted = strtok(str, "# ");
	splitted = strtok(NULL, "#, \r");
	if (channelsOnly == true)
		splitted = strtok(NULL, "#, \r");
	while (splitted != NULL) {
		tmp = "#";
		tmp += splitted;
		if (server.isExistingChannel(tmp) == false)
			tmp += " :no such channel";
		else {
			std::vector<Channel *>::iterator it = server.findChannel(tmp); 
			if ((*it)->isModeOn(MODE_CHANNEL_P))
				goto NEXT_CHANNEL;
			if (channelsOnly == false) {
				addNbOfUserAndTopic(tmp, it);
			}
		}
		tmp += "\n";
		channelList << tmp;
	NEXT_CHANNEL:
		splitted = strtok(NULL, "#, \r\n");
	}
}

std::string getChannelsList(Server &server, std::string &string) {
	std::stringstream channelList;
	bool		channelsOnly = false;
	(void)string;

	channelList << std::setw(30) << std::left << "Channel" << std::right << std::setw(5) << "Users" << std::setw(20) << "Topics\n";
	for (int i = 0; i < 55; i++) { channelList << "-"; }
	channelList << "\n";
	if (isListlParams(string)) {
		if (isChannelParamUsed(string))
			channelsOnly = true;
		if (isChannelParam(string))
			addListedChannelsToChannelList(server, channelsOnly, channelList, string);
		else
			addChannelsToChannelList(server, channelsOnly, channelList);
	} else {
		if (isChannelParamUsed(string))
			channelsOnly = true;
		addChannelsToChannelList(server, channelsOnly, channelList);
	}
	channelList << "End of LIST\n\n";
	return (channelList.str());
}

void	listCmd(Server &server, int index, std::string &string) {
	std::string channelList;

	channelList = getChannelsList(server, string);
	POUT(channelList);
	server.ssend(channelList, index);
}
