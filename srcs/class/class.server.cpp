#include "ft_irc.hpp"

/* ------------------------ constructors/destructors ------------------------ */

Server::Server(int port): _config(port), _error(), _loop(true) {
	addSockToPfds(_config.sock);
	initCommands();
};

Server::Server(int port, Error error, std::string pass): _config(port), _error(error), _pass(pass), _loop(true) {
	addSockToPfds(_config.sock);
	initCommands();
};

Server::~Server() {};

/* ----------------------------- channel getters ---------------------------- */

std::vector<Channel *>				Server::getChannels() {
	return (channels);
};

std::vector<Channel *>::iterator 	Server::findChannel(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			return (it);
	}
	return (channels.end());
};

size_t 								Server::findChannelIndex(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			return (it - channels.begin());
	}
	return (std::string::npos);
};

std::string							Server::getChannelModes(int channel_index) {
	std::string channelModes("");
	int8_t channelMode = channels[channel_index]->getChannelMode();
	if (channelMode & MODE_CHANNEL_I) {
		channelModes += "i";
	}
	if (channelMode & MODE_CHANNEL_M) {
		channelModes += "m";
	}
	if (channelMode & MODE_CHANNEL_N) {
		channelModes += "n";
	}
	if (channelMode & MODE_CHANNEL_P) {
		channelModes += "p";
	}
	if (channelMode & MODE_CHANNEL_T) {
		channelModes += "t";
	}
	if (channelMode & MODE_CHANNEL_K) {
		channelModes += "k";
	}
	if (channelMode & MODE_CHANNEL_L) {
		channelModes += "l";
	}
	return (channelModes);
};

/* ------------------------------ user getters ------------------------------ */

std::vector<User *>		Server::getUsers() {
	return (_users);
};

int						Server::userCount() {
	return (_users.size());
};

std::string 			&Server::getUserAwayMessage(int index) {
	return (_users[index]->getAwayMessage());
};

std::string 			&Server::getUserInvalidNick(int index) {
	return (_users[index]->getInvalidNick());
};

int						Server::findUserIndex(std::string &nick) {
	for (size_t i = 0; i < _users.size(); i++) {
		if (nick.compare(_users[i]->getNick()) == 0) {
			return (i);
		}
	}
	return (-1);
};

int						Server::findClientSock(int socket) {
	for (size_t i = 0; i < _users.size(); i++) {
		if (_users[i]->getSocket() == socket)
			return (i);
	}
	return (-1);
};

std::string				&Server::getHost(int index) {
	return (_users[index]->getHost());
};

std::string				&Server::getNick(int index) {
	return (_users[index]->getNick());
};

std::string				&Server::getUsername(int index) {
	return (_users[index]->getUsername());
};

std::string				&Server::getRealname(int index) {
	return (_users[index]->getRealname());
};

/* ------------------------------ other getters ----------------------------- */

bool		Server::getLoop() {
	return (_loop);
};

int			Server::getPfdsSize() {
	return (_pfds.size());
};

/* --------------------------------- setters -------------------------------- */

void			Server::setHost(int index, std::string &string) {
	_users[index]->setHost(string);
};

void			Server::setNick(int index, std::string &string) {
	_users[index]->setNick(string);
};

void			Server::setUsername(int index, std::string &string) {
	_users[index]->setUsername(string);
};

void			Server::setRealname(int index, std::string &string) {
	_users[index]->setRealname(string);
};

void			Server::setUserAwayMessage(int index, std::string &awayMessage) {
	_users[index]->setAwayMessage(awayMessage);
};

void			Server::setUserInvalidNick(int index, std::string &invalidNick) {
	_users[index]->setInvalidNick(invalidNick);
};

void			Server::setLoop(bool newState) {
	_loop =  newState;
};

/* ---------------------------- checker functions --------------------------- */

bool 			Server::isValidPass(std::string &string) {
	if (_pass.compare(string) == 0)
		return (true);
	return (false);
};

bool 			Server::isRegistered(int index) {
	return (_users[index]->isRegistered());
};

bool			Server::isExistingChannel(std::string &name) {
	for (size_t i = 0; i < channels.size(); i++) {
		if (channels[i]->getChannelName() == name)
			return (true);
	}
	return (false);
};

bool			Server::isChannelEmpty(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			return ((*it)->isEmpty());
	}
	return (false);
};

bool 			Server::isUserInChannel(std::string &channelName, int index) {
	std::vector<std::string> uchannels = _users[index]->getUchannels();
	for (size_t i = 0; i < uchannels.size(); i++) {
		if (channelName == uchannels[i])
			return (true);
	}
	return (false);
};

/* ----------------------------- poll functions ----------------------------- */

void		Server::spoll() {
	poll(&_pfds[0], _pfds.size(), -1);
};

bool		Server::spollinCondition(int &index) {
	return (_pfds[index].revents == POLLIN);
};

bool		Server::spolloutCondition(int &index) {
	return (_pfds[index].revents == POLLOUT);
};

/* ------------------------------ socket setup ------------------------------ */

void		Server::sbind()  {
	bind(_config.sock, (const struct sockaddr *)&(_config.addr), sizeof(_config.addr));
	std::cout << std::endl << "Server: The server socket (socket #" << _config.sock << ") has bound to port #6667." << std::endl;
};

