#ifndef CLASS_USER_HPP
#define CLASS_USER_HPP

class Server;

class User {

	private:

/* ---------------------------------- data ---------------------------------- */

	int									_sock;
	bool								_registerState;
	sockaddr_in							_addr;
	socklen_t							_csize;
	std::string							_host;
	std::string							_nick;
	std::string							_username;
	std::string							_realname;
	std::string							_awaymessage;
	std::string							_invalidNick;
	std::vector<std::string>			_uchannels;
	std::map<std::string, int8_t>		_channelUserMode;
	int8_t								_userMode;

	public:

/* ------------------------ constructors/destructors ------------------------ */

	User();
	User(std::string &, std::string &);
	~User();

/* --------------------------------- getters -------------------------------- */

	std::vector<std::string>	getUchannels();
	std::string					&getHost();
	std::string					&getNick();
	std::string 				&getUsername();
	std::string 				&getRealname();
	std::string					&getAwayMessage();
	std::string					&getInvalidNick();
	int							getSocket();

/* --------------------------------- setters -------------------------------- */

	void						setSocket(int &);
	void						setHost(std::string &);
	void						setNick(std::string &);
	void						setUsername(std::string &);
	void						setRealname(std::string &);
	void						setAwayMessage(std::string &);
	void						setInvalidNick(std::string &);

/* --------------------------- socket manipulation -------------------------- */

	void						uaccept(int &);
	void						usend(std::string &);
	void						uclose();
	int							urecv(std::string *);

/* ---------------------------- user manipulation --------------------------- */

	bool 						isRegistered();
	void 						uregister();
	void						leaveChannel(std::string &);
	void						joinChannel(std::string &);

/* ---------------------------------- modes --------------------------------- */

	void						assignMode(userMode);
	void						assignChannelUserMode(std::string &, channelUserMode);
	void						removeMode(userMode);
	void						removeChannelUserMode(std::string &, channelUserMode);
	bool						isModeOn(userMode);
	bool						isChannelUserModeOn(std::string &, channelUserMode);
	int8_t						getUserMode();

};

#endif
