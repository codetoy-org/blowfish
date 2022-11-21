#include "lex_exception.h"

lex_exception::lex_exception(std::string description, std::string problemCode)
	: std::runtime_error(std::string("Lex Exception:\n" + description + "\nHERE => " + problemCode).c_str()) {}