void		Server::slisten(int num) {
	listen(_config.sock, num);
	std::cout << std::endl << "Server: The server is listening to connections. It can host up to " << num << " users." << std::endl << std::endl;
};

void    	Server::saccept() {
	User *user = new User();

	user->uaccept(_config.sock);
	addUser(user);
	addSockToPfds(user->getSocket());
};

/* ---------------------------- sending/receiving --------------------------- */

void		Server::ssend(std::string &string, int index) {
	_users[index]->usend(string);
};

void		Server::ssend(std::string &string, User &user) {
	user.usend(string);
};

int			Server::srecv(std::string *string, int index) {
	return (_users[index]->urecv(string));
};

/* ------------------------ joining/adding functions ------------------------ */

void 		Server::sregister(int index) {
	_users[index]->uregister();
};

void		Server::addChannel(std::string &name, std::string &topic, int index) {
	Channel *new_channel = new Channel(name, topic, _users[index]);
	channels.push_back(new_channel);
};

void		Server::addUser(User *user) {
	_users.push_back(user);
};

void 		Server::addChannelToUser(int index, std::string channelName) {
	_users[index]->joinChannel(channelName);
};

void		Server::joinChannel(int index, std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			(*it)->addUser(_users[index]);
	}
};

void		Server::addSockToPfds(int socket) {
	_pfds.push_back(pollfd());
	_pfds.back().fd = socket;
	_pfds.back().events = POLLIN;
};

/* ------------------------------ error sending ----------------------------- */

void			Server::sendErrorServer(const char *arg1, const char *arg2, const char *arg3, errorType value) {
	_error.sendErrorServer(arg1, arg2, arg3, value);
};

void			Server::sendErrorUser(const char *arg1, const char *arg2, const char *arg3, errorType value, int index) {
	_error.sendErrorUser(arg1, arg2, arg3, value, _users[index]);
};

void			Server::sendErrorServerUser(const char *arg1, const char *arg2, const char *arg3, errorType value, int index) {
	_error.sendErrorServerUser(arg1, arg2, arg3, value, _users[index]);
};

/* ------------------------ leave/removing functions ------------------------ */

void			Server::removeChannel(int &index) {
	delete channels[index];
	channels.erase(channels.begin() + index);
};

void			Server::removeUser(int &socket) {
	int index = findClientSock(socket);
	if (index >= 0) {
		delete _users[index];
		_users.erase(_users.begin() + index);
	}
};

void			Server::removeSockFromPfds(int index) {
	if (index > 0)
		_pfds.erase(_pfds.begin() + index);
};

void			Server::delChannel(std::string &channelName) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName) {
			delete *it;
			channels.erase(it);
			break ;
		}
	}
};

void			Server::delUserFromChannel(std::string &channelName, int index) {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		if ((*it)->getChannelName() == channelName)
			(*it)->removeUser(_users[index]);
	}
};

void			Server::delChannelFromUser(std::string &channelName, int index) {
	_users[index]->leaveChannel(channelName);
};

/* --------------------------- printing functions --------------------------- */

void					Server::printPass() {
	std::cout << "The server password is: " << _pass << "." << std::endl;
};

void					Server::printChannels() {
	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
		std::cout << (*it)->getChannelName() << std::endl;
	}
};

/* ---------------------------- sending functions --------------------------- */

void			Server::sendToAllUsersInChannel(std::string &channelName, std::string &response) {
	std::vector<Channel *>::iterator	it = findChannel(channelName);

	if (it != channels.end()) {
		(*it)->sendToAllUsers(response);
	}
};

void			Server::sendToOtherUsersInChannel(std::string &channelName, std::string &response, int index) {
	std::vector<Channel *>::iterator	it = findChannel(channelName);

	if (it != channels.end()) {
		(*it)->sendToAllOtherUsers(response, _users[index]->getSocket());
	}
};

void			Server::sendToMyselfInChannel(std::string &channelName, std::string &response, int index) {
	std::vector<Channel *>::iterator	it = findChannel(channelName);

	if (it != channels.end()) {
		(*it)->sendToMyself(response, _users[index]->getSocket());
	}
};

/* -------------------------------- commands -------------------------------- */

void		Server::initCommands() {
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
};

void		Server::callCommand(Server &server, int &index, parsed *parsedCommand) {
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
};

/* ----------------------------- close functions ---------------------------- */

void		Server::closeUser(int pfds_index) {
	_users[pfds_index]->uclose();
	removeUser(_pfds[pfds_index + 1].fd);
	removeSockFromPfds(pfds_index + 1);
};

void		Server::closeServer() {
	close(_config.sock);
	std::cout << "The server has closed successfully." << std::endl;
};

/* ----------------------------- mode functions ----------------------------- */

bool		Server::isChannelModeOn(channelMode mode, int index) {
	return (channels[index]->isModeOn(mode));
};

bool		Server::isChannelUserModeOn(int index, std::string &channelName, channelUserMode mode) {
	return (_users[index]->isChannelUserModeOn(channelName, mode));
};

void		Server::assignUserMode(userMode mode, int index) {
	return (_users[index]->assignMode(mode));
};

void		Server::assignChannelMode(channelMode mode, int index) {
	return (channels[index]->assignMode(mode));
};

bool		Server::isUserModeOn(userMode mode, int index) {
	return (_users[index]->isModeOn(mode));
}
