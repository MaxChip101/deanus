#include <string>

using namespace std;

string libraries = "";

void addLibrary(const string library_name, const string library_variable) {
    libraries += "#include \"" + library_name + ".h\"\n";
}

void addVariable(const string variable_name, const string value) {
    
}

void addArray(const string array_name, const int dimensions, const string value) {
    
}

void addFunction(const string function_name, const string return_type) {
    
}