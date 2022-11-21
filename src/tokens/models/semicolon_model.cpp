#include "semicolon_model.h"

#include "../objects/semicolon_token.h"
#include "../objects/token.h"

SemicolonModel::SemicolonModel() : KeywordModel(";", TokenName::EQUALS)
{
}

Token *SemicolonModel::make_next(std::string code, int *idx)
{
    return make_next_keyword<SemicolonToken>(code, idx);
}

bool SemicolonModel::suitable_next(TokenModel *model)
{
    return true;
}