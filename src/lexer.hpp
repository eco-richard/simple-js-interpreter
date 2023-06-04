#ifndef SIMPLE_JS_INTERPRETER_SRC_LEXER_HPP
#define SIMPLE_JS_INTERPRETER_SRC_LEXER_HPP

#include "token.hpp"

class Lexer {
 public:
  Lexer(std::string input);
  Token peek();
  void next();

 private:
  Token next_token() noexcept;
  char read_char() noexcept;

 private:
  Token _token;
  std::string _input;
  std::string::iterator _position;
};

#endif  // !SIMPLE_JS_INTERPRETER_SRC_LEXER_HPP
