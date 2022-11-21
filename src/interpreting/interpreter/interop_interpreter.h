#pragma once

#include "basic_interpreter.h"
#include "../context/types/type_base.h"

class InteropInterpreter : public BasicInterpreter
{
public:
	InteropInterpreter(StatementStream *statements);
	template <typename T>
	IdentifierContext *add_global(std::string name, T variable, TypeBase *type)
	{
		ContextBase *cb = this->get_context();
		IdentifierContext *ic = cb->create_identifier(name, type);
		ic->assign<T>(variable, type);
		return ic;
	}
};