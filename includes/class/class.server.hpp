#ifndef CLASS_SERVER_HPP
# define CLASS_SERVER_HPP

class User;

class Server {

	private:

	Config															_config;
	Error															_error;
	std::vector<struct pollfd>										_pfds;
	std::string														_password;
	std::vector<User *>												_users;
	std::map<std::string, void (*)(Server &, int , std::string &)> 	_commands;

	public:
	std::vector<Channel *>											channels;

	Server(int port);
	Server(int port, Error error);
	~Server();

	//Commands
	void initCommands();
	void callCommand(std::string &, Server &, int &, std::string &);

	//Sockets
	void sbind();
	void slisten(int);
	int saccept();
	void ssend(std::string &, int);
	void ssend(std::string &, User &);
	int  srecv(std::string *, int);
	void spoll();
	bool spollinCondition(int &);
	bool spolloutCondition(int &);

	//Error
	void sendErrorServer(const char *, const char *, const char *, errorType);
	void sendErrorUser(const char *, const char *, const char *, errorType, int);
	void sendErrorServerUser(const char *, const char *, const char *, errorType, int);

	//Users
	std::vector<User *>	getUsers();
	void addUser(User *);
	void removeUser(int &);
    void setHost(int , std::string &);
    void setNick(int , std::string &);
    void setUsername(int , std::string &);
    void setRealname(int , std::string &);
	std::string	&getHost(int);
	std::string	&getNick(int);
	std::string	&getUsername(int);
	std::string	&getRealname(int);
	void delChannelFromUser(std::string &channelName, int user_index);
	bool isUserModeOn(userMode mode, int index);
	void assignUserMode(userMode mode, int index);
	int findUserIndex(std::string &nick);
	void setUserAwayMessage(int index, std::string &message);
	bool isUserAway(int index);
	std::string &getUserAwayMessage(int index);

	//Channels
	std::vector<Channel *>	getChannels();
	void addChannel(std::string &name, std::string &topic, int index);
	void addChannelToUser(int index, std::string channelName);
	void removeChannel(int &);
	std::vector<Channel *>::iterator findChannel(std::string &name);
	void joinChannel(int index, std::string &channel);
	bool isValidChannel(std::string &);
	void delUserFromChannel(std::string &channelName, int);
	bool isChannelEmpty(std::string &channelName);
	void delChannel(std::string &channelName);
	void sendToAllUsersInChannel(std::string &channelName, std::string &response);
	void sendToOtherUsersInChannel(std::string &channelName, std::string &response, int index);
	void printChannels();
	bool ischannelModeOn(channelMode mode, int index);
	void assignchannelMode(channelMode mode, int index);

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
