#ifndef COMMANDS_HPP
# define COMMANDS_HPP

void	partCmd(Server &, int, parsed *);
// void	listCmd(Server &, int , std::string &);
// void	quitCmd(Server &, int, std::string &);
// void	userCmd(Server &, int, std::string &);
void	privmsgCmd(Server &, int, parsed *);
void	awayCmd(Server &, int, parsed *);
void	nickCmd(Server &, int, parsed *);
void	joinCmd(Server &, int, parsed *);
// void	topicCmd(Server &, int, std::string &);
// void	timeCmd(Server &, int, std::string &);
// void	noticeCmd(Server &, int, std::string &);

/* -------------------------------- response -------------------------------- */

std::string		awayResponse(void);
std::string		newUserResponse(std::string &);
std::string		nickResponse(std::string & , std::string &);
std::string 	joinResponse(Server &, int, std::string &);
std::string		privmsgResponse(Server &, int, std::string &, std::string &);
std::string		partResponse(Server &, int, std::string &, std::string &);

#endif
