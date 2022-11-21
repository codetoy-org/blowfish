#include "token_lexer.h"
#include "../tokens/token_mgr.h"
#include "../exception/lex_exception.h"

#include <string>

std::pair<Token *, std::string> TokenLexer::lex_next(std::string code)
{
	while (code[0] == ' ')
	{
		if (code.empty())
		{
			throw lex_exception("Unexpected end of code", code);
		}

		code = code.substr(1);
	}

	int idx = 0;
	Token *nextToken = TokenMgr::get_instance()->new_from(code, &idx);
	if (nextToken == nullptr)
	{
		throw lex_exception("Failed to lex a token", code);
	}

	return std::pair<Token *, std::string>(nextToken, code.substr(idx));
}