#! /bin/bash

ac=$#
bot_var="bot"

echo "Hi $(whoami)!

if you got some problem with the bot start command please check your defualt x-termainal-emulator.

You can change it by using the command:  [sudo update-alternatives --config x-terminal-emulator].
"

if [ $ac -eq 2 ]
then
	make
	./bin/ircserv $1 $2
elif [ $ac -eq 3 ]
then
	if [ "$3" = "bot" ]
	then
		make ; cd ./bot && make; cd ../
		x-terminal-emulator -T "Server IRC" -e bash -c " ./bin/ircserv $1 $2 | cat - e" &
		sleep 2
		x-terminal-emulator -T "Bot Irc" -e bash -c " cd ./bot; ./bin/bot_client $2"
	else
		echo "Wrong arguments... Try with ./script.sh [server port] [password] [bot]"
	fi
else
	echo "Wrong number of arguments... Try with ./script.sh [server port] [password] optional: [bot]"
fi
