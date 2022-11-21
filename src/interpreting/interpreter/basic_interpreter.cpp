#include "basic_interpreter.h"
#include "../context/types/type_mgr.h"
#include "../context/types/wrappers/string_wrapper.h"

#include "../../exception/interpret_exception.h"

#include <string>
#include <unordered_map>

BasicInterpreter::BasicInterpreter(StatementStream *statements) : InterpreterBase(statements)
{
	this->baseContext = new ContextBase();

	TypeMgr *type_mgr = this->get_context()->get_type_mgr();

	type_mgr->register_type(new StringWrapper(type_mgr->next_id()));
}

ContextBase *BasicInterpreter::get_context()
{
	return this->baseContext;
}

void BasicInterpreter::equals_statement(EqualsStatement *let_statement)
{
	IdentifierToken *identifier = let_statement->get_identifier();
	LiteralToken *lit = let_statement->get_literal();
	IdentifierContext *identCtx = this->baseContext->acquire_identifier(identifier->get_name());
	if (identCtx == nullptr)
	{
		throw interpret_exception("Unknown identifier '" + identifier->get_name() + "'");
	}
	identCtx->assign<std::string>(lit->get_value(), identCtx->get_type());
}

std::unordered_map<std::string, std::string> stringLiterals;

void BasicInterpreter::let_statement(LetStatement *let_statement)
{
	IdentifierToken *identifier = let_statement->get_identifier();
	LiteralToken *lit = let_statement->get_literal();
	IdentifierContext *identCtx = this->baseContext->create_identifier(identifier->get_name(), this->get_context()->get_type_mgr()->find_type("string"));
	identCtx->assign<std::string>(lit->get_value(), identCtx->get_type());
}