#include "statement.h"

Statement::Statement(StatementName name)
{
    this->name = name;
}

Statement::~Statement()
{
}

StatementName Statement::model_name()
{
    return this->name;
}
