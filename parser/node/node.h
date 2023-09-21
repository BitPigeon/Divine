#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include <string>

using namespace std;

namespace Node {
    enum class Type {
        Program,

        BinaryExpression,
        LogicalExpression,

        Identifier,
        Number,
        Character,
        String,

    };

    class Node {
      public:
        Type type;

        int start;
        int end;

        Node ( ) { }

        virtual ~Node ( ) { }

    };

    class Statement : public Node {
      public:
        Type type;

        int start;
        int end;

        Statement ( ) { }

        virtual ~Statement ( ) { }

    };

    class Program : public Statement {
      public:
        Type type = Type::Program;

        std::vector<Node*> body;

        int start;
        int end;

        Program ( ) { }

        ~Program ( ) { }

    };

    class Expression : public Statement {
      public:
        Type type;

        int start;
        int end;

        Expression ( ) { }

        virtual ~Expression ( ) { }

    };

    class BinaryExpression : public Expression {
      public:
        Type type = Type::BinaryExpression;

        Node* left;

        std::string op;

        Node* right;

        int start;
        int end;

        BinaryExpression ( Node* left, std::string op, Node* right, int start, int end ) : left(left), op(op), right(right), start(start), end(end) { }

        ~BinaryExpression ( ) {
            delete left;
            delete right;

        }

    };

    class LogicalExpression : public Expression {
      public:
        Type type = Type::LogicalExpression;

        Node* left;

        std::string op;

        Node* right;

        int start;
        int end;

        LogicalExpression ( Node* left, std::string op, Node* right, int start, int end ) : left(left), op(op), right(right), start(start), end(end) { }

        ~LogicalExpression ( ) {
            delete left;
            delete right;

        }

    };

    class Literal : public Expression {
      public:
        Type type;

        int start;
        int end;

        Literal ( ) { }

        virtual ~Literal ( ) { }

    };

    class Identifier : public Literal {
      public:
        Type type = Type::Identifier;

        std::string name;

        int start;
        int end;

        Identifier ( std::string name, int start, int end ) : name(name), start(start), end(end) { }

        ~Identifier ( ) { }

    };

    class Number : public Literal {
      public:
        Type type = Type::Number;

        float value;

        std::string raw;

        int start;
        int end;

        Number ( float value, std::string raw, int start, int end ) : value(value), raw(raw), start(start), end(end) { }

        ~Number ( ) { }

    };

    class Character : public Literal {
      public:
        Type type = Type::Character;

        char value;

        std::string raw;

        int start;
        int end;

        Character ( char value, std::string raw, int start, int end ) : value(value), raw(raw), start(start), end(end) { }

        ~Character ( ) { }

    };

    class String : public Literal {
      public:
        Type type = Type::String;

        std::string value;

        std::string raw;

        int start;
        int end;

        String ( std::string value, std::string raw, int start, int end ) : value(value), raw(raw), start(start), end(end) { }

        ~String ( ) { }

    };

}

#endif // NODE_H_