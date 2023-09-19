#include <string>

#include "node/node.h"
#include "../lexer/token/token.h"

#include "parser.h"

Node::Literal* Parser::parsePrimaryExpression ( ) {
    if ( tokens[pos]->type == Token::Type::Integer || tokens[pos]->type == Token::Type::Float ) {
        Node::Literal* number = new Node::Number(std::stof(tokens[pos]->lexeme), tokens[pos]->lexeme, tokens[pos]->start, tokens[pos]->end);

        pos++;

        return number;

    } else if ( tokens[pos]->type == Token::Type::Identifier ) {
        Node::Literal* identifier = new Node::Identifier(tokens[pos]->lexeme, tokens[pos]->start, tokens[pos]->end);

        pos++;

        return identifier;

    } else if ( tokens[pos]->type == Token::Type::String ) {
        Node::Literal* string = new Node::String(tokens[pos]->lexeme.substr(1, tokens[pos]->lexeme.size() - 2), tokens[pos]->lexeme, tokens[pos]->start, tokens[pos]->end);

        pos++;

        return string;

    } else if ( tokens[pos]->type == Token::Type::Character ) {
        Node::Literal* character = new Node::String(tokens[pos]->lexeme.substr(1, tokens[pos]->lexeme.size() - 2), tokens[pos]->lexeme, tokens[pos]->start, tokens[pos]->end);

        pos++;

        return character;

    } else {
        pos++;

    }

}

Node::Expression* Parser::parseMultiplicativeExpression ( ) {
    Node::Expression* left = parsePrimaryExpression();

    while ( tokens[pos]->type == Token::Type::BinaryOperator && ( tokens[pos]->lexeme == "*" || tokens[pos]->lexeme == "/" ) ) {
        std::string op = tokens[pos]->lexeme;

        pos++;

        Node::Expression* right = parsePrimaryExpression();

        left = new Node::BinaryExpression(left, op, right, left->start, right->end);

    }

    return left;

}

Node::Expression* Parser::parseAdditiveExpression ( ) {
    Node::Expression* left = parseMultiplicativeExpression();

    while ( tokens[pos]->type == Token::Type::BinaryOperator && ( tokens[pos]->lexeme == "+" || tokens[pos]->lexeme == "-" ) ) {
        std::string op = tokens[pos]->lexeme;

        pos++;

        Node::Expression* right = parseMultiplicativeExpression();

        left = new Node::BinaryExpression(left, op, right, left->start, right->end);

    }

    return left;

}

Node::Expression* Parser::parseComparisonExpression ( ) {
    Node::Expression* left = parseAdditiveExpression();

    while ( tokens[pos]->type == Token::Type::LogicalOperator && ( tokens[pos]->lexeme == ">" || tokens[pos]->lexeme == "<" || tokens[pos]->lexeme == "==" || tokens[pos]->lexeme == ">=" || tokens[pos]->lexeme == "<=" ) ) {
        std::string op = tokens[pos]->lexeme;

        pos++;

        Node::Expression* right = parseAdditiveExpression();

        left = new Node::LogicalExpression(left, op, right, left->start, right->end);

    }

    return left;

}

Node::Expression* Parser::parseLogicalExpression ( ) {
    Node::Expression* left = parseComparisonExpression();

    while ( tokens[pos]->type == Token::Type::LogicalOperator && ( tokens[pos]->lexeme == "and" || tokens[pos]->lexeme == "&&" || tokens[pos]->lexeme == "or" || tokens[pos]->lexeme == "||" ) ) {
        std::string op = tokens[pos]->lexeme;

        pos++;

        Node::Expression* right = parseComparisonExpression();

        left = new Node::LogicalExpression(left, op, right, left->start, right->end);

    }

    return left;

}

Node::Expression* Parser::parseExpression ( ) {
    return parseLogicalExpression();

}

Node::Statement* Parser::parseStatement ( ) {
    return parseExpression();

}


Node::Program Parser::parse ( const std::string& code ) {
    src = code;

    tokens = lexer.tokenize(src);
    pos = 0;

    ast.body.clear();

    while ( tokens[pos]->type != Token::Type::EndOfFile ) {
        ast.body.push_back(parseStatement());

    }

    return ast;

}
