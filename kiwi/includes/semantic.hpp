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
};

class SymbolTable {
private:
  std::vector<std::unique_ptr<Scope>> scopes;

public:
  void declareVar(AST::Declr *);
  void declareFunc(AST::Declr *);

  SymbolTable() {}
};

class Semantic {
private:
  SymbolTable table;

public:
  Semantic();
};
} // namespace KIWI
