#include "ft_irc.hpp"

// recv(buf)
// parse(buf)
// if (command == part)
// 	partcmd(name, channel, server)

// void	partCmd(Server &server, User *user, std::string &string) {
// 	std::vector<Channel *>::iterator	channel = server.findChannel(string);
// 	int	index = (*channel)->findUser(user->getNick());
// 	if (channel == server.channel.end())
// 		PERR("Channel not in server");
// 	if (index == -1)
// 		PERR("User not in channel");
// 	if ((*channel)->findUser(user->getNick())) {
// 		(*channel)->removeUser();
// 		user->leaveChannel(string);
// 	}
// }

// int channel_in_server = server->findChannel(channel);
// int user_in_channel = server->_channels[channel_in_server].findUser(user);
// int channel_in_user = server->getChannels()[channel_in_server].[user_in_channel].findChannel(channel);

// server->getChannels()[channel_in_server].getUsers()
// server->_user[channel_in_user]
// server->_channel[channel_in_server]


// Server
// 	channel1
// 		users
// 	channel2
// 		users - 1
// 			channels
