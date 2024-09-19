#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "key_words.h"

string parser(vector<string> tokens) {


    bool blockcomment = false;
    bool linecomment = false;

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
                if (tokens.at(i) == "import") {
                    bool foundpackage = true;
                    while (foundpackage) {
                        
                    }
                    
                }
                
                cout << tokens.at(i) << endl;
            }
        }
    }

    return "null";
}
