#include "ft_irc.hpp"

Server::Server(int port): _config(port), _error() {
	addSockToPfds(_config.sock);
	initCommands();
};

Server::Server(int port, Error error): _config(port), _error(error) {
	addSockToPfds(_config.sock);
	initCommands();
};

Server::~Server() {};

void	Server::sbind()  {
	bind(_config.sock, (const struct sockaddr *)&(_config.addr), sizeof(_config.addr));
	std::cout << "[Bind] : " << _config.sock << "." << std::endl;
}

void	Server::initCommands() {
	_commands["JOIN"] = &joinCmd;
	_commands["PART"] = &partCmd;
	_commands["PRIVMSG"] = &privmsgCmd;
	_commands["LIST"] = &listCmd;
	_commands["QUIT"] = &quitCmd;
	_commands["TOPIC"] = &topicCmd;
	_commands["AWAY"] = &awayCmd;
	_commands["NICK"] = &nickCmd;
}

void	Server::callCommand(std::string &command, Server &server, int &index, std::string &string) {
	if (_commands.find(command) != _commands.end())
		_commands.find(command)->second(server, index, string);
}

void	Server::slisten(int num) {
	listen(_config.sock, num);
	std::cout << "[Listening] : You can add until " << num << " users." << std::endl;
}

void	Server::closeUser(int pfds_index) {
	_users[pfds_index]->uclose();
	removeSockFromPfds(pfds_index);
	removeUser(_pfds[pfds_index].fd);
};

void	Server::closeServer() {
	close(_config.sock);
	std::cout << "Server closed." << std::endl;
};

void	Server::ssend(std::string &string, int index) {
	_users[index]->usend(string);
};

void	Server::ssend(std::string &string, User &user) {
	user.usend(string);
};

void	Server::sendErrorServer(const char *arg1, const char *arg2, const char *arg3, errorType value) {
	_error.sendErrorServer(arg1, arg2, arg3, value);
}

void	Server::sendErrorUser(const char *arg1, const char *arg2, const char *arg3, errorType value, int index) {
	_error.sendErrorUser(arg1, arg2, arg3, value, _users[index]);
}

void	Server::sendErrorServerUser(const char *arg1, const char *arg2, const char *arg3, errorType value, int index) {
	_error.sendErrorServerUser(arg1, arg2, arg3, value, _users[index]);
}

int		Server::srecv(std::string *string, int index) {
	return (_users[index]->urecv(string));
};

void    Server::saccept() {
	User *user = new User();

	user->uaccept(_config.sock);
	addUser(user);
	addSockToPfds(user->getSocket());
};

//JOIN
//Check if the channel doesnt exit
void	Server::addChannel(std::string &name, std::string &topic, int index) {
	Channel *new_channel = new Channel(name, topic, _users[index]);
	//add first user operator status
	channels.push_back(new_channel);
};

void Server::addChannelToUser(int index, std::string channelName) {
	_users[index]->joinChannel(channelName);
}


void	Server::joinChannel(int index, std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)//add double join channel protection
			(*it)->addUser(_users[index]);
	}
};

//PART
void	Server::removeChannel(int &index) {
	delete channels[index];
	channels.erase(channels.begin() + index);
};

bool	Server::isValidChannel(std::string &name) {
	for (size_t i = 0; i < channels.size(); i++) {
		if (channels[i]->getChannelName() == name)
			return (true);
	}
	return (false);
}

void	Server::delUserFromChannel(std::string &channelName, int index) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			(*it)->removeUser(_users[index]);
	}
};

void	Server::delChannel(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName) {
			channels.erase(it);
			break ;
		}
	}
};

void	Server::delChannelFromUser(std::string &channelName, int index) {
	_users[index]->leaveChannel(channelName);
};

void	Server::spoll() {
	poll(&_pfds[0], _pfds.size(), -1);
};

bool	Server::spollinCondition(int &index) {
	return (_pfds[index].revents == POLLIN);
};

bool	Server::spolloutCondition(int &index) {
	return (_pfds[index].revents == POLLOUT);
};
void	Server::addUser(User *user) {
	_users.push_back(user);
};

void	Server::removeUser(int &socket) {
	int index = findClientSock(socket);
	if (index > 0) {
		delete _users[index];
		_users.erase(_users.begin() + index);
	}
}

void	Server::addSockToPfds(int socket) {
	_pfds.push_back(pollfd());
	_pfds.back().fd = socket;
	_pfds.back().events = POLLIN;
};

void	Server::removeSockFromPfds(int index) {
	if (index > 0)
		_pfds.erase(_pfds.begin() + index);
};

int		Server::findClientSock(int socket) {
	for (size_t i = 0; i < _users.size(); i++) {
		if (_users[i]->getSocket() == socket)
			return (i);
	}
	return (-1);
};

void	Server::setNick(int index, std::string &string) {
	_users[index]->setNick(string);
}

std::string		&Server::getNick(int index) {
	return (_users[index]->getNick());
};

int		Server::getPfdsSize() {
	return (_pfds.size());
}

std::vector<User *>	Server::getUsers() {
	return (_users);
}

std::vector<Channel *>	Server::getChannels() {
	return (channels);
}

bool	Server::isChannelEmpty(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			return ((*it)->isEmpty());
	}
	return (false);
}

std::vector<Channel *>::iterator Server::findChannel(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			return (it);
	}
	return (channels.end());
};

void		Server::sendToAllUsersInChannel(std::string &channelName, std::string &response) {
	std::vector<Channel *>::iterator	it = findChannel(channelName);

	if (it != channels.end()) {
		(*it)->sendToAllUsers(response);
	}
};

void		Server::sendToOtherUsersInChannel(std::string &channelName, std::string &response, int index) {
	std::vector<Channel *>::iterator	it = findChannel(channelName);

	if (it != channels.end()) {
		(*it)->sendToAllOtherUsers(response, _users[index]->getSocket());
	}
};

void		Server::printChannels() {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		std::cout << (*it)->getChannelName() << std::endl;
	}
};

bool		Server::isUserModeOn(userMode mode, int index) {
	return (_users[index]->isModeOn(mode));
}

void		Server::assignUserMode(userMode mode, int index) {
	return (_users[index]->assignMode(mode));
}

bool		Server::ischannelModeOn(channelMode mode, int index) {
	return (channels[index]->isModeOn(mode));
}

void		Server::assignchannelMode(channelMode mode, int index) {
	return (channels[index]->assignMode(mode));
}

int			Server::findUserIndex(std::string &nick) {
	for (size_t i = 0; i < _users.size(); i++) {
		if (nick.compare(_users[i]->getNick()) == 0) {
			return (i);
		}
	}
	return (-1);
}

void		Server::setUserAwayMessage(int index, std::string &awayMessage) {
	_users[index]->setAwayMessage(awayMessage);
}

bool		Server::isUserAway(int index) {
	return (_users[index]->isAway());
}

std::string &Server::getUserAwayMessage(int index) {
	return (_users[index]->getAwayMessage());
}