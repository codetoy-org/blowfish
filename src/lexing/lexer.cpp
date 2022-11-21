#include "lexer.h"

#include "token_lexer.h"

Lexer::Lexer(std::string code)
{
	this->code = code;
	this->idx = 0;
}

TokenStream *Lexer::lex()
{
	TokenLexer tkLex;
	TokenStream *results = new TokenStream();
	std::string theCode = this->code;

	while (theCode != "")
	{
		const auto &[token, code_left] = tkLex.lex_next(theCode);
		results->push(token);
		theCode = code_left;
	}

	return results;
}

// #include <string>

// #include "lexer.h"

// // Tokens
// #include "tokens/token.h"
// #include "tokens/equal.h"
// #include "tokens/let.h"
// #include "tokens/quote.h"
// #include "tokens/semicolon.h"
// #include "tokens/identifier.h"
// #include "tokens/eof.h"
// #include "tokens/unknown.h"
// #include "tokens/string.h"

// Lexer::Lexer(std::string code)
// {
//     this->code = code;
//     this->idx = 0;
// }

// Token *Lexer::read_current()
// {
//     if (this->is_eof())
//     {
//         return new EndOfFile();
//     }

//     if (this->get_current_char() == ' ')
//     {
//         this->advance();
//     }

//     char cur = this->get_current_char();

//     switch (cur)
//     {
//     case '=':
//         return new Equal();
//     case '"':
//     {
//         this->advance(); // We advance the index once to get the char after the first quote

//         std::string string = "";
//         while (this->get_current_char() != '"') // Keep looping until we find the next quote
//         {
//             string += this->get_current_char();

//             this->advance();
//         }

//         return new String(string);
//     }
//     case ';':
//         return new Semicolon();
//     default:
//         if (std::isalpha(cur)) // If the current character is a-Z
//         {
//             std::string token = "";
//             while (!this->is_eof())
//             {
//                 char curr = this->get_current_char();

//                 if (!std::isalpha(curr)) // First we check if that character is alpha, if not then we break out the loop and we know the token is done
//                 {
//                     break;
//                 }

//                 token += curr;

//                 this->advance();
//             }

//             if (token == "let")
//             {
//                 return new Let();
//             }
//             else
//             {
//                 return new Identifier(token);
//             }
//         }

//         break;
//     }

//     return new Unknown(std::string(sizeof(cur), cur));
// }

// std::vector<Token *> lex(Lexer *lexer)
// {
//     std::vector<Token *> tokens = std::vector<Token *>();

//     bool lexing = true;

//     while (lexing)
//     {
//         Token *token = lexer->read_current();
//         tokens.push_back(token);

//         if (token->check("EOF"))
//         {
//             break;
//         }

//         lexer->advance();
//     }

//     return tokens;
// }