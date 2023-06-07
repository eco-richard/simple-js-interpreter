#ifndef SIMPLE_JS_INTERPRETER_SRC_PARSER_PROGRAM_HPP
#define SIMPLE_JS_INTERPRETER_SRC_PARSER_PROGRAM_HPP

#include <vector>

#include "statement.hpp"

struct Program {
    std::vector<Statement*> statements;
};

#endif // !SIMPLE_JS_INTERPRETER_SRC_PARSER_PROGRAM_HPP
