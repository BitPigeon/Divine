#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <string>

#include "../lexer/lexer.h"
#include "../lexer/token/token.h"
#include "node/node.h"

class Parser {
  public:
    Parser ( ) { }

    ~Parser ( ) { }

    Node::Literal* parsePrimaryExpression ( );

    Node::Expression* parseMultiplicativeExpression ( );
    Node::Expression* parseAdditiveExpression ( );

    Node::Expression* parseComparisonExpression ( );
    Node::Expression* parseLogicalExpression ( );

    Node::Expression* parseExpression ( );

    Node::Statement* parseStatement ( );

    Node::Program parse ( const std::string& code );

  private:
    Lexer lexer;

    std::string src;

    std::vector<Token::Token*> tokens;
    size_t pos;

    Node::Program ast;

};

#endif // PARSER_H_