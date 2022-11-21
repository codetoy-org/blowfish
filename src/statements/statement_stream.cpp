#include "statement_stream.h"
#include <stdexcept>

bool StatementStream::has_next()
{
    return this->statements.size() != 0;
}

Statement *StatementStream::pop_next()
{
    Statement *statement = this->statements.back();
    this->statements.pop_back();

    return statement;
}

std::vector<Statement *> StatementStream::peek(size_t count)
{
    std::vector<Statement *> result;
    for (size_t i = 0; i < count; i++)
    {
        if (i >= this->statements.size())
        {
            throw std::runtime_error("Attempted to peek forward in a TokenStream beyond the size");
        }
        result.push_back(this->statements[i]);
    }
    return result;
}

void StatementStream::push(Statement *token)
{
    this->statements.push_front(token);
}