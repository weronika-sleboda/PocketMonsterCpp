#ifndef ERROR_SCREEN_H
#define ERROR_SCREEN_H

#include "Screen.h"

enum class ErrorType 
{

	UNDEFINED,
	WRONG_INPUT,
	PROFILE_NOT_DONE

};

class ErrorScreen : public Screen 
{

public:

	void display() const override;
	void setErrorType(ErrorType occurrentError);

private:

	ErrorType errorType = ErrorType::UNDEFINED;

};

#endif