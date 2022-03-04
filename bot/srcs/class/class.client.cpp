#include "bot.hpp"

Client::Client(): _config() {};

Client::Client(int socket, in_addr_t addr, short family, unsigned short port): _config(socket, addr, family, port) {};

Client::~Client() {};

void	Client::closeClient() const {
	close(_config.socketClient);
	std::cout << "Client closed." << std::endl;
};

int Client::connectSock() {
	if (connect(_config.socketClient, (const struct sockaddr *)&(_config.addrClient), sizeof(_config.addrClient)) == -1)
		return (-1);
	std::cout << "[Connect] : client " << _config.socketClient <<  std::endl;
	return (0);
};

void	Client::recvSock(std::string &string) {
	char msg[1000];
	recv(_config.socketClient, &msg, 1000, 0);
	string = msg;
	memset(msg, '\0', 1000);
};

void Client::sendInfo() {
	std::string nick("NICK bot\r\nUSER bot bot 127.0.0.1 :bot\r");
	send(_config.socketClient, nick.c_str(), nick.length(), 0);
}

void Client::join() {
	std::string string("JOIN #bot\r");
	send(_config.socketClient, string.c_str(), string.length(), 0);
}
