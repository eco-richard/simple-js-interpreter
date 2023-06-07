#ifndef SIMPLE_JS_INTERP_SRC_TOKEN_HPP
#define SIMPLE_JS_INTERP_SRC_TOKEN_HPP

#include <ostream>
#include <string>

enum class TokenType {
  // Misc
  Illegal,
  Eof,
  EndLine,

  // Identifiers + Literals
  Identifier,
  Number,

  // Operators
  Assign,
  Plus,
  Minus,
  Bang,
  Slash,
  Asterisk,
  Percent,

  // Delimiters
  Comma,
  Semicolon,

  LeftParen,
  RightParen,
  LeftBrace,
  RightBrace,
  LeftBrack,
  RightBrack,

  // Keywords
  Function,
  Let,
  Const,
  Var,
  True,
  False,
  If,
  Else,
  Return,

  StrongEqual,
  WeakEqual,
  StrongNotEqual,
  WeakNotEqual,
  Lt,
  Gt,
  Le,
  Ge
};

using Literal = std::string;

struct Token {
  TokenType type;
  Literal literal;
  Token(TokenType t, Literal l);
  Token();
};

std::ostream& operator<<(std::ostream& os, const Token& t);

namespace std {

std::string to_string(TokenType t);

}

#endif  // !SIMPLE_JS_INTERP_SRC_TOKEN_HPPk
