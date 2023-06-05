#include "token.hpp"

Token::Token() : type(), literal("") {}

Token::Token(TokenType t, Literal l) : type(t), literal(l) {}

std::string std::to_string(TokenType t) {
  switch (t) {
    case TokenType::Illegal:
      return "[illegal]";
    case TokenType::Eof:
      return "[eof]";
    case TokenType::EndLine:
      return "[endline]";
    case TokenType::Identifier:
      return "[identifier]";
    case TokenType::Number:
      return "[number]";
    case TokenType::Assign:
      return "=";
    case TokenType::Plus:
      return "+";
    case TokenType::Comma:
      return "-";
    case TokenType::Semicolon:
      return ";";
    case TokenType::LeftParen:
      return "(";
    case TokenType::RightParen:
      return ")";
    case TokenType::LeftBrace:
      return "{";
    case TokenType::RightBrace:
      return "}";
    case TokenType::LeftBrack:
      return "[";
    case TokenType::RightBrack:
      return "]";
    case TokenType::Function:
      return "function";
    case TokenType::Let:
      return "let";
    case TokenType::Const:
      return "const";
    case TokenType::Var:
      return "var";
    case TokenType::True:
      return "true";
    case TokenType::False:
      return "false";
    case TokenType::If:
      return "if";
    case TokenType::Else:
      return "else";
    case TokenType::Return:
      return "return";
    case TokenType::StrongEqual:
      return "===";
    case TokenType::WeakEqual:
      return "==";
    case TokenType::NotEqual:
      return "!=";
  }

};  // namespace std
