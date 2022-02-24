#ifndef CLASS_CHANNEL_HPP
#define CLASS_CHANNEL_HPP

class User;

class Channel {

	private:
		std::vector<User *>     _users;
        std::vector<User *>     _operators;
        std::string             _name;
        std::string             _topic;

	public:
		Channel(std::string &name, std::string &topic, User *first);
		~Channel();

        const std::string   &getChannelName() const;
        const std::string   &getChannelTopic() const;
        std::vector<User *>::iterator findUser(std::string &name);
        void                joinChannel(User *user);
        void                leaveChannel(int index);
};

#endif