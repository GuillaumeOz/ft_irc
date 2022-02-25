#ifndef CLASS_CONFIG_HPP
# define CLASS_CONFIG_HPP

class Config {

    public:

	int					sock;
	struct sockaddr_in 	addr;

	Config(int port);
	~Config();

};


#endif
