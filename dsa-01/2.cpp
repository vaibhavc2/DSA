#include <iostream>
using namespace std;

// cin>>,cin.get(), cin.getline(), getline(cin, .... ) difference and use:

int main()
{
    int ch;
    char name[60];
    string sname;
    // cout << "Enter a character: ";
    ch = cin.get(); // registers \n (enter) and ends taking input
    // ch = cin.getline(); // this is wrong because cin.getline is meant to be used only with c strings.
    // cin.getline() and getline() both end taking input at \n but both dont include \n in the input, whereas get() includes \n in the input.....
    // cin >> ch; // will not register other characters like tab, EOL ...
    // cin.functions to be used with character arrays (c style)
    // cin.get(name, 60);
    // cin.getline(name, 60);
    // getline(cin, sname); // use with c++ strings
    cout << endl
         << ch << endl;
    //  << ch << endl;
    return 0;
}