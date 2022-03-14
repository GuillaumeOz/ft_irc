#include "bot.hpp"

void    helpCmd(Client &client, std::string &string) {
    (void)string;
    std::string help("PRIVMSG #bot :The avaliable commands are:\n- !creators -> get beautiful ascii art of the creators of this project.\n- !ascii -> get beautiful ascii art of the 42 logo.\n");
    client.bsend(help);
}
