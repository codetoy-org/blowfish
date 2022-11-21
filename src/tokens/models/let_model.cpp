#include "let_model.h"

#include "../objects/let_token.h"
#include "../objects/token.h"

#define TOKEN_KEYWORD "let"
#define TOKEN_LEN (sizeof(TOKEN_KEYWORD) - 1)

LetModel::LetModel() : KeywordModel("let", TokenName::LET)
{
}

Token *LetModel::make_next(std::string code, int *idx)
{
    return make_next_keyword<LetToken>(code, idx);
}

bool LetModel::suitable_next(TokenModel *model)
{
    TokenName next_id = model->model_name();

    switch (next_id)
    {
    case TokenName::IDENTIFIER:
        return true;
    default:
        break;
    }

    return false;
}