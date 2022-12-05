#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 6;
    while (1)
    {
        switch (n)
        {
        case 1:
            cout << "1" << endl;
            break;
        case 2:
            cout << "2" << endl;
            break;
        case 3:
            cout << "3" << endl;
            break;
        default:
            cout << "default" << endl;
            break;
        }
        exit(0);
    }
    return 0;
}