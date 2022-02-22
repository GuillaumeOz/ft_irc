#include "ft_irc.hpp"

Config::Config(int port) {
	sock = socket(IP_TYPE, SOCKET_TYPE, 0);
	addr.sin_addr.s_addr = inet_addr(HOST);
	addr.sin_family = IP_TYPE;
	addr.sin_port = htons(port);
};

Config::~Config() {};
