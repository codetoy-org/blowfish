#include "parser.h"

#include "../exception/parse_exception.h"
#include "../statements/statement_mgr.h"

Parser::Parser(TokenStream *lexed)
{
	this->lexed = lexed;
}

StatementStream *Parser::parse()
{
	StatementStream *results = new StatementStream();
	StatementMgr *stmtMgr = StatementMgr::get_instance();
	while (lexed->has_next())
	{
		Statement *stmt = stmtMgr->new_from(lexed);
		if (stmt == nullptr)
		{
			throw parse_exception("Failed to parse a statement!");
		}
		results->push(stmt);
	}
	return results;
}
