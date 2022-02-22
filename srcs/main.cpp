#include "ft_irc.hpp"

int	main(int ac, char **av) {
	Error error;
	std::string string;

	if (ac != 2)
		error.type = ARGUMENT;
	error.displayError();
	Server server(atoi(av[1]), error);
	server.sbind();
	server.slisten(4);
	server.saccept();
	server.srecv(&string);
	std::cout << string << std::endl;
	server.closeUser();
	server.closeServer();
	return (0);
}
