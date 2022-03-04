#include "ft_irc.hpp"

User::User(): _csize(sizeof(_addr)), _username(), _nick(),_realname(),  _awaymessage("") {};

User::User(std::string &username, std::string &nick): _csize(sizeof(_addr)), _nick(nick), _username(username), _realname() {};

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

std::vector<std::string>	User::getUchannels() {

	return (_uchannels);
}

void	User::setHost(std::string &string) {
	_host = string;
}

void	User::setNick(std::string &string) {
	_nick = string;
}

void	User::setUsername(std::string &string) {
	_username = string;
}

void	User::setRealname(std::string &string) {
	_realname = string;
}

std::string	&User::getHost() {
	return _host;
}

std::string	&User::getNick() {
	return _nick;
}

std::string	&User::getUsername() {
	return _username;
}

std::string	&User::getRealname() {
	return _realname;
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

void	User::assignMode(userMode mode) {
	_userMode |= mode;
}

bool	User::isModeOn(userMode mode) {
	if (_userMode & mode)
		return (true);
	return (false);
}

void	User::assignChannelUserMode(std::string &channel, channelUserMode mode) {
	_channelUserMode[channel] |= mode;
}

bool	User::isChannelUserModeOn(std::string &channel, channelUserMode mode) {
	if (_channelUserMode[channel] & mode)
		return (true);
	return (false);
}

std::string &User::getAwayMessage() {
	return _awaymessage;
}

void		User::setAwayMessage(std::string &awayMessage) {
	_awaymessage = awayMessage;
}

bool		User::isAway() {
	return (_awaymessage != "");
}
