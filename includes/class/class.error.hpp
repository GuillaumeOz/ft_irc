#ifndef CLASS_ERROR_HPP
# define CLASS_ERROR_HPP

class User;

enum errorType {
	ARGUMENT,
    UNAVAILABLE_PORT,
	ERR_NOSUCHNICK,
	ERR_NOSUCHSERVER,
	ERR_NOSUCHCHANNEL,
	ERR_CANNOTSENDTOCHAN,
	ERR_TOOMANYCHANNELS,
	ERR_RESTRICTED,
	ERR_CHANNELISFULL,
	ERR_UNKNOWNMODE,
	ERR_INVITEONLYCHAN,
	ERR_NEEDMOREPARAMS,
	ERR_NICKNAMEINUSE,
	ERR_BANNEDFROMCHAN,
	ERR_BADCHANNELKEY,
	ERR_BADCHANMASK,
	ERR_NOCHANMODES,
	ERR_BANLISTFULL,
	ERR_NOPRIVILEGES,
	ERR_CHANOPRIVSNEEDED,
	ERR_CANTKILLSERVER,
	ERR_UNIQOPPRIVSNEEDED,
	ERR_NOOPERHOST,
	ERR_UMODEUNKNOWNFLAG,
	ERR_USERSDONTMATCH,
	NO_ERROR,
	ERR_KEYSET,
	ERR_YOUREBANNEDCREEP,
	ERR_PASSWDMISMATCH,
	ERR_NOPERMFORHOST,
	ERR_ALREADYREGISTRED,
	ERR_NOTREGISTERED,
	ERR_USERSDISABLED,
	ERR_SUMMONDISABLED,
	ERR_NOLOGIN,
	ERR_NICKCOLLISION,
	ERR_USERONCHANNEL,
	ERR_UNAVAILRESOURCE,
	ERR_NOTONCHANNEL,
	ERR_USERNOTINCHANNEL,
	ERR_ERRONEUSNICKNAME
};

class Error {

    public:

/* ---------------------------------- data ---------------------------------- */

	errorType							type;
	std::map<errorType, std::string> 	errorMessages;

/* ------------------------ constructors/destructors ------------------------ */

	Error();
	Error(Error &);
	~Error();

/* ----------------------------- getters/setters ---------------------------- */

	void					setErrorType(errorType &);
	std::string				getMessageWithReplaceToken(const char *, const char *, const char *, errorType &);

/* ----------------------- printing/sending functions ----------------------- */

	void					displayError();
	void					sendError(std::string , errorType());
	void					sendErrorServer(const char *, const char *, const char *, errorType &);
	void					sendErrorUser(const char *, const char *, const char *, errorType &, User *);
	void					sendErrorServerUser(const char *, const char *, const char *, errorType &, User *);
};

#endif
