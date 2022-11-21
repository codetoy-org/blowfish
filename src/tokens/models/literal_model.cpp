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

    //If it starts with " then its a string
    if (code[0] == '"')
    {
        std::string literal;

        //Copy all of the code into the string 'literal'
        do
        {
            code = code.substr(1);

            literal += code[0];
            *idx += 1;
        } while (code[0] != '"');

        //The loop still adds " to the end, so we chop it off
        literal = literal.substr(0, literal.size() - 1);

        //Increment the index again so the remaining is just another literal or a ;
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