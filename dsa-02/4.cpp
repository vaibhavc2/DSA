#include <iostream>
using namespace std;

int totalDenominations(int n, int denomination)
{
    return n / denomination;
}

int main(int argc, char const *argv[])
{
    int amount;
    cout << "Enter amount: ";
    cin >> amount;
    int rem = amount;
    int denominations[4] = {100, 50, 20, 1};
    int notes[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        notes[i] = totalDenominations(rem, denominations[i]);
        cout << endl
             << "Notes of Rs. " << denominations[i] << " are: " << notes[i];
        rem = rem % denominations[i];
    }

    return 0;
}