#ifndef COMMANDS_HPP
# define COMMANDS_HPP

void	partCmd(Server &, int, parsed *);
void	listCmd(Server &, int , parsed *);
void	quitCmd(Server &, int, parsed *);
void	userCmd(Server &, int, parsed *);
void	privmsgCmd(Server &, int, parsed *);
void	awayCmd(Server &, int, parsed *);
void	nickCmd(Server &, int, parsed *);
void	joinCmd(Server &, int, parsed *);
void	topicCmd(Server &, int, parsed *);
void	timeCmd(Server &, int, parsed *);
void	noticeCmd(Server &, int, parsed *);

/* -------------------------------- response -------------------------------- */

std::string		awayResponse(void);
std::string		newUserResponse(std::string &);
std::string		nickResponse(std::string & , std::string &);
std::string 	joinResponse(Server &, int, std::string &);
std::string		privmsgResponse(Server &, int, std::string &, std::string &);
std::string		partResponse(Server &, int, std::string &, std::string &);
std::string     quitResponse(Server &, int, std::string &, std::string &);
std::string     noticeResponse(Server &, int, std::string &, std::string &);


#endif
