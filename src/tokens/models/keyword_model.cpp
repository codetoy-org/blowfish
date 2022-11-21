#include "keyword_model.h"

#include "../objects/token.h"

KeywordModel::KeywordModel(std::string keyword, TokenName name) : TokenModel(name)
{
    this->keyword = keyword;
}

Token *KeywordModel::make_next(std::string code, int *idx)
{
    return make_next_keyword<Token>(code, idx);
}

bool KeywordModel::is_keyword()
{
    return true;
}

const std::string &KeywordModel::text()
{
    return this->keyword;
}