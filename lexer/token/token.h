#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <unordered_map>

using namespace std;

namespace Token {
    enum class Type {
        Identifier,
        Float,
        Integer,
        String,
        Character,

        BinaryOperator,
        LogicalOperator,

        EndOfFile,

    };

    const std::unordered_map<std::string, Type> Reserved = {
        { "and", Type::LogicalOperator },
        { "or", Type::LogicalOperator },

    };

    class Token {
      public:
        Type type;

        std::string lexeme;

        int start;
        int end;

        Token ( Type type, std::string lexeme, int start, int end ) : type(type), lexeme(lexeme), start(start), end(end) { }

        ~Token ( ) { }

    };

}

#endif // TOKEN_H_