#include "ft_irc.hpp"

Error::Error(): type(NO_ERROR) {
	errorMessages[ARGUMENT] = "Error: invalid number of arguments.";
	errorMessages[UNAVAILABLE_PORT] = "Error: port is already assigned.";
};

Error::Error(Error &instance) {
	this->errorMessages = instance.errorMessages;
	this->type = instance.type;
}

Error::~Error() {}

void Error::displayError() {
	if (type != NO_ERROR) {

	    PERR(errorMessages[type]);
		exit(EXIT_FAILURE);
    }
}

void Error::setErrorType(errorType &value) {
	type = value;
}
