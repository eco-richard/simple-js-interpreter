#ifndef SIMPLE_JS_INTERPRETER_SRC_PARSER_STATEMENT_HPP
#define SIMPLE_JS_INTERPRETER_SRC_PARSER_STATEMENT_HPP

#include "../token.hpp"
#include "expression.hpp"

struct Statement {
    virtual std::string token_literal();
};

struct LetStatement : public Statement {
    LetStatement(Identifier n, Expression v);
    std::string token_literal() override;

    Token tok; // the Let Token
    Identifier name;
    Expression value; 
};

#endif // !SIMPLE_JS_INTERPRETER_SRC_PARSER_STATEMENT_HPP

