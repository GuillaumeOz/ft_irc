#include "ft_irc.hpp"

User::User(): _csize(sizeof(_addr)) {};

User::~User() {
	uclose();
};

void    User::uaccept(int &sock) {
	_sock = accept(sock, (struct sockaddr *)&(_addr), &(_csize));
	std::cout << "[Accepted] : client " << _sock <<  std::endl;
};

void	User::usend(std::string &string) {
	send(_sock, string.c_str(), string.length(), 0);
};

void	User::urecv(std::string *string) {
	size_t	nbBytes;
	char	tmpBuff[100];

		nbBytes = recv(_sock, tmpBuff, 100, 0);
		std::cout << nbBytes << std::endl;
		*string += tmpBuff;
}

void    User::uclose() {
	close(_sock);
}

void	User::setSocket(int &socket) {
	_sock = socket;
}
