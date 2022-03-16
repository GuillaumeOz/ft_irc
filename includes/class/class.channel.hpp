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
		Channel(std::string &name, std::string &topic, User *first);
		~Channel();

		std::string						&getChannelName();
		std::string						&getChannelTopic();
		size_t							getNumberofUsers();
		int8_t							getChannelMode();
		std::vector<User *>				getUsers();
		std::vector<User *>::iterator	getUsersEnd();
		std::string						&getKeyword();
		void							setKeyword(std::string newKeyword);
		void							setChannelTopic(std::string newTopic);
		std::vector<User *>::iterator	findUser(std::string &name);
		void							addUser(User *user);
		void							removeUser(User *);
		void							sendToAllUsers(std::string &response);
		void							sendToAllOtherUsers(std::string &response, int socket);
		void							sendToMyself(std::string &response, int socket);
		bool							isEmpty();
		bool							isModeOn(channelMode);
		void							assignMode(channelMode);
		void							removeMode(channelMode);
		void							setUserLimit(int);
		size_t								getUserLimit();
		// bool							isInChannel(std::string &);
};

#endif
