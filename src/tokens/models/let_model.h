#pragma once

#include <string>

#include "keyword_model.h"

class LetModel : public KeywordModel
{
private:
    /* data */
public:
    LetModel();
    virtual class Token *make_next(std::string, int *) override;
    virtual bool suitable_next(TokenModel *) override;
};
