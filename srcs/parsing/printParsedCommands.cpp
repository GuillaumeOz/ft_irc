#include "ft_irc.hpp"

void	printParsedCommandsArgs(parsed *parsedCommands) {
	for (size_t i = 0; i < parsedCommands->args.size(); i++) {
		POUT(parsedCommands->args[i]->c_str())
	}
	if (parsedCommands->args.size() == 0)
		POUT("-")
}

void	printParsedCommandsTwoPoints(parsed *parsedCommands) {
	for (size_t i = 0; i < parsedCommands->twoPointsArgs.size(); i++) {
		POUT(parsedCommands->twoPointsArgs[i]->c_str())
	}
	if (parsedCommands->twoPointsArgs.size() == 0)
		POUT("-")
}

void	printParsedCommandschannels(parsed *parsedCommands) {
	for (size_t i = 0; i < parsedCommands->channels.size(); i++) {
		POUT(parsedCommands->channels[i]->c_str())
	}
	if (parsedCommands->channels.size() == 0)
		POUT("-")
}

void	printParsedCommand(parsed *parsedCommand) {
	POUT("Raw string : ")
	POUT(parsedCommand->rawCommand.c_str())
	POUT("Command : ")
	POUT(parsedCommand->command.c_str())
	POUT("Args : ")
	printParsedCommandsArgs(parsedCommand);
	POUT("Channels : ")
	printParsedCommandschannels(parsedCommand);
	POUT("Two points args : ")
	printParsedCommandsTwoPoints(parsedCommand);
	POUT("\n")
}

void	printParsedCommands(std::vector<parsed *> &parsedCommands) {
	for (size_t i = 0; i < parsedCommands.size(); i++) {
		std::cout << "line : " << std::flush;
		POUT(i)
		printParsedCommand(parsedCommands[i]);
	}
}
