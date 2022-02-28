#include "ft_irc.hpp"

std::string		getFirstWord(std::string string) {
	POUT("c'est las string")
	POUT(string)
	size_t i = string.find_first_of(" ");
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
	// std::string str(" JOIN #coco\n");
	// std::string channelName("#coco");
	// std::string channelTopic("soso");


			// if (strncmp(string.c_str(), "JOIN", 4) == 0) {
			// 	str.insert(0, ":");
			// 	str.insert(1, server.getNick(i - 1));
			// 	server.ssend(str, i - 1);
			// 	if (server.findChannel(channelName) == server.channel.end()) {
			// 		server.addChannel(channelName, channelTopic, (i -1));
			// 		POUT("NEW CHANNEL\n");
			// 	}
			// 	else {
			// 		server.joinChannel((i - 1), channelName);
			// 		POUT("NEW USER IN CHANNEL\n");
			// 	}
			// }
			// else if (strncmp(string.c_str(), "QUIT", 4) == 0) {
			// 		server.closeUser(i);
			// 		std::cout << "quit" << std::endl;
			// 		break;
			// }

int	main(int ac, char **av) {
	Error error;

	if (ac != 2)
		error.type = ARGUMENT;
	error.displayError();
	Server server(atoi(av[1]), error);
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
