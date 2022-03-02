#ifndef CLASS_CHANNEL_HPP
#define CLASS_CHANNEL_HPP

class User;

class Channel {

	private:
		std::vector<User *>     _users;
		std::vector<User *>     _operators;
		std::string             _name;
		std::string             _topic;
		int8_t					_channelMode;

	public:
		Channel(std::string &name, std::string &topic, User *first);
		~Channel();

		std::string						&getChannelName();
		std::string						&getChannelTopic();
		size_t							getNumberofUsers();
		std::vector<User *>::iterator	findUser(std::string &name);
		void							addUser(User *user);
		void							removeUser(User *);
		void							sendToAllUsers(std::string &response);
		void							sendToAllOtherUsers(std::string &response, int socket);
		bool							isEmpty();
		bool							isModeOn(channelMode);
		void							assignMode(channelMode);
		// bool							isInChannel(std::string &);
};

#endif
