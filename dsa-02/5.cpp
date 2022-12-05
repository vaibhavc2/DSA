#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int amount;
    cout << "Enter amount: ";
    cin >> amount;
    int rem = amount;
    int deno[] = {100, 50, 20, 1};
    for (int i = 0; i < 4; i++)
    {
        switch (deno[i])
        {
        case 100:
            cout << endl
                 << "Notes of Rs. " << deno[i] << " are: " << rem / deno[i];
            rem = rem % deno[i];
            break;
        case 50:
            cout << endl
                 << "Notes of Rs. " << deno[i] << " are: " << rem / deno[i];
            rem = rem % deno[i];
            break;
        case 20:
            cout << endl
                 << "Notes of Rs. " << deno[i] << " are: " << rem / deno[i];
            rem = rem % deno[i];
            break;
        case 1:
            cout << endl
                 << "Notes of Rs. " << deno[i] << " are: " << rem / deno[i];
            rem = rem % deno[i];
            break;
        }
    }
    return 0;
}