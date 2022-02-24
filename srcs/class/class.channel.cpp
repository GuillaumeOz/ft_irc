#include "ft_irc.hpp"

Channel::Channel(std::string &name, std::string &topic, User *first) : _name(name), _topic(topic) {
    _users.push_back(first);
}

Channel::~Channel() {}

const std::string   &Channel::getChannelName() const {
    return _name;
}

const std::string   &Channel::getChannelTopic() const {
    return _topic;
}

std::vector<User *>::iterator Channel::findUser(std::string &name) {
    for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); it++) {
        if ((*it)->getNick() == name)
            return (it);
    }
    return (_users.end());
}

void                Channel::joinChannel(User *user) {
    _users.push_back(user);
}

void                Channel::leaveChannel(int index) {
    _users.erase(_users.begin() + index);
}