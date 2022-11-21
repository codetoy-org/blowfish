#include "identifier_model.h"

#include "keyword_model.h"

#include "../objects/identifier_token.h"
#include "../objects/token.h"

IdentifierModel::IdentifierModel() : TokenModel(TokenName::IDENTIFIER)
{
}

Token *IdentifierModel::make_next(std::string code, int *idx)
{
    // Identifiers must begin with a-z
    char first = code[0];
    // Check if the first char is not alpha (a-z)
    if (!isalpha(first))
    {
        return nullptr;
    }

    // Lex the identifier
    std::string identifier = "";
    std::string lcode = code;
    while (!lcode.empty())
    {
        char next = lcode[0];
        // Identifiers are space-terminated
        if (next == ' ')
        {
            break;
        }
        identifier += next;
        lcode = lcode.substr(1);
    }
    TokenMgr *mgr = TokenMgr::get_instance();
    for (size_t i = 0; i < (size_t)TokenName::TOKEN_COUNT; i++)
    {
        TokenModel *model = mgr->get_model((TokenName)i);
        if (model == nullptr)
        {
            continue;
        }
        if (model->is_keyword())
        {
            KeywordModel *keyword = (KeywordModel *)model;
            if (identifier == keyword->text())
            {
                return nullptr;
            }
        }
    }
    // Use .size because we want the size in bytes (including null terminator)
    *idx += identifier.size();
    return new IdentifierToken(identifier);
}

bool IdentifierModel::may_vary()
{
    return true;
}

bool IdentifierModel::suitable_next(TokenModel *model)
{
    return true;
}