#include "statement_model.h"

StatementModel::StatementModel(StatementName name)
{
	this->name = name;
}

StatementName StatementModel::model_name()
{
	return this->name;
}

Statement *StatementModel::make_next(TokenStream *stream)
{
	return nullptr;
}
