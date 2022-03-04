#include "ft_irc.hpp"

std::string		goToUserCmd(std::string &command) {
	size_t i = command.find("USER");

	if (i != std::string::npos) {
		std::string newString;

		newString += command.c_str() + i;
		return (newString);
	}
	return (command);
}

void	userCmd(Server &server, int index, std::string &command) {
	std::string cmd;
	std::string tmp;
	char *ptr;
	int i = {0};

	cmd = goToUserCmd(command);
	if (strncmp(cmd.c_str(), "USER", 4 ) == 0) {
		ptr = strtok(const_cast<char *>(cmd.c_str()), " ");
		while (ptr != NULL && i < 4) {
			ptr = strtok(NULL, " :\r");
			tmp = ptr;
			if (i == 0)
				server.setUsername(index, tmp);
			if (i == 2)
				server.setHost(index, tmp);
			if (i == 3)
				server.setRealname(index, tmp);
			i++;
		}
		if (i < 3)
			server.sendErrorUser(command.c_str(), NULL, NULL, ERR_NEEDMOREPARAMS, index);
	}
}
