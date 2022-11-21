#pragma once

#include "../tokens/objects/token.h"

#include <string>
#include <utility>

class TokenLexer
{
private:
    /* data */
public:
    // Lex the next token from the code string, then return the token and the remaining code
    std::pair<Token *, std::string> lex_next(std::string);
};