#pragma once

#include "../statement_name.h"

class Statement
{
	StatementName name;

public:
	Statement(StatementName);
	virtual ~Statement();
	virtual StatementName model_name();
};