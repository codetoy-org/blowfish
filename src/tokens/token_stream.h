#pragma once

#include <deque>
#include "objects/token.h"

class TokenStream
{
private:
    std::deque<Token *> tokens;

public:
    bool has_next();
    Token *pop_next();
    Token *peek_next();
    std::vector<Token *> peek(size_t count);
    void push(Token *);
};