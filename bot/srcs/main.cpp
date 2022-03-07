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

int	main() {
	Client			client;
	std::string		msg;
	std::string		command;
	pthread_t 		thread_id;

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
		client.recvSock(msg);
		eraseCarriageReturn(msg);
        std::cout << "message received by bot: " << msg << std::endl;
		command = getCommand(msg);
		client.callCommand(client, command, msg);
	}
	pthread_join(thread_id, NULL);
	client.closeClient();
	return (0);
}
