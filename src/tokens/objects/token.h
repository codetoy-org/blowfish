#pragma once

#include "../token_mgr.h"

#include <string>

class Token
{
private:
    TokenName model_id;

public:
    Token();
    Token(TokenName);
    virtual TokenName model_name();
};
