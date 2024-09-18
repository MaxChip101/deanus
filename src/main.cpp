#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <fstream>

#include "key_words.h"
#include "syntax.h"
#include "compiler.h"

using namespace std;

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
                cout << tokens.at(i) << endl;
            }
        }
    }

    return "null";
}

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
            tokened += "=" + getToken(code[i]) + "=" ;
        } else {
            tokened += code[i];
        }
    }

    return split(tokened, '=');
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
/*

    for(int i = 0; i < tokens.size(); i++) {
        cout << tokens.at(i) << " ";
    }

    for (int arg = 0; arg <= argc; arg++) {
        cout << argv[arg] << ", ";
    }
  */  
    return 0;
}