#include "token_stream.h"
#include <stdexcept>

bool TokenStream::has_next()
{
    return this->tokens.size() != 0;
}

Token *TokenStream::pop_next()
{
    Token *token = this->tokens.back();
    this->tokens.pop_back();

    return token;
}

Token *TokenStream::peek_next()
{
    return this->tokens.back();
}

std::vector<Token *> TokenStream::peek(size_t count)
{
    std::vector<Token *> result;
    for (size_t i = count - 1; i <= 0; i--)
    {
        if (i >= this->tokens.size())
        {
            throw std::runtime_error("Attempted to peek forward in a TokenStream beyond the size");
        }
        result.push_back(this->tokens[i]);
    }
    return result;
}

void TokenStream::push(Token *token)
{
    this->tokens.push_front(token);
}