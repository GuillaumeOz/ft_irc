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
	Client(int, in_addr_t, short , unsigned short);
	~Client();

/* ------------------------------- connection ------------------------------- */

	void	recvSock(std::string *);
	int 	connectSock();
	void	closeClient() const;
	void	bsend(std::string &);

/* ---------------------------------- other --------------------------------- */
	void	initCommands();
	void	join();
	void	setPassword(char *);
	void	sendInfo();
	void	callCommand(Client &, std::string &, std::string &);
};

#endif
