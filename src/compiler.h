#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include <vector>

void addLibrary(const std::string library_name, const std::string library_variable);
std::string parser(const std::vector<std::string> tokens);


#endif