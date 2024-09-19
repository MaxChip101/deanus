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

    for(int i = 0; i < tokens.size(); i++) {
        if(tokens.at(i) == getToken('/') && tokens.at(i+1) == getToken('/') && !linecomment && !blockcomment) {
            linecomment = true;
            i+=1;
        } else if (tokens.at(i) == getToken('/') && tokens.at(i+1) == getToken('*') && !blockcomment && !linecomment) {
            blockcomment = true;
            i+=1;
        } else if (tokens.at(i) == getToken('*') && tokens.at(i+1) == getToken('/') && blockcomment) {
            blockcomment = false;
            i+=1;
        } else if(tokens.at(i) == getToken('\n') && linecomment) {
            linecomment = false;
        } else {
            if(!linecomment && ! blockcomment) {
                if (tokens.at(i) == "print") {
                    if(tokens.at(i+1) == getToken('(')) {
                        //TODO: make the parser remove any space that is not in a string
                    }
                }
                
                cout << tokens.at(i) << endl;
            }
        }
    }

    return "null";
}