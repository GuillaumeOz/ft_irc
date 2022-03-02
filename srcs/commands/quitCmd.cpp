#include "ft_irc.hpp"

std::string getLeaveReason(std::string &command) {
	std::string tmp;

	tmp.insert(tmp.begin(), command.begin() + command.find_first_of(":"), command.end());
	return (tmp);
}

std::string		getLeaveResponse(Server &server, int index, std::string &channelName, std::string &reason) {
	std::string str;

	str.insert(0, ":");
	str.insert(1, server.getNick(index).c_str());
	str.insert(str.length(), "!test");//test here ?
	str.insert(str.length(), " PRIVMSG ");
	str.insert(str.length(), channelName.c_str());
	str.insert(str.length(), " ");
	str.insert(str.length(), "has left the channel for the reason: ");
	str.insert(str.length(), reason.c_str());
	str.insert(str.length(), "\n");
    return (str);
}

void	quitCmd(Server &server, int index, std::string &command) {

	std::string reason = getLeaveReason(command);
	std::vector<std::string> uchannel = server.getUsers()[index]->getUchannels();

	for (size_t i = 0; i < uchannel.size(); i++) {
		std::string response = getLeaveResponse(server, index, uchannel[i], reason);
		server.sendToAllUsersInChannel(uchannel[i], response);
		server.delUserFromChannel(uchannel[i], index);
		if (server.isChannelEmpty(uchannel[i]) == true)
            server.delChannel(uchannel[i]);
	}
	server.closeUser(index);
}
