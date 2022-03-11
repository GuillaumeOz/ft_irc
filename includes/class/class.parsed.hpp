#ifndef CLASS_PARSED_HPP
# define CLASS_PARSED_HPP

class parsed
{

	public:

/* ---------------------------------- data ---------------------------------- */

		std::string					command;
		std::vector<std::string *>	args;
		std::vector<std::string *>	channels;
		std::vector<std::string *>	twoPointsArgs;
		std::string					rawCommand;

/* ------------------------ constructors/destructors ------------------------ */

		parsed();
		~parsed();

/* --------------------------------- setters -------------------------------- */

		void	addCommand(const char *);
		void	addArgs(const char *);
		void	addArgChannel(std::string *);
		void	addArgTwoPoints(std::string *);
		void	addRawString(std::string &);

/* ---------------------------- delete/deallocate --------------------------- */

		void	clear();
};

#endif
