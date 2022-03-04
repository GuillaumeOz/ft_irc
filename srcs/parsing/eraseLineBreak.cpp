#include "ft_irc.hpp"

std::string	eraseLineBreak(std::string &string) {
	while (string.find("\n") != std::string::npos)
		string.erase(string.begin() + string.find("\n"));
	return (string);
}
