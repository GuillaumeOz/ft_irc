#include "bot.hpp"

int	main() {
	Client			client;
	std::string		msg;
	// std::string		response;
	bool			quit = {true};

	if (client.connectSock() != -1)
		quit = false;
	if (!quit) {
		client.sendInfo();
		ussleep(20);
		client.join();
	}
	while (!quit) {
		client.recvSock(msg);
		// response = getResponse(client);
		// client.send(response);
	}
	client.closeClient();
	return (0);
}
