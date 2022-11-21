#pragma once

#include "../../tokens/objects/token.h"
#include "../../tokens/token_stream.h"
#include "../objects/statement.h"
#include "../statement_name.h"

#include <vector>

class StatementModel
{
	StatementName name;

public:
	StatementModel(StatementName name);
	virtual StatementName model_name();
	virtual Statement *make_next(TokenStream *);
};