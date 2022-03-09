#include "ft_irc.hpp"

std::string		getFirstWord(std::string string) {
	size_t i = string.find_first_of(" \n\r");
	if (i != std::string::npos) {
		std::string tmp;

		tmp.insert(tmp.begin(), string.begin(), string.begin() + i);
		return (tmp);
	}
	return (string);
}

void	handleActions(std::string &string, int index, Server &server) {
	std::string token;

	token = getFirstWord(string);
	server.callCommand(token, server, index, string);
}

void	usersActionsLoop(Server &server) {
	std::string string;
	int res = {0};

	for (int i = 1; i < server.getPfdsSize(); i++) {
		if (server.spollinCondition(i)) {
			res = server.srecv(&string, (i - 1));
			std::cout << string << std::endl;
		}
		if (res > 0) {
			parseClientInformations(string, (i - 1), server);
			handleActions(string, (i - 1), server);
			string.clear();
		}
	}
}

int	main(int ac, char **av) {
	Error error;

	if (ac != 3)
		error.type = ARGUMENT;
	error.displayError();
	Server server(atoi(av[1]), error, std::string(av[2]));
	server.sbind();
	server.slisten(10);
	int i = {0};
	while (true) {
		server.spoll();
		if (server.spollinCondition(i))
			server.saccept();
		usersActionsLoop(server);
	}
	server.closeServer();
	return (0);
}
