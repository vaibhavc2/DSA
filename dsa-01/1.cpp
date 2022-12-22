// #include <filename>  // Standard library header
// #include “filename”  // User defined header

#include <iostream>

// #include is a preprocessor directive
// it copies all the code in the mentioned file in this file before compiling by the preprocessor

using namespace std;
// a namespace contains different templates and functions
/*
Detailed explanation about namespaces in cpp:
A namespace is a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it. Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries. All identifiers at namespace scope are visible to one another without qualification. Identifiers outside the namespace can access the members by using the fully qualified name for each identifier, for example std::vector<std::string> vec;, or else by a using Declaration for a single identifier (using std::string), or a using Directive for all the identifiers in the namespace (using namespace std;). Code in header files should always use the fully qualified namespace name.
*/

// Command line arguments in cpp

int main(int argc, char const *argv[])
{
    cout << "You have entered " << argc << " argument(s) in the command line." << endl;
    // argc : number of arguments entered in the command line.
    // argv[] : is array of all the arguments given in the command line.
    cout << "The memory location address (referenced by 'argv'): " << argv << endl
         << "The list of arguments entered: " << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }

    return 0;
}