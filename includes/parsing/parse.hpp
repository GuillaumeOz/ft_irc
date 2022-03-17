#ifndef PARSE_HPP
# define PARSE_HPP

/* --------------------------------- parsing -------------------------------- */
void 			parseClientInformations(std::string &, int, Server &);
void			parseCommands(std::vector<parsed *> &, std::string);
void			printParsedCommand(parsed *);
void			printParsedCommands(std::vector<parsed *> &);
std::string		getCmdString(Server &, int, std::string , std::string , std::string);

/* ------------------------ erase unwanted characters ----------------------- */

std::string		eraseSelectedChar(std::string &, char);
std::string		eraseLineBreak(std::string &);
std::string		eraseCarriageReturn(std::string &);

#endif
