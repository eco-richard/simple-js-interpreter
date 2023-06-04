#include <algorithm>
#include <string>

#include "lexer.hpp"
#include "token.hpp"

Lexer::Lexer(std::string input)
    : _input(input), _position(input.begin()), _token() {
  next();
}

Token Lexer::peek() {
  return _token;
}

void Lexer::next() {
  _token = next_token();
}

Token Lexer::next_token() noexcept {
  Token tok;

  if (_position >= _input.end()) {
    return Token(TokenType::Eof, "");
  }

  auto ch = *_position;
  _position++;

  switch (ch) {
    case '=':
      tok = Token(TokenType::Assign, std::to_string(ch));
    case '+':
      tok = Token(TokenType::Plus, std::to_string(ch));
    case '(':
      tok = Token(TokenType::LeftParen, std::to_string(ch));
    case ')':
      tok = Token(TokenType::RightParen, std::to_string(ch));
    case '{':
      tok = Token(TokenType::LeftBrace, std::to_string(ch));
    case '}':
      tok = Token(TokenType::RightBrace, std::to_string(ch));
    case ',':
      tok = Token(TokenType::Comma, std::to_string(ch));
    case ';':
      tok = Token(TokenType::Semicolon, std::to_string(ch));
  }

  return tok;
}
