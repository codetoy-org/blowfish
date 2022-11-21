#pragma once

#include <string>
#include <stdexcept>

class interpret_exception : public std::runtime_error
{
public:
	interpret_exception(std::string);
};