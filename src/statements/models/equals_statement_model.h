#pragma once

#include "statement_model.h"

class EqualsStatementModel : public StatementModel
{
public:
	EqualsStatementModel();
	virtual Statement *make_next(TokenStream *) override;
};