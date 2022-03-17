#ifndef CLASS_SERVER_HPP
# define CLASS_SERVER_HPP

class User;

class Server {

	private:

/* ------------------------------ private data ------------------------------ */

	Config															_config;
	Error															_error;
	std::string														_pass;
	std::vector<struct pollfd>										_pfds;
	std::string														_password;
	std::vector<User *>												_users;
	std::map<std::string, void (*)(Server &, int , parsed *)> 		_commands;
	bool															_loop;

	public:

/* ------------------------------- public data ------------------------------ */

	std::vector<Channel *>											channels;

/* ------------------------ constructors/destructors ------------------------ */

	Server(int);
	Server(int, Error, std::string);
	~Server();

/* ----------------------------- server password ---------------------------- */

	void 						printPass();
	bool 						isValidPass(std::string &);
	bool 						isRegistered(int);
	void 						sregister(int);
	void 						setLoop(bool);
	bool 						getLoop();

/* ------------------------------- commands -------------------------------- */

	void 						initCommands();
	void 						callCommand(Server &, int &, parsed *);

/* ---------------------------- socket handling ---------------------------- */

	void 						sbind();
	void 						slisten(int);
	void 						saccept();
	void 						ssend(std::string &, int);
	void 						ssend(std::string &, User &);
	int  						srecv(std::string *, int);
	void 						spoll();
	bool 						spollinCondition(int &);
	bool 						spolloutCondition(int &);

/* ---------------------------- error handling ----------------------------- */

	void 						sendErrorServer(const char *, const char *, const char *, errorType);
	void 						sendErrorUser(const char *, const char *, const char *, errorType, int);
	void 						sendErrorServerUser(const char *, const char *, const char *, errorType, int);

/* ------------------------------ user getters ------------------------------ */

	std::vector<User *>			getUsers();
	std::string					&getHost(int);
	std::string					&getNick(int);
	std::string					&getUsername(int);
	std::string					&getRealname(int);
	std::string 				&getUserAwayMessage(int);
	std::string 				&getUserInvalidNick(int);
	int 						findUserIndex(std::string &);
	int							userCount();
	bool 						isUserModeOn(userMode, int);
	bool 						isChannelUserModeOn(int, std::string &, channelUserMode);

/* ------------------------------ user setters ------------------------------ */

	void 						setHost(int , std::string &);
	void 						setNick(int , std::string &);
	void 						setUsername(int , std::string &);
	void 						setRealname(int , std::string &);
	void 						assignUserMode(userMode, int);
	void						setUserInvalidNick(int, std::string &);
	void 						setUserAwayMessage(int, std::string &);

/* ---------------------------- user manipulation --------------------------- */

	void 						addUser(User *);
	void 						removeUser(int &);
	void 						delChannelFromUser(std::string &, int);



/* ----------------------------- channel getters ---------------------------- */

	std::vector<Channel *>				getChannels();
	std::string 						getChannelModes(int);
	std::vector<Channel *>::iterator 	findChannel(std::string &);
	size_t								findChannelIndex(std::string &);
	bool 								isExistingChannel(std::string &);
	bool 								isChannelEmpty(std::string &);
	bool 								isChannelModeOn(channelMode, int);
	bool 								isUserInChannel(std::string &, int);

/* -------------------------- channel manipulation -------------------------- */

	void 								addChannel(std::string &, std::string &, int);
	void 								addChannelToUser(int, std::string );
	void 								joinChannel(int, std::string &);
	void 								assignChannelMode(channelMode, int);
	void 								removeChannel(int &);
	void 								delUserFromChannel(std::string &, int);
	void 								delChannel(std::string &);

/* ------------------------ channel sending/printing ------------------------ */

	void 								sendToAllUsersInChannel(std::string &, std::string &);
	void 								sendToOtherUsersInChannel(std::string &, std::string &, int);
	void 								sendToMyselfInChannel(std::string &, std::string &, int);
	void 								printChannels();

/* ---------------------------- pfds manipulation --------------------------- */

	void 								addSockToPfds(int);
	void 								removeSockFromPfds(int);
	int	 								findClientSock(int);
	int	 								getPfdsSize();
	int	 								getPfdsSock(int &);

/* ---------------------------- closing functions --------------------------- */

	void 								closeServer();
	void 								closeUser(int);
};


#endif
