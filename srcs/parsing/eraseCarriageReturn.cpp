#include "ft_irc.hpp"

std::string		eraseCarriageReturn(std::string &string) {
	while (string.find(0xD) != std::string::npos)
		string.erase(string.begin() + string.find(0xD));
	return (string);
}
