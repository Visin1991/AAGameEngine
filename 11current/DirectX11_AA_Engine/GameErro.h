#pragma once

#include <string>
//Game Error class.Thrown when an error is detected by the game engine.
//Inherits for std::exception
class GameError : public std::exception
{
public: 
	//default constructor
	GameError()throw() :errorCode(FATAL_ERROR), message("Undefined Error in game.") {}
	//copy constructor
	GameError(const GameError& e) throw() : std::exception(e), errorCode(e.errorCode), message(e.message) {}
	//constructor with args
	GameError(int code, const std::string &s) throw() :errorCode(code), message(s) {}
	//assignmetn operator
	GameError& operator= (const GameError& rhs) throw()
	{
		std::exception::operator=(rhs);
		this->errorCode = rhs.errorCode;
		this->message = rhs.message;
	}
	//destructior
	virtual ~GameError() throw() {};

	//override what from base class
	virtual const char* what() const throw() { return this->getMessage(); }
	const char* getMessage() const throw() { return message.c_str(); } //std::string::c_str Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
	int getErrorCode() const throw() { return errorCode; }

	//Error codes
	//Negative numbers are fatal errors that may require the game to be shutdown.
	//Positive numbers are warnings that no not require the game to be shutdown.
	static const int FATAL_ERROR = -1;
	static const int WARNING = 1;

private:
	int errorCode;
	std::string message;
};