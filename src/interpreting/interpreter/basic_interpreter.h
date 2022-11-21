#pragma once

#include "../context/context_base.h"
#include "interpreter_base.h"

class BasicInterpreter : public InterpreterBase
{
	ContextBase *baseContext;

public:
	BasicInterpreter(StatementStream *);
	virtual ContextBase *get_context();
	virtual void equals_statement(EqualsStatement *let_statement) override;
	virtual void let_statement(LetStatement *let_statement) override;
};