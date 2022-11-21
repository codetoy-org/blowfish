#pragma once

#include "statement.h"

#include "../../tokens/objects/equals_token.h"
#include "../../tokens/objects/identifier_token.h"
#include "../../tokens/objects/literal_token.h"
#include "../../tokens/objects/semicolon_token.h"

class EqualsStatement : public Statement
{
	IdentifierToken *identifier;
	EqualsToken *equalsToken;
	LiteralToken *literalToken;
	SemicolonToken *terminatorToken;

public:
	EqualsStatement(IdentifierToken *identifier, EqualsToken *equalsToken, LiteralToken *literalToken, SemicolonToken *terminatorToken);
	virtual IdentifierToken *get_identifier();
	virtual EqualsToken *get_equals();
	virtual LiteralToken *get_literal();
	virtual SemicolonToken *get_terminator();
};