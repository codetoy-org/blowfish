#pragma once

#include <exception>
#include <string>
#include <stdexcept>

class lex_exception : public std::runtime_error
{
public:
	// Creates a lex exception
	// first param = description of the issue
	// second param = the problematic code
	lex_exception(std::string, std::string);
};