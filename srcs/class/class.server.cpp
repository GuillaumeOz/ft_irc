#include "ft_irc.hpp"

Server::Server(int port): _config(port), _error(), _loop(true) {
	addSockToPfds(_config.sock);
	initCommands();
};

Server::Server(int port, Error error, std::string pass): _config(port), _error(error), _pass(pass), _loop(true) {
	addSockToPfds(_config.sock);
	initCommands();
};

Server::~Server() {};

void	Server::sbind()  {
	bind(_config.sock, (const struct sockaddr *)&(_config.addr), sizeof(_config.addr));
	std::cout << "[Bind] : " << _config.sock << "." << std::endl;
}

void	Server::printPass() {
	POUT(_pass);
}

bool Server::isValidPass(std::string &string) {
	if (_pass.compare(string) == 0)
		return (true);
	return (false);
}

bool 	Server::isRegistered(int index) {
	return (_users[index]->isRegistered());
}

void 	Server::sregister(int index) {
	_users[index]->uregister();
}

void	Server::initCommands() {
	_commands["PASS"] = &passCmd;
	_commands["JOIN"] = &joinCmd;
	_commands["PART"] = &partCmd;
	_commands["PRIVMSG"] = &privmsgCmd;
	_commands["LIST"] = &listCmd;
	_commands["QUIT"] = &quitCmd;
	_commands["USER"] = &userCmd;
	_commands["TOPIC"] = &topicCmd;
	_commands["AWAY"] = &awayCmd;
	_commands["NICK"] = &nickCmd;
	_commands["TIME"] = &timeCmd;
	_commands["MODE"] = &modeCmd;
	_commands["NOTICE"] = &noticeCmd;
	_commands["WHO"] = &whoCmd;
}

void	Server::callCommand(Server &server, int &index, parsed *parsedCommand) {
	std::string notRegistered = "Your are not registered to our server please try to connect with the right password\n";
	if (!server.isRegistered(index) && parsedCommand->command.compare("PASS") != 0) {
		server.ssend(notRegistered, index);
		server.closeUser(index);
		server.setLoop(false);
		return ;
	}
	if ((server.isRegistered(index) && _commands.find(parsedCommand->command) != _commands.end()) ||
		parsedCommand->command.compare("PASS") == 0)
			_commands.find(parsedCommand->command)->second(server, index, parsedCommand);
}

void	Server::slisten(int num) {
	listen(_config.sock, num);
	std::cout << "[Listening] : You can add until " << num << " users." << std::endl;
}

void	Server::closeUser(int pfds_index) {
	POUT(_users[pfds_index]->getNick())
	_users[pfds_index]->uclose();
	removeUser(_pfds[pfds_index + 1].fd);
	removeSockFromPfds(pfds_index + 1);
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

bool	Server::isExistingChannel(std::string &name) {
	for (size_t i = 0; i < channels.size(); i++) {
		if (channels[i]->getChannelName() == name)
			return (true);
	}
	return (false);
};

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
	if (index >= 0) {
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


void	Server::setHost(int index, std::string &string) {
	_users[index]->setHost(string);
};

void	Server::setNick(int index, std::string &string) {
	_users[index]->setNick(string);
};

void	Server::setUsername(int index, std::string &string) {
	_users[index]->setUsername(string);
};

void	Server::setRealname(int index, std::string &string) {
	_users[index]->setRealname(string);
};

std::string		&Server::getHost(int index) {
	return (_users[index]->getHost());
};

std::string		&Server::getNick(int index) {
	return (_users[index]->getNick());
};

std::string		&Server::getUsername(int index) {
	return (_users[index]->getUsername());
};

std::string		&Server::getRealname(int index) {
	return (_users[index]->getRealname());
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

size_t Server::findChannelIndex(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			return (it - channels.begin());
	}
	return (std::string::npos);
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

void		Server::sendToMyselfInChannel(std::string &channelName, std::string &response, int index) {
	std::vector<Channel *>::iterator	it = findChannel(channelName);

	if (it != channels.end()) {
		(*it)->sendToMyself(response, _users[index]->getSocket());
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

std::string &Server::getUserInvalidNick(int index) {
	return (_users[index]->getInvalidNick());
}

void		Server::setUserInvalidNick(int index, std::string &invalidNick) {
	_users[index]->setInvalidNick(invalidNick);
}

bool 		Server::userIsinChannel(std::string &channelName, int index) {
	std::vector<std::string> uchannels = _users[index]->getUchannels();
	for (size_t i = 0; i < uchannels.size(); i++) {
		if (channelName == uchannels[i])
			return (true);
	}
	return (false);
}

void	Server::setLoop(bool newState) {
	_loop =  newState;
}

bool	Server::getLoop() {
	return (_loop);
}

int		Server::userCount() {
	return (_users.size());
}
