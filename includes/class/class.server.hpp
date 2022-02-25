#ifndef CLASS_SERVER_HPP
# define CLASS_SERVER_HPP

class User;

class Server {

	private:

	Config																			_config;
	Error																			_error;
	std::vector<User *>																_user;
	std::vector<struct pollfd>														_pfds;
	std::string																		_password;
	std::map<std::string, void (*)(Server &, User *, std::string &)> 				_commands;

	public:
	std::vector<Channel *>		channel;

	Server(int port);
	Server(int port, Error error);
	~Server();

	void initCommands();
	void callCommand(std::string &, Server &, int &, std::string &);

	void sbind();
	void slisten(int);
	void saccept();
	void ssend(std::string &, int);
	void ssend(std::string &, User &);
	int  srecv(std::string *, int);
	void spoll();
	bool spollinCondition(int &);
	bool spolloutCondition(int &);

	std::vector<User *>	getUsers();
	void addUser(User *);
	void removeUser(int &);
    void setNick(int , std::string &);
	std::string	&getNick(int);
	std::string	&getNick(User *);
	
	std::vector<Channel *>	getChannels();
	void addChannel(std::string &name, std::string &topic, User *user);
	void removeChannel(int &);
	std::vector<Channel *>::iterator findChannel(std::string &name);
	void joinChannel(int index, std::string &channel);

	void addSockToPfds(int);
	void removeSockFromPfds(int socket);
	int  findClientSock(int socket);
	int	 getPfdsSize();
	int	 getPfdsSock(int &);

	void closeServer();
	void closeUser(int);
};


#endif
