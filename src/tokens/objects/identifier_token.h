#pragma once

#include "token.h"

class IdentifierToken : public Token
{
	std::string name;

public:
	IdentifierToken(std::string);
	virtual const std::string &get_name();
};