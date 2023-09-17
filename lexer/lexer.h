#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include <vector>

#include "token/token.h"

class Lexer {
  public:
    Lexer ( ) { }

    ~Lexer ( ) {
        for ( Token::Token* token : tokens ) {
            delete token;

        }

    }

    std::vector<Token::Token*> tokenize ( const std::string& code );

  private:
    std::string src;
    size_t pos;

    std::vector<Token::Token*> tokens;

};

#endif // LEXER_H_