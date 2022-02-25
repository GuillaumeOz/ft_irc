#include "ft_irc.hpp"

// recv(buf)
// parse(buf)
// if (command == part)
// 	partcmd(name, channel, server)

// void	partCmd(std::string user, std::string channel, Server *server) {
	
	
	// int channel_in_server = server->findChannel(channel);
	// int user_in_channel = server->_channels[channel_in_server].findUser(user);
	// int channel_in_user = server->getChannels()[channel_in_server].[user_in_channel].findChannel(channel);

	// server->getChannels()[channel_in_server].getUsers()
	// server->_user[channel_in_user]
	// server->_channel[channel_in_server]
// }

// void	commandPART(user, name) {
// 	int index = findChannel(name);
// 	if (_channels[index].findUser(user)) {
// 		if (_channels[index].size() == 1) {
// 			removeChannel(index))
// 		}
// 	}
// }


// Server
// 	channel1
// 		users
// 	channel2
// 		users - 1
// 			channels