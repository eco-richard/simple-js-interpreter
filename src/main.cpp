#include <iostream>
#include "lexer.hpp"

int main() {
  const std::string input = R"(
    let five = 5;
    const ten = 10;

    const add = function(x, y) {
        x + y;
    };

    let res = add(x, y);
    )";

  constexpr TokenType testTypes[]{
      TokenType::Let,        TokenType::Identifier, TokenType::Assign,
      TokenType::Number,     TokenType::Semicolon,  TokenType::Const,
      TokenType::Identifier, TokenType::Assign,     TokenType::Number,
      TokenType::Semicolon,  TokenType::Const,      TokenType::Identifier,
      TokenType::Assign,     TokenType::Function,   TokenType::LeftParen,
      TokenType::Identifier, TokenType::Comma,      TokenType::Identifier,
      TokenType::RightParen, TokenType::LeftBrace,  TokenType::Identifier,
      TokenType::Plus,       TokenType::Identifier, TokenType::Semicolon,
      TokenType::RightBrace, TokenType::Semicolon,  TokenType::Let,
      TokenType::Identifier, TokenType::Assign,     TokenType::Identifier,
      TokenType::LeftParen,  TokenType::Identifier, TokenType::Comma,
      TokenType::Identifier, TokenType::RightParen, TokenType::Semicolon};

  Lexer l{input};

  for (const auto type : testTypes) {
    const auto token = l.peek();

    std::cout << "type : '" << std::to_string(type) << "' token.type : '" << std::to_string(token.type) << "'" << std::endl;
    std::cout << "literal : " << token.literal << std::endl;
    auto equal = (type == token.type);
    std::cout << std::boolalpha << "Equal : " << equal << std::endl;
    std::cout << std::endl;
    l.next();
  }

  return 0;
}