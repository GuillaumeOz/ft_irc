#include "bot.hpp"

void    asciiCmd(Client &client, std::string &string) {
	(void) string;
    std::string response("PRIVMSG #bot :                          @@@@@@@@@@@@@     *@@@@@@@@@@@@(@@@@@@@@@@@@\n                       /@@@@@@@@@@@@,       *@@@@@@@@@@  /@@@@@@@@@@@@\n                     @@@@@@@@@@@@@          *@@@@@@@     /@@@@@@@@@@@@\n                  (@@@@@@@@@@@@,            *@@@@@       /@@@@@@@@@@@@\n                @@@@@@@@@@@@@               *@@          /@@@@@@@@@@@@\n             (@@@@@@@@@@@@.                 ,            (@@@@@@@@@@@@\n           @@@@@@@@@@@@@                               @@@@@@@@@@@@@  \n        #@@@@@@@@@@@@.                              ,@@@@@@@@@@@@/    \n      @@@@@@@@@@@@@                               @@@@@@@@@@@@@       \n   #@@@@@@@@@@@@                               *@@@@@@@@@@@@*         \n @@@@@@@@@@@@&                               @@@@@@@@@@@@@            \n&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     *@@@@@@@@@@@@*          &@\n&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     *@@@@@@@@@@@@*        @@@@\n&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     *@@@@@@@@@@@@*     &@@@@@@\n&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     *@@@@@@@@@@@@*   @@@@@@@@@\n                          @@@@@@@@@@@@@     *@@@@@@@@@@@@*@@@@@@@@@@@@\n                          @@@@@@@@@@@@@                               \n                          @@@@@@@@@@@@@                               \n                          @@@@@@@@@@@@@                               \n                          @@@@@@@@@@@@@                               \n");
    client.bsend(response);
}