#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fstream>

#include "tokenHandler.h"
#include "compiler.h"

using namespace std;

vector<string> tokenize(const string code) {

    string tokened_string = "";
    vector<string> tokens;
    string temp = "";

    for (int i = 0; i < code.length(); i++) {
        
        if(charInSyntax(code[i])) {
            tokened_string += "=" + getToken(code[i]) + "=" ;
        } else {
            tokened_string += code[i];
        }
    }

    for (int i = 0; i <= tokened_string.length(); i++) {
        if(tokened_string[i] == '=' && temp != "" || i == tokened_string.length()) {
            tokens.push_back(temp);
            temp = "";
        } else if (tokened_string[i] != '=') {
            temp += tokened_string[i];
        }
    }

    return tokens;
}


int main(int argc, char **argv) {
    
    
    if(argc == 1) {
        cerr << "File Error, no input file";
        return 1;
    }

    char cwd[1024];
    string tempcwd = getcwd(cwd, sizeof(cwd));
    
    string full_cwd = tempcwd + "/" + argv[1];

    ifstream deanFile(full_cwd.c_str());
    if(!deanFile.is_open()) {
        cerr << "File Error, file does not exist: \'" << full_cwd << "\'\n";
        return 1;
    }

    string ln;
    string content;

    while(getline(deanFile, ln)) {
        content += ln;
        content.push_back('\n');
    }

    vector<string> tokens = tokenize(content);
    parser(tokens);

    for(int i = 0; i < tokens.size(); i++) {
        cout << tokens.at(i) << " ";
    }

    for (int arg = 0; arg <= argc; arg++) {
        cout << argv[arg] << ", ";
    }
    
    return 0;
}