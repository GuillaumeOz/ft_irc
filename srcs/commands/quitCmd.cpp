#include "ft_irc.hpp"

// void	Server::delChannelFromUser(std::string &channelName, int index) {
// 	_users[index]->leaveChannel(channelName);
// };

// void	Server::delUserFromChannel(std::string &channelName, int index) {
// 	for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); it++) {
// 		if ((*it)->getChannelName() == channelName)
// 			(*it)->removeUser(_users[index]);
// 	}
// };

std::string getLeaveReason(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":"), command.end());
	return (tmp);
}

std::string		getLeaveResponse(Server &server, int index, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length() - 1, "!test");
	str.insert(str.length() - 1, " QUIT ");
	str.insert(str.length() - 1, reason.c_str());
	str.insert(str.length() - 1, "\n");
    return (str);
}

	// private:
	// int								_sock;
	// sockaddr_in						_addr;
	// socklen_t						_csize;
	// std::string						_username;
	// std::string						_nick;
	// std::vector<std::string>		_uchannels;
	// int8_t							_userMode;
	// std::map<std::string, int8_t>	_channelUserMode;

// :syrk!kalt@millennium.stealth.net QUIT :Gone to have lunch ;
void	quitCmd(Server &server, int index, std::string &command) {

	std::string reason = getLeaveReason(command);
	std::string response = getLeaveResponse(server, index, reason);
	// User	user = server.getUsers()[index];
	// std::vector<User *>	users = server.getUsers();
	std::vector<std::string> uchannel = server.getUsers()[index]->getUchannels();

	server.ssend(response, index);
	for (size_t i = 0; i < uchannel.size(); i++) {

		server.delUserFromChannel(uchannel[0], index);
	}
	// server.delChannelFromUser();
	server.closeUser(index);
}
