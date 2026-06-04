#pragma once

#include "ast.hpp"
#include "scanner.hpp"

namespace XX {
class Parser {
private:
  Scanner &scanner;
  const std::string &source;
  AST::Node *module;
  Token currentToken;
  Token previousToken;

  void advance();
  bool match(TokenType t);
  bool isOP();
  int getBindingPower(TokenType t);
  AST::Type matchType(TokenType t);
  AST::VarDeclr *parseVarDeclr();
  AST::Expr *parseExpr(int b);
  AST::BinaryExpr *parseBinaryExpr();
  AST::UnaryExpr *parseUnaryExpr();
  AST::Expr *parseLiteral();
  AST::IntLiteral *parseIntLiteral();
  AST::FloatLiteral *parseFloatLiteral();

public:
  AST::Forest *parse();
  Parser(Scanner &s, std::string &sc) : scanner(s), source(sc) { advance(); }
  ~Parser() {}
};
} // namespace XX
