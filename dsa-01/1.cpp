#include <iostream>
using namespace std;

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