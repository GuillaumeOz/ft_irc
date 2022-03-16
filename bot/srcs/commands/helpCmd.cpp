#include "bot.hpp"

void    helpCmd(Client &client, std::string &string) {
    (void)string;
    std::string help("PRIVMSG #bot :The avaliable commands are:\nPRIVMSG #bot :- !creators -> get beautiful ascii art of the creators of this project.\nPRIVMSG #bot :- !ascii -> get beautiful ascii art of the 42 logo.\n");
    client.bsend(help);
}
