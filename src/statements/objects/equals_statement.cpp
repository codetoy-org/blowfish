#include "equals_statement.h"

EqualsStatement::EqualsStatement(IdentifierToken *identifier, EqualsToken *equalsToken, LiteralToken *literalToken, SemicolonToken *terminatorToken)
	: Statement(StatementName::EQUALS_STATEMENT)
{
	this->identifier = identifier;
	this->equalsToken = equalsToken;
	this->literalToken = literalToken;
	this->terminatorToken = terminatorToken;
}

IdentifierToken *EqualsStatement::get_identifier()
{
	return this->identifier;
}

EqualsToken *EqualsStatement::get_equals()
{
	return this->equalsToken;
}

LiteralToken *EqualsStatement::get_literal()
{
	return this->literalToken;
}

SemicolonToken *EqualsStatement::get_terminator()
{
	return this->terminatorToken;
}
