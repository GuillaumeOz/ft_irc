#ifndef CLASS_CONFIG_HPP
# define CLASS_CONFIG_HPP

class Config {

 public:

	int						socketClient;
	sockaddr_in				addrClient;

	Config() {
		socketClient = socket(IP_TYPE, PROTOCOLE, 0);
		addrClient.sin_addr.s_addr = inet_addr("127.0.0.1");
		addrClient.sin_family = IP_TYPE;
		addrClient.sin_port = htons(PORT);
	};

	Config(int socket, in_addr_t addr, short family, unsigned short port): socketClient(socket) {
		addrClient.sin_addr.s_addr = addr;
		addrClient.sin_family = family;
		addrClient.sin_port = port;
	};

	~Config() {};

};

#endif
