#include "parse_exception.h"

parse_exception::parse_exception(std::string description)
	: std::runtime_error(std::string("Parse Exception:\n" + description).c_str()) {}