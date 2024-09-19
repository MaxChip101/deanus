#include <string>
#include <vector>

#include "tokenHandler.h"

using namespace std;

const char key_characters[] = {
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '{', '}', '[', ']', '\\', ':', ';', '\"', '\'', '<', ',', 
    '>', '.', '?', '/', ' ', '\n'
};

bool charInSyntax(const char character) {
    for (size_t i = 0; i < sizeof(key_characters) / sizeof(key_characters[0]); i++) {
        if (key_characters[i] == character) {
            return true;
        }
        
    }
    return false;
}

vector<string> tokenize(const string code) {

    string temp = "";
    vector<string> tokens;

    for (string::size_type i = 0; i < code.length(); i++) {
        
        if(charInSyntax(code[i])) {
            if((temp != "") || (i == code.length() - 1)) {
                tokens.push_back(temp);
                temp = "";
            }
            tokens.push_back(string(1, code[i]));
        } else {
            temp += code[i];
        }
    }

    return tokens;
}