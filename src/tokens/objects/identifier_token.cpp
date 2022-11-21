#include "identifier_token.h"

IdentifierToken::IdentifierToken(std::string name) : Token(TokenName::IDENTIFIER)
{
	this->name = name;
}

const std::string &IdentifierToken::get_name()
{
	return this->name;
}
