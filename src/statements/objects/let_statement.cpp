#include "let_statement.h"

LetStatement::LetStatement(LetToken *letToken, IdentifierToken *identifier, EqualsToken *equalsToken, LiteralToken *literalToken, SemicolonToken *terminatorToken)
	: Statement(StatementName::LET_STATEMENT)
{
	this->letToken = letToken;
	this->identifier = identifier;
	this->equalsToken = equalsToken;
	this->literalToken = literalToken;
	this->terminatorToken = terminatorToken;
}

LetToken *LetStatement::get_let()
{
	return this->letToken;
}

IdentifierToken *LetStatement::get_identifier()
{
	return this->identifier;
}

EqualsToken *LetStatement::get_equals()
{
	return this->equalsToken;
}

LiteralToken *LetStatement::get_literal()
{
	return this->literalToken;
}

SemicolonToken *LetStatement::get_terminator()
{
	return this->terminatorToken;
}
