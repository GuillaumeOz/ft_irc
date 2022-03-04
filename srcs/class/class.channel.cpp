#include "ft_irc.hpp"

Channel::Channel(std::string &name, std::string &topic, User *first) : _name(name), _topic(topic), _channelMode(0) {
	assignMode(MODE_CHANNEL_N);
	assignMode(MODE_CHANNEL_T);
	_users.push_back(first);
};

Channel::~Channel() {};

std::string   &Channel::getChannelName() {
	return _name;
};

std::string   &Channel::getChannelTopic() {
	return _topic;
};

void			Channel::setChannelTopic(std::string newTopic) {
	_topic = newTopic;
};

size_t			Channel::getNumberofUsers() {
	return (_users.size());
}

std::vector<User *>::iterator Channel::findUser(std::string &name) {
	for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); it++) {
		if ((*it)->getNick() == name)
			return (it);
	}
	return (_users.end());
};

void                Channel::addUser(User *user) {
	_users.push_back(user);
};

void                Channel::removeUser(User *user) {
	for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); it++) {
		if ((*it)->getNick() == user->getNick()) {
			_users.erase(it);
			break ;
		}
	}
};

void				Channel::sendToAllUsers(std::string &response) {
	std::vector<User *>::iterator it = _users.begin();

	while ( it != _users.end()) {
			(*it)->usend(response);
		it++;
	}
};

void				Channel::sendToAllOtherUsers(std::string &response, int socket) {
	std::vector<User *>::iterator it = _users.begin();
	while ( it != _users.end()) {
			if ((*it)->getSocket() != socket) 
				(*it)->usend(response);
		it++;
	}
}

bool				Channel::isEmpty() {
	return (_users.empty());
};

void				Channel::assignMode(enum channelMode mode) {
	_channelMode |= mode;
}

bool				Channel::isModeOn(enum channelMode mode) {
	if (_channelMode & mode)
		return (true);
	return (false);
};
