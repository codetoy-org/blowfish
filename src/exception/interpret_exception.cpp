#include "interpret_exception.h"

interpret_exception::interpret_exception(std::string description)
	: std::runtime_error(std::string("Interpret Exception:\n" + description).c_str())
{
}
