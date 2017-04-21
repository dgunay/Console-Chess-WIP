#ifndef MOVETOEXCEPTION_H
#define MOVETOEXCEPTION_H


#include <exception>
#include <string>

/*
	throw MoveToException when a function is passed a bad RowColPair
	(ie passing an orthogonal move to a func expecting a diagonal move)
*/
class MoveToException : public std::exception
{
public:
	std::string what() { return "MoveTo Exception"; }
};

#endif // !MOVETOEXCEPTION_H

