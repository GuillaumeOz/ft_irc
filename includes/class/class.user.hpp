#ifndef CLASS_USER_HPP
#define CLASS_USER_HPP

class Server;

class User {

	private:
	int								_sock;
	sockaddr_in						_addr;
	socklen_t						_csize;
	std::string						_username;
	std::string						_nick;
	std::vector<std::string>		_uchannels;
	int8_t							_userMode;
	std::map<std::string, int8_t>	_channelUserMode;

	public:
	User();
	User(std::string &username, std::string &nick);
	~User();
	void						uaccept(int &);
	void						usend(std::string &);
	void						uclose();
	int							urecv(std::string *);
	void						setSocket(int &);
	int							getSocket();
	std::vector<std::string>	getUchannels();
	void						setNick(std::string &);
	void						leaveChannel(std::string &);
	std::string					&getNick();
	std::string 				&getUsername();
	void						joinChannel(std::string &channelName);
	void						assignMode(userMode);
	bool						isModeOn(userMode);
	bool						isChannelUserModeOn(std::string &, channelUserMode);
	void						assignChannelUserMode(std::string &, channelUserMode);

};

#endif
