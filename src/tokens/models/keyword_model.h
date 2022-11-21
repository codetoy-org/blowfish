#pragma once

#include <string>

#include "token_model.h"

class KeywordModel : public TokenModel
{
private:
    std::string keyword;

public:
    KeywordModel(std::string keyword, TokenName name);

    template <typename T>
    class Token *make_next_keyword(std::string code, int *idx)
    {
        if (code.find(this->keyword) == 0)
        {
            *idx += this->keyword.length();
            return new T();
        }
        return nullptr;
    }

    virtual class Token *make_next(std::string code, int *idx) override;
    virtual bool is_keyword() override;
    virtual const std::string &text();
};
