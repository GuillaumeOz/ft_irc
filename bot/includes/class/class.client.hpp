#ifndef CLASS_CLIENT_HPP
# define CLASS_CLIENT_HPP

class Config;

class Client {

 private:
	Config 														_config;
	std::string													_password;
	std::map<std::string, void (*)(Client &, std::string &)> 	_commands;

 public:

	Client();
	Client(int socket,  in_addr_t addr, short family, unsigned short port);
	~Client();

	void	initCommands();
	int 	connectSock();
	void	recvSock(std::string *string);
	void	join();
	void	closeClient() const;
	void	setPassword(char *);
	void	sendInfo();
	void	callCommand(Client &, std::string &, std::string &);
	void	bsend(std::string &response);
};

#endif
