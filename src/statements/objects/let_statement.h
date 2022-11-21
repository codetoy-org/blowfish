#pragma once

#include "statement.h"

#include "../../tokens/objects/equals_token.h"
#include "../../tokens/objects/identifier_token.h"
#include "../../tokens/objects/let_token.h"
#include "../../tokens/objects/literal_token.h"
#include "../../tokens/objects/semicolon_token.h"

class LetStatement : public Statement
{
	LetToken *letToken;
	IdentifierToken *identifier;
	EqualsToken *equalsToken;
	LiteralToken *literalToken;
	SemicolonToken *terminatorToken;

public:
	LetStatement(LetToken *letToken, IdentifierToken *identifier, EqualsToken *equalsToken, LiteralToken *literalToken, SemicolonToken *terminatorToken);
	virtual LetToken *get_let();
	virtual IdentifierToken *get_identifier();
	virtual EqualsToken *get_equals();
	virtual LiteralToken *get_literal();
	virtual SemicolonToken *get_terminator();
};