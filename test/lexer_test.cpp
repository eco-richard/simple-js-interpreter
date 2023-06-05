#include <gtest/gtest.h>
#include <iostream>
#include <lexer.hpp>
#include <string>
#include <token.hpp>

TEST(LexerTest, TestNextToken) {
  constexpr TokenType testTypes[]{TokenType::Assign,    TokenType::Plus,
                                  TokenType::LeftParen, TokenType::RightParen,
                                  TokenType::LeftBrace, TokenType::RightBrace,
                                  TokenType::Comma,     TokenType::Semicolon};

  Lexer l{"=+(){},;"};

  for (const auto type : testTypes) {
    const auto token = l.peek();

    ASSERT_EQ(token.type, type);
    l.next();
  }
}

TEST(LexerTest, SimpleJavaScript) {
  const std::string input = R"(
    let five = 5;
    const ten = 10;

    const add = function(x , y) {
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
    std::cout << "Expected: " << std::to_string(type) << "\n"
              << "Got: " << std::to_string(token.type)  << " with : "
              << token.literal << "\n" << std::endl;

    ASSERT_EQ(token.type, type) << "Expected: " << std::to_string(type) << "\n"
                                << "Got: " << std::to_string(token.type);
    l.next();
  }
}
