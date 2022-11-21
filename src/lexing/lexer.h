#pragma once

#include <vector>
#include <string>
#include "../tokens/objects/token.h"
#include "../tokens/token_stream.h"

class Lexer
{
private:
    std::string code;
    int idx;

public:
    Lexer(std::string);
    TokenStream *lex();
};

std::vector<Token *> lex(Lexer *);