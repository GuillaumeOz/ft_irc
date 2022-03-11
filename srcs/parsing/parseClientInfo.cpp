#include "ft_irc.hpp"

std::string	skipCap(std::string &string) {
	std::string tmp;
	size_t i = string.find("CAP LS");

	if (i != std::string::npos) {
		while (string[i] != '\n')
			i++;
		if (i != string.length() -1 ) {
			tmp.insert(tmp.begin(), string.begin() + i + 1, string.end());
			return (tmp);
		}
	}
	return (string);
}

void 	parseClientInformations(std::string &string, int index, Server &server) {
	std::string tmp = skipCap(string);
	std::string passMsg("Your are not register to the server. Please use the /PASS command followed by the server password");

	if (strncmp(string.c_str(), "PASS", 4) == 0)
		passCmd(server, index, string);
	if (server.isRegistered(index)) {
		if (tmp.compare(string) != 0 && strncmp(tmp.c_str(), "NICK", 4) == 0)
			nickCmd(server, index, tmp);
		userCmd(server, index, string);
	}
	else
		server.ssend(passMsg, index);
}
