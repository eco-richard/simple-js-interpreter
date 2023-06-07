#include <gtest/gtest.h>
#include <cstddef>
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
    !-/*5;
    5 < 10 > 5;

    if (5 < 10) {
        return true;
    } else {
        return false;
    })";

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
      TokenType::Identifier, TokenType::RightParen, TokenType::Semicolon,
      TokenType::Bang,       TokenType::Minus,      TokenType::Slash,
      TokenType::Asterisk,   TokenType::Number,     TokenType::Semicolon,
      TokenType::Number,     TokenType::Lt,         TokenType::Number,
      TokenType::Gt,         TokenType::Number,     TokenType::Semicolon,
      TokenType::If,         TokenType::LeftParen,  TokenType::Number,
      TokenType::Lt,         TokenType::Number,     TokenType::RightParen,
      TokenType::LeftBrace,  TokenType::Return,     TokenType::True,
      TokenType::Semicolon,  TokenType::RightBrace, TokenType::Else,
      TokenType::LeftBrace,  TokenType::Return,     TokenType::False,
      TokenType::Semicolon,  TokenType::RightBrace,
  };
  Lexer l{input};
  for (const auto type : testTypes) {
    const auto token = l.peek();

    ASSERT_EQ(token.type, type) << "Expected: " << std::to_string(type) << "\n"
                                << "Got: " << std::to_string(token.type);
    l.next();
  }
}

TEST(LexerTest, EqualityTest) {
  constexpr auto input{R"(
    let five = 5;
    10 === 10;
    10 == 10;
    9 != 10;
    9 !== 10;
    )"};

  constexpr TokenType testTypes[]{TokenType::Let,
                                  TokenType::Identifier,
                                  TokenType::Assign,
                                  TokenType::Number,
                                  TokenType::Semicolon,
                                  TokenType::Number,
                                  TokenType::StrongEqual,
                                  TokenType::Number,
                                  TokenType::Semicolon,
                                  TokenType::Number,
                                  TokenType::WeakEqual,
                                  TokenType::Number,
                                  TokenType::Semicolon,
                                  TokenType::Number,
                                  TokenType::WeakNotEqual,
                                  TokenType::Number,
                                  TokenType::Semicolon,
                                  TokenType::Number,
                                  TokenType::StrongNotEqual,
                                  TokenType::Number,
                                  TokenType::Semicolon,};

  Lexer l{input};

  for (const auto& type : testTypes) {
    const auto token = l.peek();

    ASSERT_EQ(token.type, type) << "Expected: " << std::to_string(type) << "\n"
                                << "Got: " << std::to_string(token.type);
    l.next();
  }
}
