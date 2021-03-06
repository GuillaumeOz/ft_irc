#include "ft_irc.hpp"

/* ------------------------ constructors/destructors ------------------------ */

User::User(): _registerState(false), _csize(sizeof(_addr)), _nick(), _username(), _realname(), _awaymessage(""), _userMode(NO_USER_MODE) {};

User::User(std::string &username, std::string &nick):  _registerState(false), _csize(sizeof(_addr)), _nick(nick), _username(username), _realname() , _userMode(NO_USER_MODE) {};

User::~User() {};

/* --------------------------------- getters -------------------------------- */

int							User::getSocket() {
	return (_sock);
};

std::vector<std::string>	User::getUchannels() {

	return (_uchannels);
};

int8_t						User::getUserMode() {
	return (_userMode);
};

std::string					&User::getHost() {
	return _host;
};

std::string					&User::getNick() {
	return _nick;
};

std::string					&User::getUsername() {
	return _username;
};

std::string					&User::getRealname() {
	return _realname;
};

std::string 				&User::getInvalidNick() {
	return _invalidNick;
};

std::string 				&User::getAwayMessage() {
	return _awaymessage;
};


bool 						User::isRegistered() {
	return (_registerState);
};

/* --------------------------------- setters -------------------------------- */

void			User::setAwayMessage(std::string &awayMessage) {
	_awaymessage = awayMessage;
};

void			User::setInvalidNick(std::string &invalidNick) {
	_invalidNick = invalidNick;
};

void			User::setSocket(int &socket) {
	_sock = socket;
};

void			User::setHost(std::string &string) {
	_host = string;
};

void			User::setNick(std::string &string) {
	_nick = string;
};

void			User::setUsername(std::string &string) {
	_username = string;
};

void			User::setRealname(std::string &string) {
	_realname = string;
};

void 			User::uregister() {
	_registerState = true;
};

/* --------------------------- socket manipulation -------------------------- */

void    	User::uaccept(int &sock) {
	_sock = accept(sock, (struct sockaddr *)&(_addr), &(_csize));
	std::cout << "Server: New client accepted on socket #" << _sock << "." << std::endl << std::endl;
};

void		User::usend(std::string &string) {
	send(_sock, string.c_str(), string.length(), 0);
};

int			User::urecv(std::string *string) {
	size_t	nbBytes;
	char	tmpBuff[30000];

	do {
		memset(tmpBuff, '\0', sizeof(tmpBuff));
		nbBytes = recv(_sock, tmpBuff, sizeof(tmpBuff), 0);
		*string += tmpBuff;
	} while (strchr(tmpBuff, '\n') == NULL);
	return (nbBytes);
};

void    	User::uclose() {
	close(_sock);
};

/* --------------------------- leave/join channel --------------------------- */

void			User::leaveChannel(std::string &channelName) {
	for (size_t i = 0; i < _uchannels.size(); i++) {
		if (_uchannels[i] == channelName)
			_uchannels.erase(_uchannels.begin() + i);
	}
};

void			User::joinChannel(std::string &channelName) {
	for (size_t i = 0; i < _uchannels.size(); i++) {
		if (_uchannels[i] == channelName)
			return ;
	}
	_uchannels.push_back(channelName);
};

/* ---------------------------------- modes --------------------------------- */

void			User::assignMode(userMode mode) {
	_userMode |= mode;
};

void			User::assignChannelUserMode(std::string &channel, channelUserMode mode) {
	_channelUserMode[channel] |= mode;
};

void			User::removeMode(userMode mode) {
	_userMode ^= mode;
};

void			User::removeChannelUserMode(std::string &channel, channelUserMode mode) {
	_channelUserMode[channel] ^= mode;
};

bool			User::isModeOn(userMode mode) {
	if (_userMode & mode)
		return (true);
	return (false);
};

bool			User::isChannelUserModeOn(std::string &channel, channelUserMode mode) {
	if (_channelUserMode[channel] & mode)
		return (true);
	return (false);
};
