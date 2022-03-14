#include "ft_irc.hpp"

void	timeCmd(Server &server, int index, parsed *parsedCommand) {
	(void)parsedCommand;
	time_t rawtime;
	std::string timeResponse;
	time(&rawtime);
	std::string formatTime = ctime(&rawtime);
	timeResponse += "ircserv :";
	timeResponse += formatTime;
	server.ssend(timeResponse, index);
}
