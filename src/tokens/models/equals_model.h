#pragma once

#include <string>

#include "keyword_model.h"

class EqualsModel : public KeywordModel
{
private:
    /* data */
public:
    EqualsModel();
    virtual class Token *make_next(std::string, int *) override;
    virtual bool suitable_next(TokenModel *) override;
};
