#include "literal_token.h"

LiteralToken::LiteralToken(std::string value) : Token(TokenName::LITERAL)
{
    this->value = value;
}

const std::string &LiteralToken::get_value()
{
    return this->value;
}
