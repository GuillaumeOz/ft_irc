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
#include <map>

/* ----------------------------- Socket headers ----------------------------- */

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

/* ----------------------------- Project headers ----------------------------- */

#include "class.config.hpp"
#include "class.error.hpp"
#include "class.server.hpp"

#endif
