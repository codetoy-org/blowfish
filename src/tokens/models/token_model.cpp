#include "token_model.h"
#include "../objects/token.h"
#include "../token_mgr.h"

TokenModel::TokenModel()
{
    this->name = TokenName::UNIDENTIFIED;
}

TokenModel::TokenModel(TokenName name)
{
    this->name = name;
}

TokenName TokenModel::model_name()
{
    return this->name;
}

Token *TokenModel::make_next(std::string code, int *idx)
{
    return nullptr;
}

bool TokenModel::may_vary()
{
    return false;
}

bool TokenModel::suitable_next(TokenModel *)
{
    return false;
}

bool TokenModel::is_keyword()
{
    return false;
}