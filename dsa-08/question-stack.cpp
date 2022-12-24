#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    pair<char, char> b1;
    pair<char, char> b2;
    pair<char, char> b3;
    stack<char> st;

    Solution()
    {
        b1.first = '(';
        b1.second = ')';

        b2.first = '{';
        b2.second = '}';

        b3.first = '[';
        b3.second = ']';
        // st = new stack<char>;
    }

    // ~Solution()
    // {
    //     delete[] st;
    // }

    bool isBalanced(char const* const& str)
    {
        char const* ptr = str;
        for (; *ptr != '\0'; ptr++)
        {
            if (*ptr == b1.first || *ptr == b2.first || *ptr == b3.first)
            {
                st.push(*ptr);
            }
            else if (!(st.empty()))
            {
                if (isMirrorImage(st.top(), *ptr))
                {
                    // if (st.empty())
                    // {
                    //     return false;
                    // }
                    // else
                    // {
                    //     st.pop();
                    // }
                    st.pop();
                }
                else if (!(isMirrorImage(st.top(), *ptr)))
                {
                    return false;
                }
            }
        }

        if (st.empty())
        {
            return true;
        }
        return false;
    }

    bool isMirrorImage(char& top, char const& itr_char)
    {
        if ((top == b1.first && itr_char == b1.second) || (top == b2.first && itr_char == b2.second) || (top == b3.first && itr_char == b3.second))
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char const str[] = "[()]{}{[()()]()}";

    Solution sol;
    if(sol.isBalanced(str))
    {
        cout << "BALANCED" << endl;
    }
    else
    {
        cout << "NOT BALANCED" << endl;
    }
    // int x = 4;
    // int* const ptr2 = &x;
    // int *const * const ptr3 = &ptr2;
    // (**ptr3)++;
    // int * iterating_ptr = ptr2;
    // iterating_ptr++;

    // char const *const string = "Vaibhav";
    // char const *string2 = (char const*)"Vaibhav";
    // int* arr = {0};
    // int array[] = {1,2,3,4,5};
    // // string2[1] = 'x';
    // // cout << string2 << endl;
    // char name[] = "Arnav";
    // name[2] = 'v';
    // cout << name << endl;
    // char const*const name2 = "VC";
    return 0;
}