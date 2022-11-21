#pragma once

#include <exception>
#include <string>
#include <stdexcept>

class parse_exception : public std::runtime_error
{
public:
	// Creates a parse exception
	// first param = description of the issue
	parse_exception(std::string);
};