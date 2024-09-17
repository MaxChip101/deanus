#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>

std::string getToken(const char character);

char getChar(const std::string token);

bool charInSyntax(const char character);

bool tokenInSyntax(const std::string token);

#endif