#include <iostream>
#include <queue>

using namespace std;

// Queue works on the concept of FIFO: First in , First out.

int main(int argc, char const *argv[])
{
    queue<string> q;
    q.push("Hello");
    q.push("I");
    q.push("am");
    q.push("coming");

    cout << "Size: " << q.size() << endl;
    cout << "Front: " << q.front() << endl;

    q.pop();

    cout << "Front: " << q.front() << endl;

    cout << "Size after pop: " << q.size() << endl;

    return 0;
}