#include "bot.hpp"
#include <netdb.h>
#define HTTPS_PORT 443

void apiCmd(Client &client, std::string &string)
{
	(void)string;
	int						socketClient;
	sockaddr_in				addrClient;
	struct hostent			*host;

 	std::string url = "ifconfig.co";
	std::cout << "totem" << std::endl;
	host = gethostbyname(url.c_str());
	socketClient = socket(IP_TYPE, PROTOCOLE, IPPROTO_TCP);
	addrClient.sin_addr.s_addr = *((unsigned long*)host->h_addr);
	addrClient.sin_family = IP_TYPE;
	addrClient.sin_port = htons(HTTPS_PORT);

	// std::string request ="GET \r\nHost: " + url + "\r\nConnection: close\r\n\r\n";
	std::string request;
	request = "GET /HTTPS/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";

	std::cout << "totem" << std::endl;
	connect(socketClient, (const struct sockaddr*)&addrClient, (socklen_t)sizeof(addrClient));
	std::cout << "totem2" << std::endl;
	// if(connect(socketClient, (struct sockaddr*)&addrClient, (socklen_t)sizeof(addrClient)) < 0)
	// {
	// 	std::cerr << "Error while connecting socket" << std::endl;
	// 	close(socketClient);
	// 	exit(1);	
	// }
	send(socketClient ,request.c_str(), request.length(),0 );
	std::cout << "totem3" << std::endl;
	char buff[100000];
	int n;
	n = recv(socketClient , buff, sizeof(buff), 0);
	buff[n] = '\0';
	close(socketClient);
	std::string response;
	std::cout << "response gotten:" << buff << std::endl;
	response = buff;
	std::cout << "response gotten:" << response << std::endl;
	client.bsend(response);
}
