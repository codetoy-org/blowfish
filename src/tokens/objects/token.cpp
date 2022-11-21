#include "token.h"

Token::Token()
{
	this->model_id = TokenName::UNIDENTIFIED;
}

Token::Token(TokenName modelName)
{
	this->model_id = modelName;
}

TokenName Token::model_name()
{
	return this->model_id;
}