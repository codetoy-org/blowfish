#include "equals_model.h"

#include "../objects/equals_token.h"
#include "../objects/token.h"

EqualsModel::EqualsModel() : KeywordModel("=", TokenName::EQUALS)
{
}

Token *EqualsModel::make_next(std::string code, int *idx)
{
    return make_next_keyword<EqualsToken>(code, idx);
}

bool EqualsModel::suitable_next(TokenModel *model)
{
    TokenName next_id = model->model_name();

    switch (next_id)
    {
    case TokenName::LITERAL:
        return true;
    }

    return false;
}