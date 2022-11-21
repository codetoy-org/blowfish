#pragma once

#include "objects/statement.h"

#include <deque>
#include <vector>

class StatementStream
{
private:
    std::deque<Statement *> statements;

public:
    bool has_next();
    Statement *pop_next();
    std::vector<Statement *> peek(size_t count);
    void push(Statement *);
};