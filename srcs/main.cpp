#include "ft_irc.hpp"

int	main(int ac, char **av) {
	Error error;

	(void)av;
	if (ac != 3)
		error.type = ARGUMENT;
	error.displayError();
	return (0);
}
