#ifndef CLASS_CONFIG_HPP
# define CLASS_CONFIG_HPP

class Config {

    public:

/* ---------------------------------- data ---------------------------------- */

	int						sock;
	struct sockaddr_in 		addr;

/* ------------------------ constructors/destructors ------------------------ */

	Config(int);
	~Config();

};


#endif
