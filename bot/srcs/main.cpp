#include "bot.hpp"

std::string	getMsg(std::string &string) {
	size_t i = string.find("PRIVMSG");

	if (i != std::string::npos) {
		std::string tmp = string.c_str() + i;
		size_t		j = tmp.find(":");

		if (j != std::string::npos) {
			tmp = tmp.c_str() + j + 1;
			return (tmp);
		}
	}
	return (string);
}

std::string getResponse(Client &client, std::string &string) {
    std::string		msg = getMsg(string);
	std::string		response;
	(void)client;

    if (msg.compare(string) == 0) {
        std::cout << "Not a PRIVMSG, ignoring it." << std::endl;
        return (msg);
    }
	response = msg;
    // response += ":bot PRIVMSG #bot :" + msg;
    return (response);
}

int	main() {
	Client			client;
	std::string		msg;
	std::string		response;
	bool			quit = {true};

	if (client.connectSock() != -1)
		quit = false;
	if (!quit) {
		client.sendInfo();
		usleep(20);
		client.join();
	}
	while (!quit) {
		client.recvSock(msg);
        std::cout << "message received by bot: " << msg << std::endl;
		response = getResponse(client, msg);
		std::cout << response << std::endl;
        // if (response.compare(msg) == 0)
        //     continue ;
		// client.send(response);
	}
	client.closeClient();
	return (0);
}
