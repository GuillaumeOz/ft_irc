#ifndef CLASS_SERVER_HPP
# define CLASS_SERVER_HPP

class User;

class Server {

	private:
	
	Config	_config;
	Error	_error;
	User	_user;
	

	public:

	Server(int port);
	Server(int port, Error error);
	~Server();

	void sbind();
	void slisten(int);
	void saccept();
	void ssend(std::string &);
	void srecv(std::string *);

	void closeServer();
	void closeUser();
};


#endif
