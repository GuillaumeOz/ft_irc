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

void	parsed::clearArgs() {
	for(size_t i = 0; i < args.size(); i++) {
		delete args[i];
	}
};

void	parsed::clearChannels() {
	for(size_t i = 0; i < channels.size(); i++) {
		delete channels[i];
	}
}

void	parsed::clearTwoPointsArgs() {
	for(size_t i = 0; i < twoPointsArgs.size(); i++) {
		delete twoPointsArgs[i];
	}
}

void	parsed::clear() {
	clearArgs();
	command.clear();
	rawCommand.clear();
};
