#pragma once
#include <cstdint>

namespace XX {
enum class TokenType {
  // Single-character tokens
  PLUS,
  MINUS,
  STAR,
  SLASH,
  SEMICOLON,
  COLON,
  COMMA,
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  DOT,
  EQUAL,
  GREATER,
  LESS,

  // LOGICAL
  AND_AND,
  OR_OR,
  NOT,

  // Two-character tokens
  PLUS_EQUAL,
  MINUS_EQUAL,
  SLASH_EQUAL,
  STAR_EQUAL,
  DOT_DOT,
  NOT_EQUAL,
  EQUAL_EQUAL,
  GREATER_EQUAL,
  LESS_EQUAL,
  RETURN_TYPE,

  // Literals
  IDENTIFIER,
  STRING,
  NUMBER_INT,
  NUMBER_FLOAT,

  // Keywords
  KW_INT8,
  KW_INT16,
  KW_INT32,
  KW_INT64,
  KW_FLOAT8,
  KW_FLOAT16,
  KW_FLOAT32,
  KW_FLOAT64,
  KW_CHAR,
  KW_STRING,
  KW_BOOL,
  KW_IF,
  KW_ELSE,
  KW_LOOP,
  KW_FN,
  KW_RETURN,
  KW_TRUE,
  KW_FALSE,

  ERROR,
  TOKEN_EOF
};

struct Token {
  TokenType type;
  uint32_t offset;
  uint16_t length;

  bool isReservedWord() const {
    return type > TokenType::KW_INT8 && type < TokenType::KW_FALSE;
  }
};

}; // namespace XX
