#ifndef CLASS_CLIENT_HPP
# define CLASS_CLIENT_HPP

class Config;

class Client {

 private:
	Config _config;

 public:

	Client();
	Client(int socket,  in_addr_t addr, short family, unsigned short port);
	~Client();

	int connectSock();
	void recvSock(std::string &string);
	void join();
	void closeClient() const;
	void sendInfo();
};

#endif
