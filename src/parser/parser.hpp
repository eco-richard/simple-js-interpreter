#ifndef SIMPLE_JS_INTERPRETER_SRC_PARSER_PARSER_HPP
#define SIMPLE_JS_INTERPRETER_SRC_PARSER_PARSER_HPP

#include <memory>
#include "../lexer.hpp"
#include "program.hpp"

class Parser {
    public:
        Parser(Lexer l);

        void NextToken();
        Program ParseProgram(); 
    private:
        std::unique_ptr<Lexer> _lexer;
        
        Token _current;
        Token _peek;
};

#endif // !SIMPLE_JS_INTERPRETER_SRC_PARSER_PARSER_HPP

