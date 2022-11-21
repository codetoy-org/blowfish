#pragma once

#include <string>

#include "token_model.h"

class LiteralModel : public TokenModel
{
private:
    /* data */
public:
    LiteralModel();
    virtual class Token *make_next(std::string, int *) override;
    virtual bool suitable_next(TokenModel *) override;
    virtual bool may_vary() override;
};
