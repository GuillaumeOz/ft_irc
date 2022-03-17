#ifndef CLASS_CLIENT_HPP
# define CLASS_CLIENT_HPP

class Config;

class Client {

 private:

/* ---------------------------------- data ---------------------------------- */

	Config 														_config;
	std::string													_password;
	std::map<std::string, void (*)(Client &, std::string &)> 	_commands;

 public:

/* ------------------------ constructors/destructors ------------------------ */

	Client();
	Client(int socket,  in_addr_t addr, short family, unsigned short port);
	~Client();


/* --------------------------------- setters -------------------------------- */

	void	setPassword(char *);

/* --------------------------- socket manipulation -------------------------- */

	int 	connectSock();
	void	recvSock(std::string *string);
	void	closeClient() const;
	void	bsend(std::string &response);

/* --------------------------- commands functions --------------------------- */

	void	initCommands();
	void	callCommand(Client &, std::string &, std::string &);
	void	sendInfo();
	void	join();
};

#endif
