#include "ft_irc.hpp"

Error::Error(): type(NO_ERROR) {
	errorMessages[ARGUMENT] = "Error: invalid number of arguments.";
	errorMessages[UNAVAILABLE_PORT] = "Error: port is already assigned.";

	errorMessages[ERR_NOSUCHNICK] = "place1 :No such nick/channel";
	errorMessages[ERR_NOSUCHSERVER] = "place1 :No such server";
	errorMessages[ERR_NOSUCHCHANNEL] = "place1 :No such channel";
	errorMessages[ERR_CANNOTSENDTOCHAN] = "place1 :Cannot send to channel";
	errorMessages[ERR_TOOMANYCHANNELS] = "place1 :You have joined too many channels";
	errorMessages[ERR_NEEDMOREPARAMS] = "place1 :Not enough parameter";
	errorMessages[ERR_NICKNAMEINUSE] = "place1 :Nickname is already in use";
	errorMessages[ERR_RESTRICTED] = ":Your connection is restricted!";
	errorMessages[ERR_CHANNELISFULL] = "place1 :Cannot join channel (+l)";
	errorMessages[ERR_UNKNOWNMODE] = "place1 :is unknown mode char to me for place2";
	errorMessages[ERR_INVITEONLYCHAN] = "place1 :Cannot join channel (+i)";
	errorMessages[ERR_BANNEDFROMCHAN] = "place1 :Cannot join channel (+b)";
	errorMessages[ERR_BADCHANNELKEY] = "place1 :Cannot join channel (+k)";
	errorMessages[ERR_BADCHANMASK] = "place1 :Bad Channel Mask";
	errorMessages[ERR_NOCHANMODES] = "place1 :Channel doesn't support modes";
	errorMessages[ERR_BANLISTFULL] = "place1 place2 :Channel list is full";
	errorMessages[ERR_NOPRIVILEGES] = ":Permission Denied- You're not an IRC operator";
	errorMessages[ERR_CHANOPRIVSNEEDED] = "place1 :You're not channel operator";
	errorMessages[ERR_CANTKILLSERVER] = ":You can't kill a server!";
	errorMessages[ERR_UNIQOPPRIVSNEEDED] = ":You're not the original channel operator";
	errorMessages[ERR_NOOPERHOST] = ":No O-lines for your host";
	errorMessages[ERR_UMODEUNKNOWNFLAG] = ":Unknown MODE flag";
	errorMessages[ERR_USERSDONTMATCH] = ":Cannot change mode for other users";
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

void	Error::sendError(const char *arg1, const char *arg2, const char *arg3, errorType &value, User *user) {
	std::string	message;

	message = getMessageWithReplaceToken(arg1, arg2, arg3, value);
	POUT("Error sent: ")
	POUT(message);
	POUT("USer nick:")
	POUT(user->getNick())
	user->usend(message);
};

