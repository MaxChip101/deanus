#include <string>
#include <unordered_map>

#include "syntax.h"

using namespace std;

const char key_characters[] = {
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '{', '}', '[', ']', '\\', ':', ';', '\"', '\'', '<', ',', 
    '>', '.', '?', '/', ' ', '\n'
};

const string key_tokens[] = {
    "=[EXCLAMATION]=", "=[AT]=", "=[HASHTAG]=", "=[DOLLAR]=", "=[PERCENT]=", "=[CARAT]=", "=[AMPERSAND]=", "=[MULTIPLY]=", 
    "=[LEFT_PARENTHESIS]=", "=[RIGHT_PARENTHESIS]=", "=[MINUS]=", "=[PLUS]=", "=[EQUAL]=", "=[LEFT_BRACE]=", "=[RIGHT_BRACE]=",
    "=[LEFT_BRACKET]=", "=[RIGHT_BRACKET]=", "=[BACKSLASH]=", "=[COLON]=", "=[SEMI]=", "=[QUOTE]=", "=[APOSTROPHE]=", "=[LESS_THAN]=",
    "=[COMMA]=", "=[GREATER_THAN]=", "=[PERIOD]=", "=[QUESTION]=", "=[SLASH]=", "=[SPACE]=", "=[NEW_LINE]="
};

string getToken(const char character) {
    for (int i = 0; i < sizeof(key_characters) / sizeof(key_characters[0]); i++) {
        if (key_characters[i] == character) {
            return key_tokens[i];
        }
    }
    return "`";
}

char getChar(const string token) {
    for (int i = 0; i < sizeof(key_tokens) / sizeof(key_tokens[0]); i++) {
        if (key_tokens[i] == token) {
            return key_characters[i];
        }
    }
    return '`';
}

bool charInSyntax(const char character) {
    for (int i = 0; i < sizeof(key_characters) / sizeof(key_characters[0]); i++) {
        if (key_characters[i] == character) {
            return 1;
        }
        
    }
    return 0;
}

bool tokenInSyntax(string token) {
    for (int i = 0; i < sizeof(key_tokens) / sizeof(key_tokens[0]); i++) {
        if (key_tokens[i] == token) {
            return 1;
        }
        
    }
    return 0;
}