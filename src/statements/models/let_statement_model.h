#pragma once

#include "statement_model.h"

class LetStatementModel : public StatementModel
{
public:
	LetStatementModel();
	virtual Statement *make_next(TokenStream *) override;
};