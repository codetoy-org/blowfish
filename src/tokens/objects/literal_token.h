#pragma once

#include "token.h"

class LiteralToken : public Token
{
    std::string value;

public:
    LiteralToken(std::string);
    virtual const std::string &get_value();
};