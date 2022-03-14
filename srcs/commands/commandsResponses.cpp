#include "ft_irc.hpp"

/* ----------------------------- Away functions ----------------------------- */

std::string awayResponse(void) {
	std::string response;
	response += "You have been marked as being away\r\n";
	return (response);
}

/* ----------------------------- Nick functions ----------------------------- */

std::string newUserResponse(std::string &nick) {
	std::string response;

	response += "001 " + nick + " :Welcome to the Internet Relay Network " + nick + "\n";
	return (response);
}

std::string nickResponse(std::string &newNick, std::string &oldNick)
{
	std::string response;

	response += ":" + oldNick + "!ircserv NICK " + newNick + "\n";
	POUT(response)
	return (response);
}

/* ----------------------------- Join functions ----------------------------- */

std::string	joinResponse(Server &server, int index, std::string &channelName) {
	std::string response;

	response += ":" + server.getNick(index) + " JOIN " + channelName + "\n";
	return (response);
}

/* ----------------------------- Privmsg functions ----------------------------- */


std::string privmsgResponse(Server &server, int index, std::string &destination, std::string &message) {
	std::string response;

	response += ":" + server.getNick(index) + "!ircserv PRIVMSG " + destination + " :" + message + "\n";
	return (response);
}
