#include "ft_irc.hpp"


// RPL_NOTOPIC
// "<channel> :No topic is set"
// RPL_TOPIC
// "<channel> :<topic>"

// TOPIC #test :another topic      ; Command to set the topic on #test
//                                    to "another topic".

//    TOPIC #test :                   ; Command to clear the topic on
//                                    #test.

//    TOPIC #test                     ; Command to check the topic for
//                                    #test.

bool	isDisplayTopic(std::string &command) {
	return (command.find_first_of(":") == std::string::npos);
}

std::string getTopic(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":") , command.end());
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

// :WiZ!jto@tolsun.oulu.fi TOPIC #test :New topic

//INPUT = /topic    			CMD = TOPIC #test
//INPUT = /topic :				CMD = TOPIC #test ::
//INPUT = /topic <lorem> 		CMD = TOPIC #test :lorem

void	topicCmd(Server &server, int index, std::string &command) {
	POUT("ENTER INTO TOPIC CMD GESTION")
	std::string response;
	std::string channel;
	std::vector<Channel *>::iterator	it;

	if (isDisplayTopic(command) == true) {
		channel = getTopicDisplayChannelName(command);
		it = server.findChannel(channel);
		std::string displayTopic = getDisplayTopic(server, index, channel, (*it)->getChannelTopic());
		server.ssend(displayTopic, index);
		return ;
	}
	//add user mode protection
	std::string topic = getTopic(command);
	POUT("NEW TOPIC")
	POUT(topic)
	channel = getTopicChannelName(command);
	it = server.findChannel(channel);
	if (topic.compare("::") == 0) {
		std::string newTopic = "topic not set.";
		(*it)->setChannelTopic(newTopic);
		response = getTopicResponse(server, index, channel, (*it)->getChannelTopic());
		server.ssend(response, index);
	}
	else {
		POUT("COUCOUCOUCOCUC")
		(*it)->setChannelTopic(topic.c_str() + 1);
		response = getTopicResponse(server, index, channel, (*it)->getChannelTopic());
		server.ssend(response, index);
	}
}
