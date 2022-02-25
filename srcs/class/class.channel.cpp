#include "ft_irc.hpp"

Channel::Channel(std::string &name, std::string &topic, User *first) : _name(name), _topic(topic) {
    _users.push_back(first);
}

Channel::~Channel() {}

std::string   &Channel::getChannelName() {
    return _name;
}

std::string   &Channel::getChannelTopic() {
    return _topic;
}

// int Channel::findUser(std::string &name) {
//     for (int i = 0; i < _users.size(); i++) {
//         if (_users[i].getNick() == name)
//             return (i);
//     }
//     return (-1);
// }

std::vector<User *>::iterator Channel::findUser(std::string &name) {
    for (std::vector<User *>::iterator it = _users.begin(); it != _users.end(); it++) {
        if ((*it)->getNick() == name)
            return (it);
    }
    return (_users.end());
}

void                Channel::addUser(User *user) {
    _users.push_back(user);
}

void                Channel::removeUser(int index) {
    _users.erase(_users.begin() + index);
}

// int                Channel::isInChannel(std::string &user) {
//     if (findUser(user) == _users.end())
//         return (false);
//     return (true);
// }

