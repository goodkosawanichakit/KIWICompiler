#pragma once

#include "ast.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace KIWI {

struct Scope {
  std::unordered_map<std::string, AST::Declr *> symbol;
  Scope *parent;

  Scope() : parent(nullptr) {}
  Scope(Scope *p) : parent(p) {}
};

class SymbolTable {
private:
  Scope *currScope;
  std::vector<std::unique_ptr<Scope>> scopes;

public:
  bool declareVar(AST::VarDeclr *);
  void declareFunc(AST::FuncDeclr *);

  void enterScope();
  void leaveScope();

  SymbolTable() {
    scopes.push_back(std::make_unique<Scope>());
    currScope = scopes.back().get();
  }
};

class Semantic {
private:
  SymbolTable table;

public:
  void collectPass(const AST::Forest *);
  bool analyze();

  Semantic();
};
} // namespace KIWI
