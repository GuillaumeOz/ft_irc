#include "ft_irc.hpp"

// bool	isModeinLobby(std::string &string) {
// 	size_t			n;

// 	char *str = const_cast<char *>(string.c_str() + string.find(" "));
// 	POUT("subString1")
// 	POUT(subString)
// 	eraseCarriageReturn(subString);
// 	eraseLineBreak(subString);
// 	eraseSelectedChar(subString, ' ');
// 	POUT("subString2")
// 	POUT(subString)
// 	if (subString.compare("ircserv") == 0)
// 		return (true);
// 	return (false);
// }

bool	isModeinLobby(std::string &command) {
	std::string ret;
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, "\0");
	ret = tmp;
	ret = eraseCarriageReturn(ret);
	ret = eraseLineBreak(ret);
	ret = eraseSelectedChar(ret, ' ');
	POUT("subString2")
	POUT(ret)
	if (ret.compare("ircserv") == 0)
		return (true);
	return (false);
}

void	modeCmd(Server &server, int index, std::string &command) {
POUT("***************BEGIN***************")
	POUT(command)
	// std::string	modeArg;

	if (isModeinLobby(command) == true) {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_NOSUCHCHANNEL, index);
		return ;
	}
	// modeArg = parseModeArg(command);

	// if () //user mode cmd
	// else //channel mode cmd
	// (void)command;
	// (void)index;
	// (void)server;
POUT("****************END****************")
}

// USER ERROR:
    //    502    ERR_USERSDONTMATCH ":Cannot change mode for other users"
	    //    461    ERR_NEEDMOREPARAMS  "<command> :Not enough parameters"
	    //    501    ERR_UMODEUNKNOWNFLAG  ":Unknown MODE flag"

    //    221    RPL_UMODEIS "<user mode string>"
    //      - To answer a query about a client's own mode,
    //        RPL_UMODEIS is sent back.

// SERVER ERROR:

// 		ERR_NEEDMOREPARAMS    "<command> :Not enough parameters"          
// 		ERR_KEYSET			"<channel> :Channel key already set"
// 		ERR_NOCHANMODES      	"<channel> :Channel doesn't support modes"      
// 		ERR_CHANOPRIVSNEEDED	"<channel> :You're not channel operator"
// 		ERR_USERNOTINCHANNEL   "<nick> <channel> :They aren't on that channel"      
// 		ERR_UNKNOWNMODE			"<char> :is unknown mode char to me for <channel>"

// 		RPL_CHANNELMODEIS
// 		RPL_BANLIST                     RPL_ENDOFBANLIST
// 		RPL_EXCEPTLIST                  RPL_ENDOFEXCEPTLIST
// 		RPL_INVITELIST                  RPL_ENDOFINVITELIST
// 		RPL_UNIQOPIS

