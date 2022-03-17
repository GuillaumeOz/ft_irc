#include "ft_irc.hpp"

std::vector<std::string> 		split(std::string string, std::string seperators)	{
	size_t i = 0, startIndex = 0, endIndex = 0;
	std::vector<std::string> splittedString;

	while (i < string.length()) {
		if ((seperators.find(string[i]) != std::string::npos && seperators.find(string[i + 1]) == std::string::npos) || i == string.length() - 1) {
			endIndex = i;
			std::string subStr = "";
			subStr.append(string, startIndex, endIndex - startIndex);
			splittedString.push_back(subStr);
			startIndex = endIndex + 1;
		}
		i++;
	}
	return (splittedString);
}

parsed							*getParsedCommandLine(std::string &commandLine) {
	parsed *parsedCommand = new parsed();
	std::string seperators = " ,";
	std::vector<std::string> splittedCommand = split(commandLine, seperators);

	if (splittedCommand.size() > 0) {
		parsedCommand->addCommand(splittedCommand[0].c_str());

		for (size_t i = 1; i < splittedCommand.size(); i++) {
			parsedCommand->addArgs(splittedCommand[i].c_str());
		}
	}
	return (parsedCommand);
}

void							parseCommands(std::vector<parsed *> &parsedCommands, std::string string) {
	std::string seperators = "\r\n";
	std::vector<std::string> splittedCommand = split(string, seperators);

	for(size_t i = 0; i < splittedCommand.size(); i++) {
		parsedCommands.push_back(getParsedCommandLine(splittedCommand[i]));
		parsedCommands.back()->addRawString(splittedCommand[i]);
	}
}
