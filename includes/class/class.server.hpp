#ifndef CLASS_SERVER_HPP
# define CLASS_SERVER_HPP

class User;

class Server {

	private:

	Config																			_config;
	Error																			_error;
	std::vector<User *>																_users;
	std::vector<struct pollfd>														_pfds;
	std::string																		_password;
	std::map<std::string, void (*)(Server &, int , std::string &)> 					_commands;

	public:
	std::vector<Channel *>															channels;

	Server(int port);
	Server(int port, Error error);
	~Server();

	//Commands
	void initCommands();
	void callCommand(std::string &, Server &, int &, std::string &);

	//Sockets
	void sbind();
	void slisten(int);
	void saccept();
	void ssend(std::string &, int);
	void ssend(std::string &, User &);
	int  srecv(std::string *, int);
	void spoll();
	bool spollinCondition(int &);
	bool spolloutCondition(int &);

	//Error
	void sendError(const char *, const char *, const char *, errorType, int);

	//Users
	std::vector<User *>	getUsers();
	void addUser(User *);
	void removeUser(int &);
    void setNick(int , std::string &);
	std::string	&getNick(int);
	std::string	&getNick(User *);
	void delChannelFromUser(std::string &channelName, int user_index);

	//Channels
	std::vector<Channel *>	getChannels();
	void addChannel(std::string &name, std::string &topic, int index);
	void removeChannel(int &);
	std::vector<Channel *>::iterator findChannel(std::string &name);
	void joinChannel(int index, std::string &channel);
	bool isValidChannel(std::string &);
	void delUserFromChannel(std::string &channelName, int);
	bool isChannelEmpty(std::string &channelName);
	void delChannel(std::string &channelName);
	void sendToAllUsersInChannel(std::string &channelName, std::string &response);
	void printChannels();

	//Pfds
	void addSockToPfds(int);
	void removeSockFromPfds(int socket);
	int  findClientSock(int socket);
	int	 getPfdsSize();
	int	 getPfdsSock(int &);

	void closeServer();
	void closeUser(int);
};


#endif
