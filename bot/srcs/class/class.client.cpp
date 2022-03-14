#include "bot.hpp"

Client::Client(): _config() {
	initCommands();
};

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

void	Client::recvSock(std::string *string) {
	char	tmpBuff[1000];

	do {
		memset(tmpBuff, '\0', sizeof(tmpBuff));
		recv(_config.socketClient, tmpBuff, sizeof(tmpBuff), 0);
		*string += tmpBuff;
	} while (strchr(tmpBuff, '\0') == NULL);
};

void Client::sendInfo() {
	std::string nick("NICK bot\r\nUSER bot bot 127.0.0.1 :bot\r");
	send(_config.socketClient, nick.c_str(), nick.length(), 0);
}

void Client::join() {
	std::string string("JOIN #bot\r");
	send(_config.socketClient, string.c_str(), string.length(), 0);
}

void Client::initCommands() {
	_commands["!ascii"] = &asciiCmd;
	_commands["!creators"] = &creatorsCmd;
	_commands["!help"] = &helpCmd;
}

void	Client::callCommand( Client &client, std::string &command, std::string &string) {
	std::string error("the bot doesn't know this command: ");
	std::cout << "command to find:" << command << std::endl;
	if (_commands.find(command) != _commands.end())
		_commands.find(command)->second(client, string);
	else
		bsend(error += command + "\n");
}

void Client::bsend(std::string &response) {
	send(_config.socketClient, response.c_str(), response.length(), 0);
	std::cout << "response sent: " << response << std::endl;
}
