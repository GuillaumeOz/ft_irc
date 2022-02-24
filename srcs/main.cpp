#include "ft_irc.hpp"

void	usersActionsLoop(Server &server) {
	std::string string;server.getPfdsSize();
	std::string str(":user42 JOIN #coco\n");
	int res = {0};

	for (int i = 1; i < server.getPfdsSize(); i++) {
		if (server.spollinCondition(i)) {
			res = server.srecv(&string, (i - 1));
			std::cout << string << std::endl;
		}
		if (res > 0) {
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
