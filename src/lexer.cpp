#include <algorithm>
#include <iostream>
#include <string>

#include "lexer.hpp"
#include "token.hpp"

const std::unordered_map<std::string, TokenType> Lexer::_token_lookup = {
    {"=", TokenType::Assign},    {"+", TokenType::Plus},
    {"(", TokenType::LeftParen}, {")", TokenType::RightParen},
    {"{", TokenType::LeftBrace}, {"}", TokenType::RightBrace},
    {"[", TokenType::LeftBrack}, {"]", TokenType::RightBrack},
    {",", TokenType::Comma},     {";", TokenType::Semicolon}};

const std::unordered_map<std::string, TokenType> Lexer::_keyword_lookup = {
    {"function", TokenType::Function},
    {"let", TokenType::Let},
    {"const", TokenType::Const},
    {"var", TokenType::Var},
    {"true", TokenType::True},
    {"false", TokenType::False},
    {"if", TokenType::If},
    {"else", TokenType::Else},
    {"return", TokenType::Return},
};

Lexer::Lexer(std::string input) {
  _input = input;
  _position = _input.begin();
  _token = next_token();
}

Token Lexer::peek() {
  return _token;
}

void Lexer::next() {
  _token = next_token();
}

bool Lexer::is_whitespace(char ch) noexcept {
  return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

Token Lexer::next_token() noexcept {
  if (_position >= _input.end()) {
    return Token(TokenType::Eof, "");
  }

  // Get rid of whitespace
  _position = std::find_if_not(_position, _input.end(), is_whitespace);

  auto ch = *_position;
  std::string ch_str{ch};

  if (_token_lookup.find(ch_str) != _token_lookup.end()) {
    auto type = _token_lookup.at(ch_str);
    _position++;

    // TODO: check for ch being =, <, >, !
    return Token(type, ch_str);
  }

  if (std::isdigit(ch)) {
    auto start = _position;
    _position = std::find_if_not(_position, _input.end(), isdigit);
    std::string literal{start, _position};
    return Token(TokenType::Number, literal);
  }

  if (std::isalpha(ch)) {
    auto start = _position;
    _position = std::find_if_not(_position, _input.end(), isalpha);
    std::string literal{start, _position};
    // Check for keywords
    if (_keyword_lookup.find(literal) != _keyword_lookup.end()) {
      auto type = _keyword_lookup.at(literal);
      return Token(type, literal);
    }

    // If not a keyword, then identifier
    // _position++;
    return Token(TokenType::Identifier, literal);
  }

  return Token{};
}
