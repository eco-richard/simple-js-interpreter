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
    {",", TokenType::Comma},     {";", TokenType::Semicolon},
    {"-", TokenType::Minus},     {"!", TokenType::Bang},
    {"/", TokenType::Slash},     {"*", TokenType::Asterisk},
    {"%", TokenType::Percent},   {"<", TokenType::Lt},
    {">", TokenType::Gt}};

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

char Lexer::peek_char() noexcept {
  return (*(_position + 1));
}

std::string Lexer::peek_2_char() noexcept {
  return std::string{_position + 1, _position + 3};
}

std::optional<Token> Lexer::check_equality_strength(char ch) noexcept {
    if (peek_2_char() == "==" && ch == '=') {
        _position += 3;
        return Token(TokenType::StrongEqual, "===");
    } 
    if (peek_2_char() == "==" && ch == '!') {
        _position += 3;
        return Token(TokenType::StrongNotEqual, "!==");
    }
    if (peek_char() == '=' && ch == '=') {
        _position += 2;
        return Token(TokenType::WeakEqual, "==");
    }
    if (peek_char() == '=' && ch == '!') {
        _position += 2;
        return Token(TokenType::WeakNotEqual, "!=");
    }
    return {};
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
    if (ch_str == "=") {
      auto token = check_equality_strength('=');
      if (token.has_value()) {
        return token.value();
      }
      ++_position;
      return Token(TokenType::Assign, "=");
    }

    if (ch_str == "!") {
      auto token = check_equality_strength('!');
      if (token.has_value()) {
        return token.value();
      }
      ++_position;
      return Token(TokenType::Bang, "!");
    }

    auto type = _token_lookup.at(ch_str);
    _position++;

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
