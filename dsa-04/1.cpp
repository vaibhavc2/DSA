#include <iostream>
#include <queue>
using namespace std;

// Priority Queue
// max heap & min heap

int main(int argc, char const *argv[])
{
    // max heap
    priority_queue<int> maxi;
    // whenever we will fetch an element from maxi, it will always return the maximum/greatest element

    maxi.push(1);
    maxi.push(9);
    maxi.push(5);
    maxi.push(2);

    cout << "Top of maxi: " << maxi.top() << endl;

    cout << "Size: " << maxi.size() << endl;

    // the following approach won't work here, but we can use for loop in other way!
    // for(int i:maxi)
    //     cout << i << " ";
    int n = maxi.size();
    for (int i = 0; i < n; i++) // we dont use maxi.size() here because while we keep poping at every iteration, the size keeps changing!
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }

    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;
    // whenever we will fetch an element from mini, it will always return the smallest/least element

    mini.push(69);
    mini.push(11);
    mini.push(919);
    mini.push(87);

    cout << "Top of mini: " << mini.top() << endl;
    cout << "Size of mini: " << mini.size() << endl;

    int x = mini.size();

    for (int i = 0; i < x; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    return 0;
}