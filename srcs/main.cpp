#include "ft_irc.hpp"

// int	main(int ac, char **av) {
// 	Error error;
// 	std::string string;

// 	if (ac != 2)
// 		error.type = ARGUMENT;
// 	error.displayError();
// 	Server server(atoi(av[1]), error);
// 	server.sbind();
// 	server.slisten(4);
// 	server.saccept();
// 	server.srecv(&string);
// 	std::cout << string << std::endl;
// 	server.closeUser();
// 	server.closeServer();
// 	return (0);
// }


int		main() {
	int server_sock = socket(AF_INET, SOCK_STREAM, 0);
	int opt = 1;
	setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	struct	sockaddr_in	addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6667);
	addr.sin_addr.s_addr = INADDR_ANY;
	bind(server_sock, (struct sockaddr *) &addr, sizeof(addr));
	std::vector<struct pollfd>	pfds;
	pfds.push_back(pollfd());
	pfds.back().fd = server_sock;
	pfds.back().events = POLLIN;
	listen(server_sock, 5);
	while (1) {
		poll(&pfds[0], sizeof(pfds), -1);
		if (pfds[0].revents == POLLIN) {
			int sock = accept(server_sock, NULL, NULL);
			pfds.push_back(pollfd());
			pfds.back().fd = sock;
			pfds.back().events = POLLIN;
		}
		else {
			for (std::vector<struct pollfd>::iterator it = pfds.begin(); it != pfds.end(); it++) {
				if ((*it).revents == POLLIN) {
					char buf[256];
					int res = recv((*it).fd, &buf, sizeof(buf), 0);
					if (res > 0) {
						std::cout << buf << std::endl;
						if (strncmp(buf, "JOIN", 4) == 0) {
							std::cout << "joining\n";
							send((*it).fd, ":user42 JOIN #coco\n", 40, 0);
						}
						else {
							// send((*it).fd, string1.c_str(), string1.length(), 0);
							// send((*it).fd, ":user42 CONNECT 127.0.0.1 6667\n", 40, 0);
							// send((*it).fd, ":user42 NICK noam\n", 20, 0);
							// send((*it).fd, ":127.0.0.1 003 user42 :This server was created Thu Jan 27 2022\n", 64, 0);
							// send((*it).fd, ":127.0.0.1 004 user42 :test solanum-1.0-dev DGQRSZaghilopsuwz CFILMPQSTbcefgijklmnopqrstuvz\n", 93, 0);
						}
						    //    001 RPL_WELCOME "Welcome to the Internet Relay Network <nick>!<user>@<host>"
						// :borja!borja@polaris.cs.uchicago.edu PRIVMSG #cmsc23300 :Hello everybody
						// :<nickname>@<username>!<hostname> <COMMAND> <arg>\r\n
						// :irc.example.com 001 borja :Welcome to the Internet Relay Network borja!borja@polaris.cs.uchicago.edu
						// :irc.core.com 473 _Yeti_ #mIRC :Sorry, cannot join channel.

					}
					memset(buf, '\0', 255);
				}
			}
		}
	}
	return (0);
}
