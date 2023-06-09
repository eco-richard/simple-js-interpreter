#include "token.hpp"

Token::Token() : type(), literal("") {}

Token::Token(TokenType t, Literal l) : type(t), literal(l) {}

Token::Token(const Token& t) {
    type = t.type;
    literal = t.literal;
}

Token::Token(Token&& t) {
    type = std::move(t.type);
    literal = std::move(t.literal);
}

Token& Token::operator=(const Token& rhs) {
    if (this == &rhs) {
        return *this;
    }
    type = rhs.type;
    literal = rhs.literal;
    return *this;
}

Token& Token::operator=(Token&& rhs) {
    type = std::move(rhs.type);
    literal = std::move(rhs.literal);

    return *this;
}

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
    case TokenType::Minus:
      return "-";
    case TokenType::Bang:
      return "!";
    case TokenType::Slash:
      return "/";
    case TokenType::Asterisk:
      return "*";
    case TokenType::Percent:
      return "%";
    case TokenType::Comma:
      return ",";
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
    case TokenType::StrongNotEqual:
      return "!==";
    case TokenType::WeakNotEqual:
      return "!=";
    case TokenType::Lt:
      return "<";
    case TokenType::Gt:
      return ">";
    case TokenType::Le:
      return "<=";
    case TokenType::Ge:
      return ">=";
  }

};  // namespace std
