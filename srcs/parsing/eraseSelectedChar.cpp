#include "ft_irc.hpp"

std::string		eraseSelectedChar(std::string &string, char character) {
	while (string.find(character) != std::string::npos)
		string.erase(string.begin() + string.find(character));
	return (string);
}
