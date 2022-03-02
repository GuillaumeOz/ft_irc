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

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":") - 1, command.end());
	return (tmp);
}

std::string		getTopicChannelName(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of("\n") - 1);
	return (tmp);
}

std::string		getDisplayTopicResponse(Server &server, int index, std::string &channelName) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), "!test");
	str.insert(str.length(), " TOPIC ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), "\n");
    return (str);
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
//INPUT = /topic				CMD = TOPIC #test ::
//INPUT = /topic <lorem> 		CMD = TOPIC #test :lorem

void	topicCmd(Server &server, int index, std::string &command) {
	std::string channel = getTopicChannelName(command);
	std::vector<Channel *>::iterator	it = server.findChannel(channel);
	// return (string.find_first_of(" ") != std::string::npos);
	// POUT(command)
	// POUT(channel)
	// POUT("TEST1")
	// POUT((*it)->getChannelTopic())

	if (isDisplayTopic(command) == true) {
		std::string displayResponse = getDisplayTopicResponse(server, index, (*it)->getChannelTopic());
		POUT("DISPLAYRESPNSE")
		POUT(displayResponse)
		server.ssend(displayResponse, index);
	}
	// server.getUsers()[index]->usend((*it)->getChannelTopic());
	// if (topic.size() == std::string::npos) {

	// 	POUT("TEST3")
	// 	return ;
	// }
	// std::string topic = getTopic(command);
	// else if (topic.compare("::")) {

	// }
	// else {

	// }

	// POUT("command")
	// POUT(command)
	// POUT("topic")
	// POUT(topic)
	// POUT("channel")
	// POUT(channel)
	// POUT("response")
	// POUT(response)

	(void)server;
	(void)index;
}
