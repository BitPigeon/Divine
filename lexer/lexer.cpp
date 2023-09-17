#include "lexer.h"

std::vector<Token::Token*> Lexer::tokenize ( const std::string& code ) {
    src = code;
    pos = 0;

    tokens.clear();

    while ( pos < src.size() ) {
        if ( std::isalpha(src[pos]) || src[pos] == '_' ) {
            std::string lexeme;

            while ( pos < src.size() && ( std::isalnum(src[pos]) || src[pos] == '_' ) ) {
                lexeme += src[pos];

                pos++;

            }

            auto reserved = Token::Reserved.find(lexeme);

            Token::Type type;

            if ( reserved != Token::Reserved.end() ) {
                type = reserved->second;

            } else {
                type = Token::Type::Identifier;

            }

            tokens.push_back(new Token::Token(type, lexeme, pos - lexeme.size(), pos));

        } else if ( std::isdigit(src[pos]) ) {
            std::string lexeme;

            while ( pos < src.size() && ( std::isdigit(src[pos]) || ( pos + 1 < src.size() && std::isdigit(src[pos + 1]) && lexeme.find('.') == std::string::npos && src[pos] == '.' ) ) ) {
                lexeme += src[pos];

                pos++;

            }

            Token::Type type;

            if ( lexeme.find('.') == std::string::npos ) {
                type = Token::Type::Integer;

            } else {
                type = Token::Type::Float;

            }

            tokens.push_back(new Token::Token(type, lexeme, pos - src.size(), pos));

        } else if ( src[pos] == '"' || src[pos] == '\'' ) {
            char delimiter = src[pos];

            std::string lexeme(1, delimiter);

            while ( pos < src.size() && src[pos] != delimiter ) {
                lexeme += src[pos];

                pos++;

            }

            if ( src[pos] == delimiter ) {
                lexeme += src[pos];

                pos++;

            }

            Token::Type type;

            if ( delimiter == '"' ) {
                type = Token::Type::String;

            } else {
                type = Token::Type::Character;

            }

            tokens.push_back(new Token::Token(type, lexeme, pos - src.size(), pos));

        } else if ( src[pos] == '+' || src[pos] == '-' || src[pos] == '*' || src[pos] == '/' ) {
            tokens.push_back(new Token::Token(Token::Type::BinaryOperator, std::string(1, src[pos]), pos, pos + 1));

            pos++;

        } else if ( src[pos] == '>' || src[pos] == '<' || src[pos] == '=' ) {
            tokens.push_back(new Token::Token(Token::Type::ComparisonOperator, std::string(1, src[pos]), pos, pos + 1));

            pos++;

        }

    }

    tokens.push_back(new Token::Token(Token::Type::EndOfFile, "", pos, pos));

    return tokens;

}