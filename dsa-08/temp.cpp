#include <iostream>
#include <vector>
using namespace std;

// char*& gives error because here we need a const pointer for reference
void print(char* const& name)
{
    cout << name << endl;
}

int main(int argc, char const *argv[])
{
    char name[] = "Vaibhav";
    print(name);
    std::vector<char> s;
    s.push_back('c');
    s.push_back('d');
    s.pop_back();
    for(char i : s)
    {
        cout << i << endl;
    }
    return 0;
}