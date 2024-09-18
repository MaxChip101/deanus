#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <string>

std::string getToken(const char character);

char getChar(const std::string token);

bool charInSyntax(const char character);

bool tokenInSyntax(const std::string token);

#endif
