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

bool	isNewUser(std::string &string) {
	if (strncmp(string.c_str(), "NICK", 4) == 0) {
		return (true);
	}
	return (false);
}

void	parseUserNick(std::string &string, int index, bool &newUser, Server &server) {
		std::string tmp;

	if (newUser) {
		size_t		i = {5};

		while (i < string.length()) {
			if (string[i] ==  '\n')
				break;
			i++;
		}
		tmp.insert(tmp.begin(), string.begin() + 5, string.begin() + i -1);
		POUT(tmp);
		server.setNick(index, tmp);
	}
}

void	welcomeNewUser(std::string &string, int index, Server &server) {
	std::string response;

	POUT(server.getNick(index))	
	if (strncmp(string.c_str(), "CAP LS", 6) == 0) {
		response += "001 ";
		response += server.getNick(index);
		response += " :Welcome to the Internet Relay Network ";
		response += server.getNick(index);
		response += "\n";
		server.ssend(response, index);
	}
}

void 	parseClientInformations(std::string &string, int index, Server &server) {
	std::string tmp = skipCap(string);
	bool newUser = {false};

	POUT(tmp);
	newUser = isNewUser(tmp);
	parseUserNick(tmp, index, newUser, server);
	welcomeNewUser(string, index, server);
	//parseUserName
}
