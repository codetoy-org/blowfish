#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>

#include "lexing/lexer.h"
#include "parsing/parser.h"
#include "interpreting/interpreter/interop_interpreter.h"
#include "interpreting/context/types/type_mgr.h"
#include "tokens/objects/token.h"
#include "tokens/token_stream.h"

int main(int argc, char const *argv[])
{
    // std::string code = "let var = \"value\";";
    std::string cppVar = "hey";
    std::string code = "global = \"test\";";

    try
    {
        Lexer lexer(code);
        TokenStream *tokens = lexer.lex();
        Parser parser(tokens);
        StatementStream *statements = parser.parse();
        InteropInterpreter interpreter(statements);
        IdentifierContext *globalVar = interpreter.add_global<std::string>("global", cppVar, interpreter.get_context()->get_type_mgr()->find_type("string"));
        interpreter.execute_statements();
        cppVar = globalVar->get_value<std::string>();
        printf("cppVar: %s\n", cppVar.c_str());
    }
    catch (std::runtime_error &ex)
    {
        printf("[Exception caught]\n%s\n", ex.what());
    }

    return 0;
}
