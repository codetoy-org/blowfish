#include "statement_mgr.h"

#include "models/equals_statement_model.h"
#include "models/let_statement_model.h"

static StatementMgr *instance = nullptr;

StatementMgr::StatementMgr()
{
	this->models = {
		new EqualsStatementModel(),
		new LetStatementModel(),
	};
}

StatementMgr *StatementMgr::get_instance()
{
	if (instance == nullptr)
	{
		instance = new StatementMgr();
	}
	return instance;
}

StatementModel *StatementMgr::get_model(StatementName name)
{
	for (const auto &model : this->models)
	{
		if (model->model_name() == name)
		{
			return model;
		}
	}
	return nullptr;
}

Statement *StatementMgr::new_from(TokenStream *stream)
{
	for (const auto &model : this->models)
	{
		Statement *match = model->make_next(stream);
		if (match)
		{
			return match;
		}
	}
	return nullptr;
}
