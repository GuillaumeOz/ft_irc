#include "ft_irc.hpp"

Channel::Channel(std::string &name, std::string &topic, User *first) : _name(name), _topic(topic), _channelMode(0), _userLimit(0) {
	_users.push_back(first);
};

Channel::~Channel() {};

/* --------------------------------- getters -------------------------------- */

std::string   						&Channel::getChannelName() {
	return _name;
};

std::string   						&Channel::getChannelTopic() {
	return _topic;
};

std::vector<User *>   				Channel::getUsers() {
	return (_users);
};

std::vector<User *>::iterator 		Channel::getUsersEnd() {
	return (_users.end());
};

std::string							&Channel::getKeyword() {
	return (_keyword);
};

size_t								Channel::getNumberofUsers() {
	return (_users.size());
};

int8_t								Channel::getChannelMode() {
	return (_channelMode);
};

bool				Channel::isEmpty() {
	return (_users.empty());
};

/* --------------------------------- setters -------------------------------- */

void								Channel::setKeyword(std::string newKeyword) {
	_keyword = newKeyword;
};

void								Channel::setChannelTopic(std::string newTopic) {
	_topic = newTopic;
};

void        				        Channel::addUser(User *user) {
	_users.push_back(user);
};

/* ---------------------------- user manipulation --------------------------- */

std::vector<User *>::iterator 		Channel::findUser(std::string &name) {
	for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); it++) {
		if ((*it)->getNick() == name)
			return (it);
	}
	return (_users.end());
};

void                				Channel::removeUser(User *user) {
	for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); it++) {
		if ((*it)->getNick() == user->getNick()) {
			_users.erase(it);
			break ;
		}
	}
};

/* ---------------------------- sending functions --------------------------- */

void								Channel::sendToAllUsers(std::string &response) {
	std::vector<User *>::iterator it = _users.begin();

	while ( it != _users.end()) {
			(*it)->usend(response);
		it++;
	}
};

void								Channel::sendToAllOtherUsers(std::string &response, int socket) {
	std::vector<User *>::iterator it = _users.begin();
	while ( it != _users.end()) {
			if ((*it)->getSocket() != socket) 
				(*it)->usend(response);
		it++;
	}
};

void								Channel::sendToMyself(std::string &response, int socket) {
	std::vector<User *>::iterator it = _users.begin();
	while ( it != _users.end()) {
			if ((*it)->getSocket() == socket) 
				(*it)->usend(response);
		it++;
	}
};

/* ----------------------------- mode functions ----------------------------- */

void								Channel::assignMode(enum channelMode mode) {
	_channelMode |= mode;
};

void								Channel::removeMode(enum channelMode mode) {
	_channelMode ^= mode;
};

bool								Channel::isModeOn(enum channelMode mode) {
	if (_channelMode & mode)
		return (true);
	return (false);
};

void				Channel::setUserLimit(int limit) {
	_userLimit = limit;
}

size_t					Channel::getUserLimit() {
	return _userLimit;
}