#include "bot.hpp"

bool	g_quit = {true};

void	quitBot(int code) {
	(void)code;
	g_quit = true;
}

void	*sendQuit(void *rawDataClient) {
	Client *client = reinterpret_cast<Client *>(rawDataClient);
	std::string quit = "QUIT :Quitte\n";
	while (!g_quit) ;
	client->bsend(quit);
	return (client);
}

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

std::string getCommand(std::string &string) {
    std::string		msg = getMsg(string);

    if (msg.compare(string) == 0) {
        std::cout << "Not a PRIVMSG, ignoring it." << std::endl;
        return (msg);
    }
    return (msg);
}

std::string	eraseCarriageReturn(std::string &string) {
	while (string.find("\r") != std::string::npos)
		string.erase(string.begin() + string.find("\r"));
	size_t n = string.find("\n");
	if (n != std::string::npos)
		string.erase(string.begin() + n, string.end());
	return (string);
}

int	main(int ac, char **av) {
	Client			client;
	std::string		msg;
	std::string		command;
	pthread_t 		thread_id;

	if (ac == 2)
		client.setPassword(av[1]);
	if (client.connectSock() != -1)
		g_quit = false;
	if (!g_quit) {
		client.sendInfo();
		usleep(20);
		client.join();
	}
	pthread_create(&thread_id, NULL, sendQuit, &client);
	while (!g_quit) {
		signal(SIGINT, &quitBot);
		client.recvSock(&msg);
		eraseCarriageReturn(msg);
        std::cout << "message received by bot: " << msg << std::endl;
		command = getCommand(msg);
		client.callCommand(client, command, msg);
		msg.clear();
	}
	pthread_join(thread_id, NULL);
	client.closeClient();
	return (0);
}
