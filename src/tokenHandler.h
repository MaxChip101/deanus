#ifndef TOKENHANDLER_H
#define TOKENHANDLER_H

#include <string>

std::string getToken(const char character);

char getChar(const std::string token);

bool charInSyntax(const char character);

bool tokenInSyntax(const std::string token);

std::vector<std::string> tokenize(const std::string code);

#endif
