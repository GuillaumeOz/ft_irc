#include "ft_irc.hpp"

//guillaumeoz_ sets mode -n #test2   ---> channel
// guillaumeoz_ sets mode +i guillaumeoz_ ---> nick
std::string	composeNickMode(int8_t nickMode) {
	std::string ret = "+";

	if (nickMode & MODE_USER_A) {
		ret += "a";
	}
	if (nickMode & MODE_USER_I) {
		ret += "i";
	}
	if (nickMode & MODE_USER_R) {
		ret += "r";
	}
	return (ret + "\n");
}

void	displayChannelMode(Server &server, int index, std::string &channelName, int8_t channelMode, char prefix) {
	std::string mode = "0";
	if (channelMode & MODE_CHANNEL_I) {
		channelMode ^= MODE_CHANNEL_I;
		mode = "i";
	}
	else if (channelMode & MODE_CHANNEL_M) {
		channelMode ^= MODE_CHANNEL_M;
		mode = "m";
	}
	else if (channelMode & MODE_CHANNEL_N) {
		channelMode ^= MODE_CHANNEL_N;
		mode = "n";
	}
	else if (channelMode & MODE_CHANNEL_P) {
		channelMode ^= MODE_CHANNEL_P;
		mode = "p";
	}
	else if (channelMode & MODE_CHANNEL_T) {
		channelMode ^= MODE_CHANNEL_T;
		mode = "t";
	}
	else if (channelMode & MODE_CHANNEL_K) {
		channelMode ^= MODE_CHANNEL_K;
		mode = "k";
	}
	else if (channelMode & MODE_CHANNEL_L) {
		channelMode ^= MODE_CHANNEL_L;
		mode = "l";
	}
	if (mode != "0") {
		std::string initChanelModeRespose = getCmdString(server, index, channelName, (prefix + mode), "MODE");
		server.ssend(initChanelModeRespose, index);
		displayChannelMode(server, index, channelName, channelMode, prefix);
	}
}

bool	isModeinLobby(std::string &command) {
	std::string ret;
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, "\0");
	ret = tmp;
	ret = eraseCarriageReturn(ret);
	ret = eraseLineBreak(ret);
	ret = eraseSelectedChar(ret, ' ');
	if (ret.compare("ircserv") == 0)
		return (true);
	return (false);
}

bool	isModeNick(Server &server, int index, std::string &command, std::string &nickName) {
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, " ");
	nickName = tmp;
	nickName = eraseCarriageReturn(nickName);
	nickName = eraseLineBreak(nickName);
	nickName = eraseSelectedChar(nickName, ' ');
	POUT("NICKNAME")
	POUT(nickName)
	if (nickName.compare(server.getNick(index)) == 0)
		return (true);
	return (false);
}

bool	isModeChannel(Server &server, std::string &command, std::string &channelName) {
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, " ");
	channelName = tmp;
	channelName = eraseCarriageReturn(channelName);
	channelName = eraseLineBreak(channelName);
	channelName = eraseSelectedChar(channelName, ' ');
	POUT("CHANNEL")
	POUT(channelName)
	if (server.findChannel(channelName) != server.channels.end())
		return (true);
	return (false);
}

bool	isModeOnlyNick(std::string &command, std::string &userNick) {
	std::string ret;
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, "\0");
	ret = tmp;
	ret = eraseCarriageReturn(ret);
	ret = eraseLineBreak(ret);
	ret = eraseSelectedChar(ret, ' ');
	if (ret.compare(userNick) == 0)
		return (true);
	return (false);
}

// default +iwx
void	handleModeNick(Server &server, int index, std::string &command, std::string &nickName) {
	POUT("C LE USER")

	POUT(command)
	if (isModeOnlyNick(command, server.getNick(index)) == true) {
		// server.getUserMode();
		std::string composedNickMode = composeNickMode(server.getUsers()[index]->getUserMode());
		// std::string onlyNickResponse = getCmdString(server, index, "ircserv", composedNickMode, "PRIVMSG");
		server.ssend(composedNickMode, index);
	}

		// std::vector<User *>::iterator	it = server.getUsers().begin() + index;
		// (*it)->assignMode(static_cast<userMode>());
		// // iwx
	
	(void)nickName;
}

// default +nt  
// MODE_CHANNEL_USER_O
void	handleModeChannel(Server &server, int index, std::string &command, std::string &channelName) {
	POUT("C LE CHANNEL")
	std::vector<Channel *>::iterator	it = server.findChannel(channelName);
	size_t								channelIndex = server.findChannelIndex(channelName);

	if (server.ischannelModeOn(static_cast<channelMode>(MODE_CHANNEL_T | MODE_CHANNEL_N), channelIndex) == false) {
		server.getUsers()[index]->assignChannelUserMode(channelName, MODE_CHANNEL_USER_O);
		(*it)->assignMode(static_cast<channelMode>(MODE_CHANNEL_T | MODE_CHANNEL_N));
		displayChannelMode(server, index, channelName, (*it)->getChannelMode(), '+');
		return ;
	}

	(void)command;
}

void	modeCmd(Server &server, int index, std::string &command) {
POUT("***************BEGIN***************")

	std::string	userName;
	std::string	channelName;

	if (isModeinLobby(command) == true) {
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_NOSUCHNICK, index);
		return ;
	}
	if (isModeNick(server, index, command, userName) == true) {
		handleModeNick(server, index, command, userName);
	}
	else if (isModeChannel(server, command, channelName) == true) {
		handleModeChannel(server, index, command, channelName);
	}
	else
		server.sendErrorServerUser("IRC ", NULL, NULL, ERR_NOSUCHNICK, index);

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

