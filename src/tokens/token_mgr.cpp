#include "token_mgr.h"

#include "models/equals_model.h"
#include "models/identifier_model.h"
#include "models/let_model.h"
#include "models/literal_model.h"
#include "models/semicolon_model.h"
#include "objects/token.h"

static TokenMgr *instance;

TokenMgr::TokenMgr()
{
    this->models = {
        new EqualsModel(),
        new IdentifierModel(),
        new LetModel(),
        new LiteralModel(),
        new SemicolonModel(),
    };
}

TokenMgr *TokenMgr::get_instance()
{
    if (instance == nullptr)
    {
        instance = new TokenMgr();
    }

    return instance;
}

TokenModel *TokenMgr::get_model(TokenName name)
{
    for (const auto &model : this->models)
    {
        if (model->model_name() == name)
        {
            return model;
        }
    }
    return nullptr;
}

Token *TokenMgr::new_from(std::string code, int *idx)
{
    for (const auto &model : this->models)
    {
        Token *match = model->make_next(code, idx);
        if (match)
        {
            return match;
        }
    }
    return nullptr;
}