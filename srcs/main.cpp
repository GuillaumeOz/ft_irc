#include "ft_irc.hpp"

bool	isNewUser(std::string &string) {
	if (strncmp(string.c_str(), "CAP", 3) == 0) {
		return (true);
	}
	return (false);
}

bool	parseUserNick(std::string &string, int index, bool &newUser, Server &server) {
	std::string tmp;

	if (newUser) {
		for (size_t i = 5; i != string.length(); i++) {
			if (string.compare(i, 1, " "))
				tmp.assign(string.begin() + 5, string.begin() + i);
		}
		server.setNick(index, tmp);
		POUT(server.getNick(index));
	}
	newUser = false;
	return (newUser);
}

bool 	parseClientInformations(std::string &string, int index, bool &newUser, Server &server) {
	newUser = parseUserNick(string, index, newUser, server);
	newUser = isNewUser(string);
	return newUser;
}

void	usersActionsLoop(Server &server) {
	std::string string;
	std::string str(":user42 JOIN #coco\n");
	bool newUser = {false};
	int res = {0};

	for (int i = 1; i < server.getPfdsSize(); i++) {
		if (server.spollinCondition(i)) {
			res = server.srecv(&string, (i - 1));
			std::cout << string << std::endl;
		}
		if (res > 0) {
			parseClientInformations(string, (i - 1), newUser, server);
			if (strncmp(string.c_str(), "JOIN", 4) == 0) {
				std::cout << "joining\n";
				server.ssend(str, i - 1);
			}
			else if (strncmp(string.c_str(), "QUIT", 4) == 0) {
				server.closeUser(i);
				std::cout << "quit" << std::endl;
				break;
			}
		}
		string.clear();
	}
}

int	main(int ac, char **av) {
	Error error;

	if (ac != 2)
		error.type = ARGUMENT;
	error.displayError();
	Server server(atoi(av[1]), error);
	server.sbind();
	server.slisten(4);
	int i = {0};
	while (true){
		server.spoll();
		if (server.spollinCondition(i))
			server.saccept();
		usersActionsLoop(server);
	}
	server.closeServer();
	return (0);
}
