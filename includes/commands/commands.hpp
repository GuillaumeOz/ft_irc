#ifndef COMMANDS_HPP
# define COMMANDS_HPP

void	partCmd(Server &, int, std::string &);
void	joinCmd(Server &, int, std::string &);
void	privmsgCmd(Server &, int, std::string &);
void	listCmd(Server &, int , std::string &);
void	quitCmd(Server &, int, std::string &);
void	userCmd(Server &, int, std::string &);
void	awayCmd(Server &, int, std::string &);
void	nickCmd(Server &, int, std::string &);
void	topicCmd(Server &, int, std::string &);
void	timeCmd(Server &, int, std::string &);
void    noticeCmd(Server &, int, std::string &);
void	passCmd(Server &, int , std::string &);

#endif
