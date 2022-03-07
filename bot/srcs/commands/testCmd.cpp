#include "bot.hpp"

void    testCmd(Client &client, std::string &string) {
	(void) string;
    std::string response("PRIVMSG #bot :lalalalalalal\n");
    client.bsend(response);
}
