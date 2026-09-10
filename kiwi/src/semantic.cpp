#include "semantic.hpp"
#include "ast.hpp"
#include <memory>

/*
  FUNC_DECLR Name: f ReturnType: INT8
  PARAM_DECLR Name: a Type: INT8
  PARAM_DECLR Name: b Type: INT8
  BLOCK
    ASSIGN_STMT     IDENTIFIER Name: a
      BINARY_EXPR Operator: +
        IDENTIFIER Name: a
        IDENTIFIER Name: b
    RETURN_STMT Value:
      IDENTIFIER Name: a
 */

void KIWI::Semantic::collectPass(const KIWI::AST::Forest *topLevel) {
  if (!topLevel)
    return;
  for (auto &declr : topLevel->vec) {
    switch (declr->getKind()) {
    case AST::Kind::FUNC_DECLR:
      table.declareFunc(static_cast<AST::FuncDeclr *>(declr.get()));
      break;

    case AST::Kind::VAR_DECLR:
      table.declareVar(static_cast<AST::VarDeclr *>(declr.get()));
      break;

    default:
      break;
    }
  }
}

void KIWI::SymbolTable::enterScope() {
  scopes.push_back(std::make_unique<Scope>(currScope));
  currScope = scopes.back().get();
}

void KIWI::SymbolTable::leaveScope() { currScope = currScope->parent; }

void KIWI::SymbolTable::declareFunc(KIWI::AST::FuncDeclr *node) {
  if (!node)
    return;
  std::string name = node->getName();

  // TODO:IDK
  if (currScope->symbol.count(name) > 0)
    return;

  currScope->symbol.insert({name, node});
  enterScope();

  // Literally the same as collectPass, but my grammar doesn't allow nested
  // function.
  for (auto &param : node->getParams()) {
    std::string name = static_cast<AST::ParamDeclr *>(param.get())->getName();
    currScope->symbol.insert({name, param.get()});
  }

  // TODO: collectBlock!!

  leaveScope();
}
