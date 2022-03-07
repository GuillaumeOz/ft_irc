#include "bot.hpp"

std::string	eraseCarriageReturn(std::string &string) {
	while (string.find("\r") != std::string::npos)
		string.erase(string.begin() + string.find("\r"));
	size_t n = string.find("\n");
	if (n != std::string::npos)
		string.erase(string.begin() + n, string.end());
	return (string);
}

std::string	getMsg(std::string &string) {
	size_t i = string.find("PRIVMSG");

	if (i != std::string::npos) {
		std::string tmp = string.c_str() + i;
		size_t		j = tmp.find(":");

		if (j != std::string::npos) {
			tmp = tmp.c_str() + j + 1;
			return (tmp);
		}
	}
	return (string);
}

std::string getCommand(std::string &string) {
    std::string		msg = getMsg(string);

    if (msg.compare(string) == 0) {
        std::cout << "Not a PRIVMSG, ignoring it." << std::endl;
        return (msg);
    }
    return (msg);
}
