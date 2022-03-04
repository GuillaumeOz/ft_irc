#include "ft_irc.hpp"

Error::Error(): type(NO_ERROR) {
	errorMessages[ARGUMENT] = "Error: invalid number of arguments.\n";
	errorMessages[UNAVAILABLE_PORT] = "Error: port is already assigned.\n";

	errorMessages[ERR_NOSUCHNICK] = "place1 :No such nick/channel.\n";
	errorMessages[ERR_NOSUCHSERVER] = "place1 :No such server.\n";
	errorMessages[ERR_NOSUCHCHANNEL] = "place1 :No such channel.\n";
	errorMessages[ERR_CANNOTSENDTOCHAN] = "place1 :Cannot send to channel.\n";
	errorMessages[ERR_TOOMANYCHANNELS] = "place1 :You have joined too many channels.\n";
	errorMessages[ERR_NEEDMOREPARAMS] = "place1 :Not enough parameter.\n";
	errorMessages[ERR_NICKNAMEINUSE] = "place1 :Nickname is already in use.\n";
	errorMessages[ERR_RESTRICTED] = ":Your connection is restricted!.\n";
	errorMessages[ERR_CHANNELISFULL] = "place1 :Cannot join channel (+l).\n";
	errorMessages[ERR_UNKNOWNMODE] = "place1 :is unknown mode char to me for place2.\n";
	errorMessages[ERR_INVITEONLYCHAN] = "place1 :Cannot join channel (+i).\n";
	errorMessages[ERR_BANNEDFROMCHAN] = "place1 :Cannot join channel (+b).\n";
	errorMessages[ERR_BADCHANNELKEY] = "place1 :Cannot join channel (+k).\n";
	errorMessages[ERR_BADCHANMASK] = "place1 :Bad Channel Mask.\n";
	errorMessages[ERR_NOCHANMODES] = "place1 :Channel doesn't support modes.\n";
	errorMessages[ERR_BANLISTFULL] = "place1 place2 :Channel list is full.\n";
	errorMessages[ERR_NOPRIVILEGES] = ":Permission Denied- You're not an IRC operator.\n";
	errorMessages[ERR_CHANOPRIVSNEEDED] = "place1 :You're not channel operator.\n";
	errorMessages[ERR_CANTKILLSERVER] = ":You can't kill a server!.\n";
	errorMessages[ERR_UNIQOPPRIVSNEEDED] = ":You're not the original channel operator.\n";
	errorMessages[ERR_NOOPERHOST] = ":No O-lines for your host.\n";
	errorMessages[ERR_UMODEUNKNOWNFLAG] = ":Unknown MODE flag.\n";
	errorMessages[ERR_USERSDONTMATCH] = ":Cannot change mode for other users.\n";
	errorMessages[ERR_NICKCOLLISION] = "place1 :Nickname collision KILL from place2@place3.\n";
	errorMessages[ERR_UNAVAILRESOURCE] = "place1 :Nick/channel is temporarily unavailable.\n";
	errorMessages[ERR_USERNOTINCHANNEL] = "place1 place2 :They aren't on that channel.\n";
	errorMessages[ERR_NOTONCHANNEL] = "place1 :You're not on that channel.\n";
	errorMessages[ERR_USERONCHANNEL] = "place1 place2 :is already on channel.\n";
	errorMessages[ERR_NOLOGIN] = "place1 :User not logged in.\n";
	errorMessages[ERR_SUMMONDISABLED] = ":SUMMON has been disabled.\n";
	errorMessages[ERR_USERSDISABLED] = ":USERS has been disabled.\n";
	errorMessages[ERR_NOTREGISTERED] = ":You have not registered.\n";
	errorMessages[ERR_ALREADYREGISTRED] = ":Unauthorized command (already registered).\n";
	errorMessages[ERR_NOPERMFORHOST] = ":Your host isn't among the privileged.\n";
	errorMessages[ERR_PASSWDMISMATCH] = ":Password incorrect.\n";
	errorMessages[ERR_YOUREBANNEDCREEP] = ":You are banned from this server.\n";
	errorMessages[ERR_KEYSET] = "place1 :Channel key already set.\n";
	errorMessages[ERR_ERRONEUSNICKNAME] = "place1 :Erroneous nickname\n";
};

Error::Error(Error &instance) {
	this->errorMessages = instance.errorMessages;
	this->type = instance.type;
};

Error::~Error() {};

void Error::displayError() {
	if (type != NO_ERROR) {

		PERR(errorMessages[type]);
		exit(EXIT_FAILURE);
	}
};

void	Error::setErrorType(errorType &value) {
	type = value;
};

std::string	Error::getMessageWithReplaceToken(const char *arg1, const char *arg2, const char *arg3, errorType &value) {
	std::string tmp = errorMessages.find(value)->second;
	if (arg1 != NULL)
		tmp.replace(tmp.find("place1"), 6, arg1);
	if (arg2 != NULL)
		tmp.replace(tmp.find("place2"), 6, arg2);
	if (arg3 != NULL)
		tmp.replace(tmp.find("place3"), 6, arg3);
	return (tmp);
};

void	Error::sendErrorServer(const char *arg1, const char *arg2, const char *arg3, errorType &value) {
	std::string	message;

	message = getMessageWithReplaceToken(arg1, arg2, arg3, value);
	PERR(message)
};

void	Error::sendErrorUser(const char *arg1, const char *arg2, const char *arg3, errorType &value, User *user) {
	std::string	message;

	message = getMessageWithReplaceToken(arg1, arg2, arg3, value);
	user->usend(message);
};

void	Error::sendErrorServerUser(const char *arg1, const char *arg2, const char *arg3, errorType &value, User *user) {
	std::string	message;

	message = getMessageWithReplaceToken(arg1, arg2, arg3, value);
	user->usend(message);
	PERR(message)
};
