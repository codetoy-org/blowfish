#pragma once

#include "../tokens/token_stream.h"
#include "models/statement_model.h"
#include "objects/statement.h"
#include "statement_name.h"

#include <vector>

class StatementMgr
{
private:
    StatementMgr();
    std::vector<StatementModel *> models;

public:
    static StatementMgr *get_instance();
    StatementModel *get_model(StatementName);
    Statement *new_from(TokenStream *);
};
