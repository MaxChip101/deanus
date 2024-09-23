#include <string>
#include <iostream>
#include <vector>
#include "tokenHandler.h"

using namespace std;

string libraries = "";

void addLibrary(const string library_name, const string library_variable) {
    libraries += "#include \"" + library_name + ".h\"\n";
}

vector<string> whitespace_remover(const vector<string> tokens) {
    bool in_string = false;
    bool in_character = false;
    vector<string> final_tokens;

    for(vector<string>::size_type i = 0; i < tokens.size(); i++) {
        if(tokens.at(i) == "\"") {
            if(!in_character) {
                in_string = !in_string;
            }
        }

        if(tokens.at(i) == "\'") {
            if(!in_string) {
                in_character = !in_character;
            }
        }

        if(in_string || in_character) {
            final_tokens.push_back(tokens.at(i));
        } else {
            if(tokens.at(i) != " " && tokens.at(i) != "\t") {
                final_tokens.push_back(tokens.at(i));
            }
        }
    }
    return final_tokens;
}

bool parser(const vector<string> input_tokens) {

    bool blockcomment = false;
    bool linecomment = false;

    string buffer = "";

    vector<string> tokens = whitespace_remover(input_tokens);

    for(vector<string>::size_type i = 0; i < tokens.size(); i++) {
        if(tokens.at(i) == "/" && tokens.at(i+1) == "/" && !linecomment && !blockcomment) {
            linecomment = true;
            i+=1;
        } else if (tokens.at(i) == "/" && tokens.at(i+1) == "*" && !blockcomment && !linecomment) {
            blockcomment = true;
            i+=1;
        } else if (tokens.at(i) == "*" && tokens.at(i+1) == "/" && blockcomment) {
            blockcomment = false;
            i+=1;
        } else if(tokens.at(i) == "\n" && linecomment) {
            linecomment = false;
        } else {
            // TODO: if it is a space then it will be deleted
            if(!linecomment && !blockcomment) {
                /*
                switch (tokens.at(i)) {
                case "print":
                    break;
                
                default:
                    break;
                }
                */
                if (tokens.at(i) == "print") {
                    if(tokens.at(i+1) == "(") {
                        //TODO: make the parser remove any space that is not in a string
                    }
                }
                
                cout << "(" << tokens.at(i) << ")";
            }
        }
    }

    return true;
}