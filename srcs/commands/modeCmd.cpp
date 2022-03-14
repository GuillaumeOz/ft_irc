#include "ft_irc.hpp"

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

std::string	composeChannelMode(int8_t channelMode, std::string &channelName) {
	std::string ret = "+";

	if (channelMode & MODE_CHANNEL_I) {
		ret += "i";
	}
	if (channelMode & MODE_CHANNEL_M) {
		ret += "m";
	}
	if (channelMode & MODE_CHANNEL_N) {
		ret += "n";
	}
	if (channelMode & MODE_CHANNEL_P) {
		ret += "p";
	}
	if (channelMode & MODE_CHANNEL_T) {
		ret += "t";
	}
	if (channelMode & MODE_CHANNEL_K) {
		ret += "k";
	}
	if (channelMode & MODE_CHANNEL_L) {
		ret += "l";
	}
	ret = "Channel " + channelName + " modes: " + ret + "\n";
	return (ret);
}

void	displayNickMode(Server &server, int index, std::string &nick, int8_t nickMode, char prefix) {
	std::string mode = "0";
	if (nickMode & MODE_USER_A) {
		nickMode ^= MODE_USER_A;
		mode = "a";
	}
	else if (nickMode & MODE_USER_I) {
		nickMode ^= MODE_USER_I;
		mode = "i";
	}
	else if (nickMode & MODE_USER_R) {
		nickMode ^= MODE_USER_R;
		mode = "r";
	}
	if (mode != "0") {
		std::string initChanelModeRespose = getCmdString(server, index, nick, (prefix + mode), "MODE");
		server.ssend(initChanelModeRespose, index);
		displayNickMode(server, index, nick, nickMode, prefix);
	}
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

bool	isModeinLobby(std::string command) {
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

bool	isModeNick(Server &server, int index, std::string command, std::string &nickName) {
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

bool	isModeChannel(Server &server, std::string command, std::string &channelName) {
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

bool	isModeOnlyNick(std::string command, std::string &userNick) {
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

bool	isModeChanges(std::string command, size_t &findLen) {
	for (size_t i = 0; command[i] != '\0'; i++) {
		if (command[i] == '+' || command[i] == '-') {
			findLen = i;
			return (true);
		}
	}
	return (false);
}

bool	isKnowUserMode(char mode, userMode &modeToAdd) {
	if (mode == 'a') {
		modeToAdd = MODE_USER_A;
		return (true);
	}
	else if (mode == 'i') {
		modeToAdd = MODE_USER_I;
		return (true);
	}
	else if (mode == 'r') {
		modeToAdd = MODE_USER_R;
		return (true);
	}
	return (false);
}

bool	isKnowUserModeInChannel(char mode, channelUserMode &modeToAdd) {
	if (mode == 'o') {
		modeToAdd = MODE_CHANNEL_USER_O;
		return (true);
	}
	else if (mode == 'v') {
		modeToAdd = MODE_CHANNEL_USER_V;
		return (true);
	}
	return (false);
}

void	changeNickMode(Server &server, std::string command, std::string &nickName, size_t findLen, int index) {
	char 		*mode = const_cast<char *>(command.c_str() + findLen);
	char		prefix;
	userMode	modeToAddDel;

	for (int i = 0; mode[i] != '\0'; i++) {
		modeToAddDel = NO_USER_MODE;

		if (isspace(mode[i])) {
			return ;
		}
		else if (mode[i] == '+')
			prefix = '+';
		else if (mode[i] == '-')
			prefix = '-';
		else if (isKnowUserMode((mode[i]), modeToAddDel) == true) {
			if (prefix == '+') {
				if (!(server.getUsers()[index]->getUserMode() & modeToAddDel)) {
					server.getUsers()[index]->assignMode(modeToAddDel);
					displayNickMode(server, index, nickName, modeToAddDel, prefix);
				}
			}
			else if (prefix == '-') {
				if (server.getUsers()[index]->getUserMode() & modeToAddDel) {
					server.getUsers()[index]->removeMode(modeToAddDel);
					displayNickMode(server, index, nickName, modeToAddDel, prefix);
				}
			}
		}
		else {
			std::string errMode;
			errMode += mode[i];
			server.sendErrorServerUser(errMode.c_str(), NULL, NULL, ERR_UMODEUNKNOWNFLAG, index);
		}
	}
}

void	handleModeNick(Server &server, int index, std::string &command, std::string &nickName) {
	POUT("C LE USER")
	size_t findLen;

    //add  502    ERR_USERSDONTMATCH ":Cannot change mode for other users" ??
	if (isModeOnlyNick(command, server.getNick(index)) == true) {
		std::string composedNickMode = composeNickMode(server.getUsers()[index]->getUserMode());
		server.ssend(composedNickMode, index);
	}
	else if (isModeChanges(command, findLen) == true) {
		changeNickMode(server, command, nickName, findLen, index);
	}
}

bool	isModeOnlyChannel(std::string command, std::string &channelName) {
	std::string ret;
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, "\0");
	ret = tmp;
	ret = eraseCarriageReturn(ret);
	ret = eraseLineBreak(ret);
	ret = eraseSelectedChar(ret, ' ');
	if (ret.compare(channelName) == 0)
		return (true);
	return (false);
}

void	displayUserInChannelMode(Server &server, int index, std::string &nick, int8_t nickMode, char prefix) {
	std::string mode = "0";
	if (nickMode & MODE_CHANNEL_USER_O) {
		nickMode ^= MODE_CHANNEL_USER_O;
		mode = "o";
	}
	else if (nickMode & MODE_CHANNEL_USER_V) {
		nickMode ^= MODE_CHANNEL_USER_V;
		mode = "v";
	}
	if (mode != "0") {
		std::string initChanelModeRespose = getCmdString(server, index, nick, (prefix + mode), "MODE");
		server.ssend(initChanelModeRespose, index);
		displayUserInChannelMode(server, index, nick, nickMode, prefix);
	}
}

bool	isUserInChannelMode(Server &server, std::string command, std::string &channelName, std::string &nickName) {
	std::vector<Channel *>::iterator	it = server.findChannel(channelName);
	std::string delimiter = " ";
	size_t		pos = 0;

	while ((pos = command.find(delimiter)) != std::string::npos) {
		command.erase(0, pos + delimiter.length());
	}
	command = eraseCarriageReturn(command);
	command = eraseLineBreak(command);
	if ((*it)->findUser(command) != (*it)->getUsersEnd()) {
		nickName = command;
		POUT("LAICI:LALALLSCK:ASMCKLAS")
		POUT(nickName)
		return (true);
	}
	return (false);
// 		ERR_USERNOTINCHANNEL   "<nick> <channel> :They aren't on that channel"
}

void	changeUserInChannelMode(Server &server, std::string command, std::string &channelName, std::string &nickName, int index) {
	size_t	findLen;

	if (isModeChanges(command, findLen) == true) {
		char 			*mode = const_cast<char *>(command.c_str() + findLen);
		char			prefix;
		channelUserMode	modeToAddDel;

		for (int i = 0; mode[i] != ' '; i++) {
			modeToAddDel = NO_CHANNEL_USER_MODE;

			if (isspace(mode[i])) {
				return ;
			}
			else if (mode[i] == '+')
				prefix = '+';
			else if (mode[i] == '-')
				prefix = '-';
			else if (isKnowUserModeInChannel((mode[i]), modeToAddDel) == true) {
				if (prefix == '+') {
					if (!(server.getUsers()[index]->isChannelUserModeOn(channelName, modeToAddDel))) {
						server.getUsers()[index]->assignChannelUserMode(channelName, modeToAddDel);
						displayUserInChannelMode(server, index, nickName, modeToAddDel, prefix);
					}
				}
				else if (prefix == '-') {
					if (server.getUsers()[index]->isChannelUserModeOn(channelName, modeToAddDel)) {
						server.getUsers()[index]->removeChannelUserMode(channelName, modeToAddDel);
						displayUserInChannelMode(server, index, nickName, modeToAddDel, prefix);
					}
				}
			}
			else {
				std::string errMode;
				errMode += mode[i];
				server.sendErrorServerUser(errMode.c_str(), NULL, NULL, ERR_UMODEUNKNOWNFLAG, index);
			}
		}
	}
}

bool	isKnowChannelMode(char mode, channelMode &modeToAdd) {
	if (mode == 'i') {
		modeToAdd = MODE_CHANNEL_I;
		return (true);
	}
	else if (mode == 'm') {
		modeToAdd = MODE_CHANNEL_M;
		return (true);
	}
	else if (mode == 'n') {
		modeToAdd = MODE_CHANNEL_N;
		return (true);
	}
	else if (mode == 'p') {
		modeToAdd = MODE_CHANNEL_P;
		return (true);
	}
	else if (mode == 't') {
		modeToAdd = MODE_CHANNEL_T;
		return (true);
	}
	else if (mode == 'k') {
		modeToAdd = MODE_CHANNEL_K;
		return (true);
	}
	else if (mode == 'l') {
		modeToAdd = MODE_CHANNEL_L;
		return (true);
	}
	return (false);
}

void	changeChannelMode(Server &server, std::string command, std::string &channelName, int index) {
	std::vector<Channel *>::iterator	it = server.findChannel(channelName);
	size_t	findLen;

	POUT("ICICICIC")
	if (isModeChanges(command, findLen) == true) {
		char 		*mode = const_cast<char *>(command.c_str() + findLen);
		char		prefix;
		channelMode	modeToAddDel;
		POUT("LALALAL")

		for (int i = 0; mode[i] != '\0'; i++) {
			modeToAddDel = NO_CHANNEL_MODE;

			POUT("mode")
			POUT(mode)
			if (isspace(mode[i])) {
				return ;
			}
			else if (mode[i] == '+')
				prefix = '+';
			else if (mode[i] == '-')
				prefix = '-';
			else if (isKnowChannelMode((mode[i]), modeToAddDel) == true) {
				if (prefix == '+') {
					if (!((*it)->getChannelMode() & modeToAddDel)) {
						(*it)->assignMode(modeToAddDel);
						displayChannelMode(server, index, channelName, modeToAddDel, prefix);
					}
				}
				else if (prefix == '-') {
					if ((*it)->getChannelMode() & modeToAddDel) {
						(*it)->removeMode(modeToAddDel);
						displayChannelMode(server, index, channelName, modeToAddDel, prefix);
					}
				}
			}
			else {
				std::string errMode;
				errMode += mode[i];
				server.sendErrorServerUser(errMode.c_str(), NULL, NULL, ERR_UMODEUNKNOWNFLAG, index);
			}
		}
	}
}

// default +nt  
// MODE_CHANNEL_USER_O
// guillaumeoz_ sets mode -n #test2   ---> channel
// guillaumeoz_ sets mode +i guillaumeoz_ ---> nick
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
	if (isModeOnlyChannel(command, channelName) == true) {
		std::string composedChannelMode = composeChannelMode((*it)->getChannelMode(), channelName);
		server.sendToMyselfInChannel(channelName, composedChannelMode, index);
	}
	else if (server.getUsers()[index]->isChannelUserModeOn(channelName, MODE_CHANNEL_USER_O) == true) {
		std::string nickName;
		if (isUserInChannelMode(server, command, channelName, nickName) == true)
			changeUserInChannelMode(server, command, channelName, nickName, index);
		else
			changeChannelMode(server, command, channelName, index);
		// 		ERR_KEYSET			"<channel> :Channel key already set"
	}
	else {
		server.sendErrorServerUser(channelName.c_str(), NULL, NULL, ERR_CHANOPRIVSNEEDED, index);
	}
}

void	modeCmd(Server &server, int index, std::string &command) {
POUT("***************BEGIN***************")
	POUT("command")
	POUT(command)

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

// SERVER ERROR:

// 		ERR_NEEDMOREPARAMS    "<command> :Not enough parameters"          
// 		ERR_NOCHANMODES      	"<channel> :Channel doesn't support modes"      
// 		ERR_UNKNOWNMODE			"<char> :is unknown mode char to me for <channel>"

// 		RPL_CHANNELMODEIS
// 		RPL_BANLIST                     RPL_ENDOFBANLIST
// 		RPL_EXCEPTLIST                  RPL_ENDOFEXCEPTLIST
// 		RPL_INVITELIST                  RPL_ENDOFINVITELIST
// 		RPL_UNIQOPIS

