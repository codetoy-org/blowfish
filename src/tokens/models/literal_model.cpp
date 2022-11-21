#include "literal_model.h"

#include "../objects/literal_token.h"
#include "../objects/token.h"

LiteralModel::LiteralModel() : TokenModel(TokenName::LITERAL)
{
}

Token *LiteralModel::make_next(std::string code, int *idx)
{
    if (code.empty())
    {
        return nullptr;
    }

    if (code[0] == '"')
    {
        std::string literal;

        do
        {
            literal += code[0];
            *idx += 1;

            code = code.substr(1);
        } while (code[0] != '"');

        *idx += 1;

        return new LiteralToken(literal);
    }

    return nullptr;
}

bool LiteralModel::suitable_next(TokenModel *model)
{
    TokenName next_id = model->model_name();

    switch (next_id)
    {
    case TokenName::SEMICOLON:
        return true;
    }

    return false;
}

bool LiteralModel::may_vary()
{
    return true;
}