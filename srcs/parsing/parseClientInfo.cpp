#include "ft_irc.hpp"

std::string	skipCap(std::string &string) {
	std::string tmp;

	if (strncmp(string.c_str(), "CAP", 3) == 0) {
		size_t i = string.find_first_of("\n");
		if (i != string.length() -1 ) {
			tmp.insert(tmp.begin(), string.begin() + i + 1, string.end());
			return (tmp);
		}
	}
	return (string);
}

void 	parseClientInformations(std::string &string, int index, Server &server) {
	std::string tmp = skipCap(string);

	if (tmp.compare(string) != 0 && strncmp(tmp.c_str(), "NICK", 4) == 0) {
		nickCmd(server, index, tmp);
		std::string tmp = "JOIN #bot\r\n";
		joinCmd(server, index, tmp);
	}
	userCmd(server, index, string);
}
