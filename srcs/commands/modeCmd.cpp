#include "ft_irc.hpp"

std::string		composeNickMode(int8_t nickMode) {
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

std::string		composeChannelMode(int8_t channelMode, std::string &channelName) {
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

void			displayNickMode(Server &server, int index, std::string &nick, int8_t nickMode, char prefix) {
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
		std::string initChanelModeResponse = getCmdString(server, index, nick, (prefix + mode), "MODE");
		server.ssend(initChanelModeResponse, index);
		displayNickMode(server, index, nick, nickMode, prefix);
	}
}

void			addKeywordToResponse(std::string &response, std::string keyword) {
	response += ' ';
	response += keyword;
	response = eraseLineBreak(response);
	response += '\n';
}

bool            parseChannelKeyword(Server &server, std::string &channelName, std::string command, std::string &keyword, char prefix) {
    std::vector<Channel *>::iterator    it = server.findChannel(channelName);
    std::string delimiter = " ";
    std::stringstream    itoa;
    size_t        pos = 0;
    size_t        wordCount = 0;

    while ((pos = command.find(delimiter)) != std::string::npos) {
        command.erase(0, pos + delimiter.length());
        wordCount++;
    }
    command = eraseCarriageReturn(command);
    command = eraseLineBreak(command);
    if (prefix == '+') {
        if (command.size() == 0 || wordCount != 3) {
            itoa << (rand() % 1000);
            keyword = itoa.str();
            (*it)->setKeyword(keyword);
        }
        else {
            (*it)->setKeyword(command);
            keyword = command;
        }
        return (true);
    }
    else if (prefix == '-') {
        (*it)->getKeyword().clear();
        keyword.clear();
        return (false);
    }
    return (false);
}

void	displayChannelMode(Server &server, parsed *parsedCommand, int index, std::string &channelName, int8_t channelMode, char prefix) {
	std::string mode = "0";
	std::string	keyword;
	bool		displayKeyMsg = false;

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
		displayKeyMsg = parseChannelKeyword(server, channelName, parsedCommand->rawCommand, keyword, prefix);
		mode = "k";
	}
	else if (channelMode & MODE_CHANNEL_L) {
		channelMode ^= MODE_CHANNEL_L;
		mode = "l";
	}
	if (mode != "0") {
		std::string initChanelModeResponse = getCmdString(server, index, channelName, (prefix + mode), "MODE");
		if (displayKeyMsg == true)
			addKeywordToResponse(initChanelModeResponse, keyword);
		if (initChanelModeResponse.find("+l") != std::string::npos) {
			std::string suffix = ' ' + *parsedCommand->args[2];
			initChanelModeResponse.insert(initChanelModeResponse.length() - 1, suffix);
		}
		server.ssend(initChanelModeResponse, index);
		displayChannelMode(server, parsedCommand, index, channelName, channelMode, prefix);
	}
}

bool			isModeinLobby(std::string command) {
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

bool			isModeNick(Server &server, int index, std::string command, std::string &nickName) {
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, " ");
	nickName = tmp;
	nickName = eraseCarriageReturn(nickName);
	nickName = eraseLineBreak(nickName);
	nickName = eraseSelectedChar(nickName, ' ');
	if (nickName.compare(server.getNick(index)) == 0)
		return (true);
	return (false);
}

bool			isModeChannel(Server &server, std::string command, std::string &channelName) {
	char *str = const_cast<char *>(command.c_str() + command.find(" "));
	char *tmp;

	tmp = strtok(str, " ");
	channelName = tmp;
	channelName = eraseCarriageReturn(channelName);
	channelName = eraseLineBreak(channelName);
	channelName = eraseSelectedChar(channelName, ' ');
	if (server.findChannel(channelName) != server.channels.end())
		return (true);
	return (false);
}

