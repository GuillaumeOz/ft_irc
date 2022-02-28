#include "ft_irc.hpp"

User::User(): _csize(sizeof(_addr)), _username(), _nick() {};

User::User(std::string &username, std::string &nick): _csize(sizeof(_addr)), _username(username), _nick(nick) {};

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

int	User::urecv(std::string *string) {
	size_t	nbBytes;
	char	tmpBuff[1000];

	do {
		memset(tmpBuff, '\0', sizeof(tmpBuff));
		nbBytes = recv(_sock, tmpBuff, sizeof(tmpBuff), 0);
		*string += tmpBuff;
	} while (strchr(tmpBuff, '\0') == NULL);
	return (nbBytes);
};

void    User::uclose() {
	close(_sock);
};

void	User::setSocket(int &socket) {
	_sock = socket;
};

int		User::getSocket() {
	return (_sock);
};

void	User::setNick(std::string &string) {
	_nick = string;
}

std::string	&User::getNick() {
	return _nick;
}

std::string	&User::getUsername() {
	return _username;
}

void	User::leaveChannel(std::string &channelName) {
	for (size_t i = 0; i < _uchannels.size(); i++) {
		if (_uchannels[i] == channelName)
			_uchannels.erase(_uchannels.begin() + i);
	}
}

void	User::joinChannel(std::string &channelName) {
	for (size_t i = 0; i < _uchannels.size(); i++) {
		if (_uchannels[i] == channelName)
			return ;
	}
	_uchannels.push_back(channelName);
}
