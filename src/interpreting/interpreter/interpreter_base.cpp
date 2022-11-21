#include "interpreter_base.h"
#include "interpreter_base.h"

#include "../../exception/interpret_exception.h"

InterpreterBase::InterpreterBase(StatementStream *statements)
{
	this->statements = statements;
}

void InterpreterBase::execute_statements()
{
	while (this->statements->has_next())
	{
		Statement *stmt = this->statements->pop_next();

		switch (stmt->model_name())
		{
		case StatementName::EQUALS_STATEMENT:
			this->equals_statement((EqualsStatement *)stmt);
			break;
		case StatementName::LET_STATEMENT:
			this->let_statement((LetStatement *)stmt);
			break;
		default:
			throw interpret_exception("Unknown statement name");
		}
	}
}

void InterpreterBase::equals_statement(EqualsStatement *equals_statement)
{
	throw interpret_exception("Statement not implemented");
}

void InterpreterBase::let_statement(LetStatement *let_statement)
{
	throw interpret_exception("Statement not implemented");
}
