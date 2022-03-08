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

bool	isBotOn(int ac, char **av) {
	if (ac == 3) {
		if (strcmp(av[2], "bot") == 0)
			return (true);
	}
	return (false);
}

void	runBot(void) {
	system("xterm -e bash make bot");
	system("xterm -e bash -c ./bot/bin/bot_client");
	std::cout << "toto" << std::endl;
}

int	main(int ac, char **av) {
	Error error;
	bool botState = isBotOn(ac, av);

	if ((ac != 2 && ac != 3) || ( ac == 3 && !botState))
		error.type = ARGUMENT;
	error.displayError();
	Server server(atoi(av[1]), error);
	server.sbind();
	server.slisten(10);
	int i = {0};
	if (botState)
		runBot();
	while (true) {
		server.spoll();
		if (server.spollinCondition(i)) {
			int index = server.saccept();
			std::string str("JOIN #bot\r");
			joinCmd(server, index, str);
		}
		usersActionsLoop(server);
	}
	server.closeServer();
	return (0);
}
