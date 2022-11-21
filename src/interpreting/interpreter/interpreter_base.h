#pragma once

#include "../../statements/objects/equals_statement.h"
#include "../../statements/objects/let_statement.h"
#include "../../statements/statement_stream.h"

class InterpreterBase
{
	StatementStream *statements;

public:
	InterpreterBase(StatementStream *);
	virtual void execute_statements();
	virtual void equals_statement(EqualsStatement *equals_statement);
	virtual void let_statement(LetStatement *let_statement);
};