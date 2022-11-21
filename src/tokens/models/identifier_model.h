#pragma once

#include <string>

#include "token_model.h"

class IdentifierModel : public TokenModel
{
private:
    /* data */
public:
    IdentifierModel();
    virtual class Token *make_next(std::string, int *) override;
    virtual bool may_vary() override;
    virtual bool suitable_next(TokenModel *) override;
};
