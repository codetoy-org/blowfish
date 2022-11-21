#pragma once

#include "../token_name.h"

#include <string>
#include <vector>

class TokenModel
{
private:
    /* data */
    TokenName name;

public:
    TokenModel();
    TokenModel(TokenName name);
    virtual TokenName model_name();
    virtual class Token *make_next(std::string, int *);
    // Determines if the token may match multiple different strings, and not just one string of text
    virtual bool may_vary();
    // Determines if the model is suitable to be the next model
    virtual bool suitable_next(TokenModel *);
    // Tells us if the token is a keyword or not
    virtual bool is_keyword();
};
