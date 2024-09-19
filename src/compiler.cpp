#include <string>
#include <iostream>
#include <vector>
#include "tokenHandler.h"

using namespace std;

string libraries = "";

void addLibrary(const string library_name, const string library_variable) {
    libraries += "#include \"" + library_name + ".h\"\n";
}

string parser(const vector<string> tokens) {

    bool blockcomment = false;
    bool linecomment = false;

    string buffer = "";

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
            if(!linecomment && ! blockcomment) {
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
                
                cout << "(" << tokens.at(i) << ")" << endl;
            }
        }
    }

    return "null";
}