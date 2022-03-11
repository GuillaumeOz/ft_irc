#ifndef FT_IRC_HPP
# define FT_IRC_HPP

/* --------------------------------- Macros --------------------------------- */

#define POUT(x) std::cout << x << std::endl;
#define PERR(x) std::cerr << x << std::endl;
#define IP_TYPE AF_INET
#define SOCKET_TYPE SOCK_STREAM
#define HOST "127.0.0.1"

/* ----------------------------- Common headers ----------------------------- */

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <map>

/* ----------------------------- Socket headers ----------------------------- */

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>

/* ----------------------------- Project enums ----------------------------- */

enum userMode {
	NO_USER_MODE = 0,
	MODE_USER_A = (1 << 0),
	MODE_USER_I = (1 << 1),
	MODE_USER_R = (1 << 2),
	// MODE_USER_W = (1 << 3),
	// MODE_USER_O = (1 << 4)
};

enum channelUserMode {
	NO_CHANNEL_USER_MODE = 0,
	MODE_CHANNEL_USER_O = (1 << 0),
	MODE_CHANNEL_USER_V = (1 << 1)
};

enum channelMode {

	NO_CHANNEL_MODE = 0,
	MODE_CHANNEL_I = (1 << 0),
	MODE_CHANNEL_M = (1 << 1),
	MODE_CHANNEL_N = (1 << 2),
	MODE_CHANNEL_P = (1 << 3),
	MODE_CHANNEL_T = (1 << 4),
	MODE_CHANNEL_K = (1 << 5),
	MODE_CHANNEL_L = (1 << 6)
};

/* ----------------------------- Project headers ----------------------------- */

#include "class.config.hpp"
#include "class.error.hpp"
#include "class.channel.hpp"
#include "class.server.hpp"
#include "class.user.hpp"

#include "commands.hpp"
#include "parse.hpp"


#endif
