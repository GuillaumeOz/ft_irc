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
		x-terminal-emulator -T "Server IRC" -e bash -c "make; ./bin/ircserv $1 $2" &
		sleep 7
		x-terminal-emulator -T "Bot Irc" -e bash -c "cd ./bot && make; ./bin/bot_client"
	else
		echo "Wrong arguments... Try with ./script.sh [server port] [password] [bot]"
	fi
else
	echo "Wrong number of arguments... Try with ./script.sh [server port] [password] optional: [bot]"
fi
