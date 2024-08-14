#include <iostream>
#include <string>
#include <vector>

enum TokenType {
    NUMBER,
    OPERATOR,
    PARENTHESIS
};

class Token {
public:
    TokenType type;
    std::string value;

    Token(TokenType t, const std::string& val) : type(t), value(val) {}
};

std::vector<Token> tokenize(std::string chaine)
{
    std::vector<Token> tokens;
    for (size_t i = 0; i < chaine.size(); i++)
    {
        if (chaine[i] == ' ')
        {
            continue; 
        }

        if (std::isdigit(chaine[i]))
        {
            std::string number;
            while (i < chaine.size() && std::isdigit(chaine[i])) {
                number += chaine[i];  
                i++;
            }
            i--; 
            tokens.push_back(Token(NUMBER, number));
        }
        else if (chaine[i] == '+' || chaine[i] == '-' || chaine[i] == '*' || chaine[i] == '/') {
            tokens.push_back(Token(OPERATOR, std::string(1, chaine[i])));
        }
        else if (chaine[i] == '(' || chaine[i] == ')') {
            tokens.push_back(Token(PARENTHESIS, std::string(1, chaine[i])));
        }
    }
    return tokens; 
}

int main()
{
    std::vector<Token> tokens = tokenize("12 + 34 - (56 * 78)");

    for (const auto& token : tokens) {
        std::cout << "Token(Type: ";
        switch (token.type) {
        case NUMBER: std::cout << "NUMBER"; break;
        case OPERATOR: std::cout << "OPERATOR"; break;
        case PARENTHESIS: std::cout << "PARENTHESIS"; break;
        }
        std::cout << ", Value: " << token.value << ")" << std::endl;
    }

    return 0;
}
