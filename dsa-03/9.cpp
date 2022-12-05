#include <iostream>
#include <stack>
using namespace std;

// this works on the principle of LIFO : LAST in, FIRST out

int main(int argc, char const *argv[])
{
    stack<string> s;
    s.push("vaibhav");
    s.push("chopra");
    s.push("kaintt");

    cout << "top: " << s.top() << endl;
    s.pop(); // pop removes the Top element, next one is now at the top
    cout << "top: " << s.top() << endl;

    cout << "size: " << s.size() << endl;
    s.pop();
    s.pop();
    // after poping all the elements, there is nothing left in the stack, hence empty returns true (1)
    cout << "Empty? " << s.empty() << endl;

    // we cannot print a stack using for loop. printing is done using other ways.

    // for(int i:s)
    //     cout << i << " ";

    // cout << endl;
    return 0;
}