#include "ft_irc.hpp"

size_t	getTokenPos(std::string &string, std::string token) {
	return (string.find(token.c_str()));
}

bool	isToken(std::string &string, std::string token) {
	size_t i = getTokenPos(string, token.c_str());
	return (i != std::string::npos);
}
