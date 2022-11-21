#pragma once

#include <string>

#include "keyword_model.h"

class SemicolonModel : public KeywordModel
{
private:
    /* data */
public:
    SemicolonModel();
    virtual class Token *make_next(std::string, int *) override;
    virtual bool suitable_next(TokenModel *) override;
};
