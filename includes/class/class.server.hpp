#ifndef CLASS_SERVER_HPP
# define CLASS_SERVER_HPP

class User;

class Server {

	private:
	
	Config						_config;
	Error						_error;
	std::vector<User *>			_user;
	std::vector<struct pollfd>	_pfds;

	public:

	Server(int port);
	Server(int port, Error error);
	~Server();

	void sbind();
	void slisten(int);
	void saccept();
	void ssend(std::string &, int);
	int srecv(std::string *, int);
	void spoll();
	bool spollinCondition(int &);
	bool spolloutCondition(int &);

	void addUser(User *);
	void removeUser(int &);
	
	void addSockToPfds(int);
	void removeSockFromPfds(int socket);
	int  findClientSock(int socket);
	int	 getPfdsSize();
	int	 getPfdsSock(int &);

	void closeServer();
	void closeUser(int);
};


#endif
