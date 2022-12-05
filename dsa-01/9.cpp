#include <iostream>
#include <vector>
using namespace std;

// use vector instead of dynamic array

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of subjects: ";
    cin >> n;
    vector<int> marks(n);
    // cout << endl << marks.size() << endl
    //      << endl;
    cout << endl;
    for (int i = 0; i < marks.size(); i++)
    {
        marks[i] = i + 1;
        cout << marks[i] << endl;
    }

    // int *arr = new int[6];
    // cout << sizeof([]arr) << endl;
    // delete[] arr;

    return 0;
}
