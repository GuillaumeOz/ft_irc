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
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

/* ----------------------------- Socket headers ----------------------------- */

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>

/* ----------------------------- Project headers ----------------------------- */

#include "class.config.hpp"
#include "class.error.hpp"
#include "class.channel.hpp"
#include "class.server.hpp"
#include "class.user.hpp"

#include "commands.hpp"
#include "parse.hpp"

#endif
