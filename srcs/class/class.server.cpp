#include "ft_irc.hpp"

Server::Server(int port): _config(port), _error() {};

Server::Server(int port, Error error): _config(port), _error(error) {};

Server::~Server() {};

void	Server::sbind()  {
	bind(_config.sock, (const struct sockaddr *)&(_config.addr), sizeof(_config.addr));
	std::cout << "[Bind] : " << _config.sock << "." << std::endl;
}

void	Server::slisten(int num) {
	listen(_config.sock, num);
	std::cout << "[Listening] : You can add until " << num << " users." << std::endl;
}

void	Server::closeUser() {
	_user.uclose();
};

void	Server::closeServer() {
	close(_config.sock);
	std::cout << "Server closed." << std::endl;
};

void	Server::ssend(std::string &string) {
	_user.usend(string);
};

void	Server::srecv(std::string *string) {
	_user.urecv(string);
};

void    Server::saccept() {
	_user.uaccept(_config.sock);
};
