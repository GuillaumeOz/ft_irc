#include "ft_irc.hpp"

/* ------------------------ Constructors/Destructors ------------------------ */

parsed::parsed(): command(), args(), channels(), twoPointsArgs(), rawCommand() {};

parsed::~parsed() {
	clear();
};

/* --------------------------------- setters -------------------------------- */

void	parsed::addCommand(const char *token) {
	command = token;
};

void	parsed::addArgs(const char *token) {
	std::string *arg = new std::string();

	*arg = token;
	addArgChannel(arg);
	addArgTwoPoints(arg);
	args.push_back(arg);
};

void	parsed::addArgChannel(std::string *arg) {
	 if ((*arg)[0] == '#')
		channels.push_back(arg);
};

void	parsed::addArgTwoPoints(std::string *arg) {
	 if ((*arg)[0] == ':')
		twoPointsArgs.push_back(arg);
};

void	parsed::addRawString(std::string &string) {
	rawCommand = string;
};

/* ---------------------------- delete/deallocate --------------------------- */

void	parsed::clear() {
	for(size_t i = 0; i < args.size(); i++) {
		delete args[i];
	}
};
