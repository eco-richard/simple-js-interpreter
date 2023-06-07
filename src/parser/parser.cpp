
#include "parser.hpp"
#include <memory>
#include "program.hpp"
 
Parser::Parser(Lexer l) {
    _lexer = std::make_unique<Lexer>(l);
    _current = Token();
    _peek = Token();

    NextToken();
    NextToken();
}

void Parser::NextToken() {
    _current = _peek;
    _peek = _lexer->peek();
    _lexer->next();
}

Program Parser::ParseProgram() {
    return {};
}


