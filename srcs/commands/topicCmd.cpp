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

std::string		getTopicChannelName(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of("#"), command.begin() + command.find_first_of(":") - 1);
	return (tmp);
}

std::string getTopic(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":"), command.end());
	return (tmp);
}

std::string		getTopicResponse(Server &server, int index, std::string &channelName, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), "!test");//test here ?
	str.insert(str.length(), " TOPIC ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), " ");
	str.insert(str.length(), reason.c_str());
	str.insert(str.length(), "\n");
    return (str);
}

// :WiZ!jto@tolsun.oulu.fi TOPIC #test :New topic
void	topicCmd(Server &server, int index, std::string &command) {
	std::string topic = getTopic(command);
	std::string channel = getTopicChannelName(command);
	std::string response = getTopicResponse(server, index, channel, topic);

	POUT("topic")
	POUT(topic)
	POUT("channel")
	POUT(channel)
	POUT("response")
	POUT(response)
}
