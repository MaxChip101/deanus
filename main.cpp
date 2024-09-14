#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> key_tokens {
    {'!', "=[EXCLAMATION]="},
    {'@', "=[AT]="},
    {'#', "=[HASHTAG]="},
    {'$', "=[DOLLAR]="},
    {'%', "=[PERCENT]="},
    {'^', "=[CARAT]="},
    {'&', "=[AMPERSAND]="},
    {'*', "=[MULTIPLY]="},
    {'(', "=[LEFT_PARENTHESIS]="},
    {')', "=[RIGHT_PARENTHESIS]="},
    {'-', "=[MINUS]="},
    {'+', "=[PLUS]="},
    {'=', "=[EQUAL]="},
    {'{', "=[LEFT_BRACE]="},
    {'}', "=[RIGHT_BRACE]="},
    {'[', "=[LEFT_BRACKET]="},
    {']', "=[RIGHT_BRACKET]="},
    {'\\', "=[BACKSLASH]="},
    {':', "=[COLON]="},
    {';', "=[SEMI]="},
    {'\"', "=[QUOTE]="},
    {'\'', "=[APOSTROPHE]="},
    {'<', "=[LESS_THAN]="},
    {',', "=[COMMA]="},
    {'>', "=[GREATER_THAN]="},
    {'.', "=[PERIOD]="},
    {'?', "=[QUESTION]="},
    {'/', "=[SLASH]="},
    {' ', "=[SPACE]="},
};

unordered_map<string, char> get_key_tokens {
    {"=[EXCLAMATION]=", '!'},
    {"=[AT]=", '@'},
    {"=[HASHTAG]=", '#'},
    {"=[DOLLAR]=", '$'},
    {"=[PERCENT]=", '%'},
    {"=[CARAT]=", '^'},
    {"=[AMPERSAND]=", '&'},
    {"=[MULTIPLY]=", '*'},
    {"=[LEFT_PARENTHESIS]=", '('},
    {"=[RIGHT_PARENTHESIS]=", ')'},
    {"=[MINUS]=", '-'},
    {"=[PLUS]=", '+'},
    {"=[EQUAL]", '='},
    {"=[LEFT_BRACE]=", '{'},
    {"=[RIGHT_BRACE]=", '}'},
    {"=[LEFT_BRACKET]=", '['},
    {"=[RIGHT_BRACKET]=", ']'},
    {"=[BACKSLASH]=", '\\'},
    {"=[COLON]=", ':'},
    {"=[SEMI]=", ';'},
    {"=[QUOTE]=", '\"'},
    {"=[APOSTROPHE]=", '\''},
    {"=[LESS_THAN]=", '<'},
    {"=[COMMA]=", ','},
    {"=[GREATER_THAN]=", '>'},
    {"=[PERIOD]=", '.'},
    {"=[QUESTION]=", '?'},
    {"=[SLASH]=", '/'},
    {"=[SPACE]=", ' '},
};

string tokenize(string code) {

    string tokened = "";

    bool key = 0;

    for (int i = 0; i < code.length(); i++) {
        
        switch (code[i]) {
            case '.':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case ' ':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case ';':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case ',':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case ':':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '+':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '-':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '*':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '/':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '(':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case ')':
                tokened += key_tokens[code[i]];
                key = 1;
                break;                
            case '[':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case ']':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '{':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '}':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '&':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '^':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '%':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '\"':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '\'':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '=':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '$':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '#':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '@':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '!':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '<':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '>':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '?':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
            case '\\':
                tokened += key_tokens[code[i]];
                key = 1;
                break;
        }

        if (!key) {
            tokened += code[i];
        }

        key = 0;  
    }

    return tokened;
}




int main(int argc, char *argv[]) {

    cout << tokenize("i'm a. skibidi (sigma)") << "\n";

    for (int arg = 0; arg <= argc; arg++) {

    }
    std::cout << "Hello, World!" << "\n";
    return 0;
}
