#include "ft_irc.hpp"

bool	isNewUser(std::string &string) {
	if (strncmp(string.c_str(), "CAP LS", 6) == 0) {
		return (true);
	}
	return (false);
}

void	parseUserNick(std::string &string, int index, bool &newUser, Server &server) {
	std::string tmp;
	size_t		i = {13};

	if (newUser) {
		while (i < string.length()) {
			if (string[i] ==  '\n')
				break;
			i++;
		}
		tmp.assign(string.begin() + 13, string.begin() + i);
		server.setNick(index, tmp);
		POUT("\nnick name:");
		POUT(server.getNick(index));
	}
}

void 	parseClientInformations(std::string &string, int index, Server &server) {
	bool newUser = {false};
	newUser = isNewUser(string);
	parseUserNick(string, index, newUser, server);
}

void	usersActionsLoop(Server &server) {
	std::string string;
	std::string str(" JOIN #coco\n");
	std::string channelName("#coco");
	std::string channelTopic("soso");
	int res = {0};

	for (int i = 1; i < server.getPfdsSize(); i++) {
		if (server.spollinCondition(i)) {
			res = server.srecv(&string, (i - 1));
			std::cout << string << std::endl;
		}
		if (res > 0) {
			parseClientInformations(string, (i - 1), server);
			if (strncmp(string.c_str(), "JOIN", 4) == 0) {
				str.insert(0, ":");
				str.insert(1, server.getNick(i - 1));
				server.ssend(str, i - 1);
				if (server.findChannel(channelName) == server.channel.end()) {
					server.addChannel(channelName, channelTopic, (i -1));
					POUT("NEW CHANNEL\n");
				}
				else {
					server.joinChannel((i - 1), channelName);
					POUT("NEW USER IN CHANNEL\n");
				}
			}
			else if (strncmp(string.c_str(), "QUIT", 4) == 0) {
					server.closeUser(i);
					std::cout << "quit" << std::endl;
					break;
			}
			string.clear();
		}
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
