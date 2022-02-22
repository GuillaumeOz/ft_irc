#ifndef CLASS_ERROR_HPP
# define CLASS_ERROR_HPP

enum errorType {
	ARGUMENT,
    UNAVAILABLE_PORT,
	NO_ERROR
};

class Error {

    public:
	errorType	type;
	std::map<errorType, std::string> errorMessages;

	Error();
	Error(Error &);
	~Error();

	void	displayError();
	void	setErrorType(errorType &);
	
};


#endif
