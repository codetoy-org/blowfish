#pragma once

#include "models/token_model.h"
#include "token_name.h"

#include <vector>

class TokenMgr
{
private:
    TokenMgr();
    std::vector<TokenModel *> models;

public:
    static TokenMgr *get_instance();
    TokenModel *get_model(TokenName);
    class Token *new_from(std::string, int *);
};
