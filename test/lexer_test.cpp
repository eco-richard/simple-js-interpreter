#include <gtest/gtest.h>
#include <iostream>
#include <lexer.hpp>
#include <string>

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
