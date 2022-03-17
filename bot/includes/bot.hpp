#ifndef BOT_HPP
# define BOT_HPP

#define IP_TYPE AF_INET
#define PROTOCOLE SOCK_STREAM
#define PORT 6667

/* ----------------------------- Common headers ----------------------------- */

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <map>
#include <signal.h>
#include <pthread.h>

/* ----------------------------- Socket headers ----------------------------- */

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <poll.h>

/* ----------------------------- Project headers ----------------------------- */

#include "class.config.hpp"
#include "class.client.hpp"
#include "commands.hpp"
#include "parsing.hpp"

#endif
