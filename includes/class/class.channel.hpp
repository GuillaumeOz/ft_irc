#ifndef CLASS_CHANNEL_HPP
#define CLASS_CHANNEL_HPP

class User;

class Channel {

	private:
		std::vector<User *>     _users;
		std::vector<User *>     _operators;
		std::string             _name;
		std::string             _topic;
		std::string             _keyword;
		int8_t					_channelMode;
		size_t						_userLimit;

	public:

/* ------------------------- constructors/destructos ------------------------ */
		
		Channel(std::string &, std::string &, User *);
		~Channel();

/* --------------------------------- getters -------------------------------- */

		std::string						&getChannelName();
		std::string						&getChannelTopic();
		size_t							getNumberofUsers();
		int8_t							getChannelMode();
		std::vector<User *>				getUsers();
		std::vector<User *>::iterator	getUsersEnd();
		std::string						&getKeyword();
		std::vector<User *>::iterator	findUser(std::string &);

/* --------------------------------- setters -------------------------------- */

		void							setKeyword(std::string);
		void							setChannelTopic(std::string);

/* ---------------------------- user manipulation --------------------------- */

		void							addUser(User *);
		void							removeUser(User *);
		void							assignMode(channelMode);
		void							removeMode(channelMode);
		void							setUserLimit(int);
		size_t							getUserLimit();

/* ---------------------------- sending functions --------------------------- */

		void							sendToAllUsers(std::string &);
		void							sendToAllOtherUsers(std::string &, int );
		void							sendToMyself(std::string &, int );

/* ---------------------------- checker functions --------------------------- */

		bool							isEmpty();
		bool							isModeOn(channelMode);

};

#endif
