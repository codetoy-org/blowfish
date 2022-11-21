#pragma once

#include "../statements/statement_stream.h"
#include "../interpreting/interpreter/interpreter_base.h"
#include "../tokens/token_stream.h"

class Parser
{
	TokenStream *lexed;

public:
	Parser(TokenStream *lexed);
	virtual StatementStream *parse();
};