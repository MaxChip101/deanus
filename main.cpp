#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <unistd.h>

#include "syntax.h"

using namespace std;




string lexer(vector<string> tokens) {
    cout << "lexing";
}

// TODO: make a function that takes in the tokens and makes it have logic to do other stuff

vector<string> split(string str, char separator) {
    vector<string> v;
    string temp = "";
    for (int i = 0; i <= str.length(); i++) {
        if(str[i] == separator && temp != "" || i == str.length()) {
            v.push_back(temp);
            temp = "";
        } else if (str[i] != separator) {
            temp += str[i];
        }
    }
    return v;
}

vector<string> tokenize(string code) {

    string tokened = "";

    for (int i = 0; i < code.length(); i++) {
        
        if(charInSyntax(code[i])) {
            tokened += getToken(code[i]);
        } else {
            tokened += code[i];
        }
    }

    return split(tokened, '=');
}


int main(int argc, char **argv) {

    cout << "test \n";

    //string cwd = argv[0];
    /*
    char cwd[1024];
    string tempcwd = getcwd(cwd, sizeof(cwd));
    string full_cwd = tempcwd + "/" + argv[1];

*/
    vector<string> tokens = tokenize("skibidi, sigma; sigma no cap # real");

    

    for(int i = 0; i < tokens.size(); i++) {
        cout << tokens.at(i) << " ";
    }

    /*
    lexer(tokenize("i'm a. skibidi (sigma)"));

    cout << tokenize("i'm a. skibidi (sigma)").at(0) << "\n";

    */

    for (int arg = 0; arg <= argc; arg++) {
        cout << argv[arg] << ", ";
    }

    cin.get();

    return 0;
}
