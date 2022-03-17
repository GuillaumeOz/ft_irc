#include "ft_irc.hpp"

void	handleActions(std::vector<parsed*> parsedCommands, int index, Server &server) {
	for (size_t i = 0; i < parsedCommands.size() && (server.getLoop() == true); i++) {
		server.callCommand(server, index, parsedCommands[i]);
	}
	server.setLoop(true);
}

void	usersActionsLoop(Server &server) {
	std::string				string;
	std::vector<parsed*>	parsedCommands;
	int res = {0};

	for (int i = 1; i < server.getPfdsSize(); i++)
	{
		if (server.spollinCondition(i))
		{
			res = server.srecv(&string, (i - 1));
		}
		if (res > 0) {
			parseCommands(parsedCommands, string);
			// printParsedCommands(parsedCommands);
			handleActions(parsedCommands, (i - 1), server);
			string.clear();
		}
		for (size_t i = 0; i < parsedCommands.size(); i++) {
			delete parsedCommands[i];
		}
		parsedCommands.clear();
	}
}

int 	main(int ac, char **av)
{
	Error error;

	if (ac != 3)
		error.type = ARGUMENT;
	error.displayError();
	Server server(atoi(av[1]), error, std::string(av[2]));
	server.sbind();
	server.slisten(100);
	int i = {0};
	while (true)
	{
		server.spoll();
		if (server.spollinCondition(i))
			server.saccept();
		usersActionsLoop(server);
	}
	server.closeServer();
	return (0);
}
