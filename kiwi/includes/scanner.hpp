#pragma once

#include "token.hpp"
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace KIWI {
class Scanner {
private:
  const std::string &source;
  size_t start = 0;
  size_t current = 0;
  size_t line = 1;
  std::vector<uint32_t> lineOffset;
  static std::unordered_map<std::string, TokenType> reserve_words;

  bool isAtEnd();
  bool match(char c);
  char advance();
  char peek();
  char peekNext();
  void skipWhitespace();
  void comment();
  bool multiLineComment();
  Token digit();
  Token string();
  Token identifier();

public:
  Token scanToken();
  const std::vector<uint32_t> &getLineOffset();
  Scanner(const std::string &source);
};

} // namespace KIWI