bool			isModeOnlyNick(std::string command, std::string &userNick) {
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

bool			isModeChanges(std::string command, size_t &findLen) {
	for (size_t i = 0; command[i] != '\0'; i++) {
		if (command[i] == '+' || command[i] == '-') {
			findLen = i;
			return (true);
		}
	}
	return (false);
}

bool			isKnowUserMode(char mode, userMode &modeToAdd) {
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

bool			isKnowUserModeInChannel(char mode, channelUserMode &modeToAdd) {
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

void			changeNickMode(Server &server, std::string command, std::string &nickName, size_t findLen, int index) {
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

void			handleModeNick(Server &server, int index, std::string &command, std::string &nickName) {
	size_t findLen;

	if (isModeOnlyNick(command, server.getNick(index)) == true) {
		std::string composedNickMode = composeNickMode(server.getUsers()[index]->getUserMode());
		server.ssend(composedNickMode, index);
	}
	else if (isModeChanges(command, findLen) == true) {
		changeNickMode(server, command, nickName, findLen, index);
	}
}

bool			isModeOnlyChannel(std::string command, std::string &channelName) {
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

void			displayUserInChannelMode(Server &server, int index, std::string &nick, int8_t nickMode, char prefix) {
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
		std::string initChanelModeResponse = getCmdString(server, index, nick, (prefix + mode), "MODE");
		server.ssend(initChanelModeResponse, index);
		displayUserInChannelMode(server, index, nick, nickMode, prefix);
	}
}

bool			isUserInChannelMode(Server &server, std::string command, std::string &channelName, std::string &nickName) {
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
		return (true);
	}
	return (false);
}

void			changeUserInChannelMode(Server &server, std::string command, std::string &channelName, std::string &nickName, int index) {
	std::vector<Channel *>::iterator	it = server.findChannel(channelName);
	size_t								findLen;

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
					if (!(*(*it)->findUser(nickName))->isChannelUserModeOn(channelName, modeToAddDel)) {
						(*(*it)->findUser(nickName))->assignChannelUserMode(channelName, modeToAddDel);
						displayUserInChannelMode(server, index, nickName, modeToAddDel, prefix);
					}
				}
				else if (prefix == '-') {
					if ((*(*it)->findUser(nickName))->isChannelUserModeOn(channelName, modeToAddDel)) {
						(*(*it)->findUser(nickName))->removeChannelUserMode(channelName, modeToAddDel);
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

bool			isKnowChannelMode(char mode, channelMode &modeToAdd) {
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

size_t	isNumber(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (-1);
	}
	return (atoi(str.c_str()));
}

void	changeChannelMode(Server &server, parsed *parsedCommand, std::string &channelName, int index) {
	std::vector<Channel *>::iterator	it = server.findChannel(channelName);
	size_t	findLen;

	if (isModeChanges(parsedCommand->rawCommand, findLen) == true) {
		char 		*mode = const_cast<char *>(parsedCommand->rawCommand.c_str() + findLen);
		char		prefix;
		channelMode	modeToAddDel;

		for (int i = 0; mode[i] != '\0'; i++) {
			modeToAddDel = NO_CHANNEL_MODE;

			if (isspace(mode[i])) {
				return ;
			}
			else if (mode[i] == '+')
				prefix = '+';
			else if (mode[i] == '-')
				prefix = '-';
			else if (isKnowChannelMode((mode[i]), modeToAddDel) == true) {
				if (prefix == '+') {
					if (mode[i] == 'l') {
						if (parsedCommand->args[2]) {
							size_t limit = isNumber(*parsedCommand->args[2]);
							if (limit > 0 && limit != server.channels[server.findChannelIndex(channelName)]->getUserLimit()) {
								(*it)->setUserLimit(limit);
							}
							else {
								(*it)->setUserLimit(0);
								(*it)->removeMode(modeToAddDel);
								continue ;
							}
						}
						else
							continue ;
					}
					if (!((*it)->getChannelMode() & modeToAddDel) || mode[i] == 'l') {
						(*it)->assignMode(modeToAddDel);
						displayChannelMode(server, parsedCommand, index, channelName, modeToAddDel, prefix);
					}
				}
				else if (prefix == '-') {
					if (mode[i] == 'l')
						(*it)->setUserLimit(0);
					if ((*it)->getChannelMode() & modeToAddDel) {
						(*it)->removeMode(modeToAddDel);
						displayChannelMode(server, parsedCommand, index, channelName, modeToAddDel, prefix);
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

void	handleModeChannel(Server &server, int index, parsed *parsedCommand, std::string &channelName) {
	std::vector<Channel *>::iterator	it = server.findChannel(channelName);
	size_t								channelIndex = server.findChannelIndex(channelName);

	if (server.isChannelModeOn(static_cast<channelMode>(MODE_CHANNEL_T | MODE_CHANNEL_N), channelIndex) == false) {
		server.getUsers()[index]->assignChannelUserMode(channelName, MODE_CHANNEL_USER_O);
		(*it)->assignMode(static_cast<channelMode>(MODE_CHANNEL_T | MODE_CHANNEL_N));
		displayChannelMode(server, parsedCommand, index, channelName, (*it)->getChannelMode(), '+');
		return ;
	}
	if (isModeOnlyChannel(parsedCommand->rawCommand, channelName) == true) {
		std::string composedChannelMode = composeChannelMode((*it)->getChannelMode(), channelName);
		server.sendToMyselfInChannel(channelName, composedChannelMode, index);
	}
	else if (server.getUsers()[index]->isChannelUserModeOn(channelName, MODE_CHANNEL_USER_O) == true) {
		std::string nickName;
		if (isUserInChannelMode(server, parsedCommand->rawCommand, channelName, nickName) == true) {
			changeUserInChannelMode(server, parsedCommand->rawCommand, channelName, nickName, index);
		}
		else
			changeChannelMode(server, parsedCommand, channelName, index);
	}
	else {
		server.sendErrorServerUser(channelName.c_str(), NULL, NULL, ERR_CHANOPRIVSNEEDED, index);
	}
}

void			modeCmd(Server &server, int index, parsed *parsedCommand) {
	std::string	userName;
	std::string	channelName;

	if (isModeinLobby(parsedCommand->rawCommand) == true) {
		server.sendErrorServerUser("ircserv ", NULL, NULL, ERR_NOSUCHNICK, index);
		return ;
	}
	if (isModeNick(server, index, parsedCommand->rawCommand, userName) == true) {
		handleModeNick(server, index, parsedCommand->rawCommand, userName);
	}
	else if (isModeChannel(server, parsedCommand->rawCommand, channelName) == true) {
		handleModeChannel(server, index, parsedCommand, channelName);
	}
	else
		server.sendErrorServerUser("ircserv ", NULL, NULL, ERR_NOSUCHNICK, index);
}