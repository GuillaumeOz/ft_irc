#include "ft_irc.hpp"

Config::Config(int port) {
	sock = socket(IP_TYPE, SOCKET_TYPE, 0);
	address.sin_addr.s_addr = inet_addr(HOST);
	address.sin_family = IP_TYPE;
	address.sin_port = htons(port);
};

Config::~Config() {};
