#include "ft_irc.hpp"

std::string		getCmdString(Server &server, int index, std::string channelName, std::string reason, std::string cmd) {
	std::string ret;

	ret += ":";
	ret += server.getNick(index).c_str();
	ret += "!ircserv";
	ret += " ";
	ret += cmd;
	ret += " ";
	ret += channelName.c_str();
	ret += " :";
	ret += reason.c_str();
	ret += "\n";
    return (ret);
}
