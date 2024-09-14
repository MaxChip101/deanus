#include <iostream>
#include <string>

using namespace std;

string tokenize(string code) {

    string tokened = "";

    bool key_token = 0;

    for (int i = 0; i < code.length(); i++) {

       
        switch (code[i]) {
            case '.':
                tokened += " [PERIOD] ";
                key_token = 1;
                break;
            case ' ':
                tokened += " [SPACE] ";
                key_token = 1;
                break;
            case ';':
                tokened += " [SEMI] ";
                key_token = 1;
                break;
            case ',':
                tokened += " [COMMA] ";
                key_token = 1;
                break;
            case ':':
                tokened += " [COLLON] ";
                key_token = 1;
                break;
            case '+':
                tokened += " [PLUS] ";
                key_token = 1;
                break;
            case '-':
                tokened += " [MINUS] ";
                key_token = 1;
                break;
            case '*':
                tokened += " [MULTIPLY] ";
                key_token = 1;
                break;
            case '/':
                tokened += " [DIVIDE] ";
                key_token = 1;
                break;
            case '(':
                tokened += " [LEFT_PARENTHESIS] ";
                key_token = 1;
                break;
            case ')':
                tokened += " [RIGHT_PARENTHESIS] ";
                key_token = 1;
                break;                
            case '[':
                tokened += " [LEFT_BRACKET] ";
                key_token = 1;
                break;
            case ']':
                tokened += " [RIGHT_BRACKET] ";
                key_token = 1;
                break;
            case '{':
                tokened += " [LEFT_BRACE] ";
                key_token = 1;
                break;
            case '}':
                tokened += " [RIGHT_BRACE] ";
                key_token = 1;
                break;
            case '&':
                tokened += " [AMPERSAND] ";
                key_token = 1;
                break;
            case '^':
                tokened += " [CARAT] ";
                key_token = 1;
                break;
            case '%':
                tokened += " [PERCENT] ";
                key_token = 1;
                break;
            case '\"':
                tokened += " [QUOTE] ";
                key_token = 1;
                break;
            case '\'':
                tokened += " [APOSTROPHE] ";
                key_token = 1;
                break;
            case '=':
                tokened += " [EQUAL] ";
                key_token = 1;
                break;
            case '$':
                tokened += " [DOLAR] ";
                key_token = 1;
                break;
            case '#':
                tokened += " [HASHTAG] ";
                key_token = 1;
                break;
            case '@':
                tokened += " [AT] ";
                key_token = 1;
                break;
            case '!':
                tokened += " [EXCLAMATION] ";
                key_token = 1;
                break;
            case '<':
                tokened += " [LESS_THAN] ";
                key_token = 1;
                break;
            case '>':
                tokened += " [GREATER_THAN] ";
                key_token = 1;
                break;
            case '?':
                tokened += " [QUESTION] ";
                key_token = 1;
                break;
            case '\\':
                tokened += " [BACKSLASH] ";
                key_token = 1;
                break;
        }

        if (!key_token) {
            tokened += code[i];
        }

        key_token = 0;
        
        
    }

    return tokened;
}

int main(int argc, char *argv[]) {

    cout << tokenize("i'm a skibidi (sigma)") << "\n";

    for (int arg = 0; arg <= argc; arg++) {

    }
    std::cout << "Hello, World!" << "\n";
    return 0;
}
