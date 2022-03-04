#ifndef PARSE_HPP
# define PARSE_HPP

std::string		getCmdString(Server &server, int index,
					std::string &channelName, std::string &reason, std::string &cmd);
std::string		eraseLineBreak(std::string &);
std::string		eraseCarriageReturn(std::string &);
void 	        parseClientInformations(std::string &, int, Server &);

#endif
