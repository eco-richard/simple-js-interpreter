#ifndef SIMPLE_JS_INTERPRETER_SRC_LEXER_HPP
#define SIMPLE_JS_INTERPRETER_SRC_LEXER_HPP

#include <optional>
#include <unordered_map>
#include "token.hpp"

class Lexer {
 public:
  Lexer(std::string input);
  Token peek();
  void next();

 private:
  Token next_token() noexcept;
  char read_char() noexcept;
  static bool is_whitespace(char ch) noexcept;
  char peek_char() noexcept;
  std::string peek_2_char() noexcept;
  std::optional<Token> check_equality_strength(char ch) noexcept;

 private:
  Token _token;
  std::string _input;
  std::string::iterator _position;

  static const std::unordered_map<std::string, TokenType> _token_lookup;
  static const std::unordered_map<std::string, TokenType> _keyword_lookup;
};

#endif  // !SIMPLE_JS_INTERPRETER_SRC_LEXER_HPP
