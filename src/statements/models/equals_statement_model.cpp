#include "equals_statement_model.h"

#include "../../tokens/objects/identifier_token.h"
#include "../../tokens/objects/equals_token.h"
#include "../../tokens/objects/literal_token.h"
#include "../../tokens/objects/semicolon_token.h"

#include "../objects/equals_statement.h"

EqualsStatementModel::EqualsStatementModel() : StatementModel(StatementName::EQUALS_STATEMENT)
{
}

Statement *EqualsStatementModel::make_next(TokenStream *stream)
{
	if (!stream->has_next())
	{
		return nullptr;
	}

	size_t curIter = 0;
	IdentifierToken *identifierToken = nullptr;
	EqualsToken *equalsToken = nullptr;
	LiteralToken *literalToken = nullptr;
	SemicolonToken *terminatorToken = nullptr;
	do
	{
		if (curIter > 4)
		{
			break;
		}

		Token *nextToken = stream->peek_next();

		switch (nextToken->model_name()) {
		case TokenName::IDENTIFIER:
			stream->pop_next();
			identifierToken = (IdentifierToken *)nextToken;
			break;
		case TokenName::EQUALS:
			stream->pop_next();
			equalsToken = (EqualsToken *)nextToken;
			break;
		case TokenName::LITERAL:
			stream->pop_next();
			literalToken = (LiteralToken *)nextToken;
			break;
		case TokenName::SEMICOLON:
			stream->pop_next();
			terminatorToken = (SemicolonToken *)nextToken;
			break;
		default:
			return nullptr;
		}

		curIter++;
	} while (stream->has_next());

	if (identifierToken != nullptr &&
		equalsToken != nullptr &&
		literalToken != nullptr &&
		terminatorToken != nullptr)
	{
		return new EqualsStatement(
			identifierToken,
			equalsToken,
			literalToken,
			terminatorToken);
	}

	return nullptr;
}
