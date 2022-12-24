// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
    string op_str = "/*+-^()";
    stack<char> op_stack;
public:

    string infixToPostfix(string& str)
    {
        string answer;
        for (int i = 0; i < str.size(); i++)
        {
            if (isValidOperator(str[i]))
            {
                if (op_stack.empty())
                {
                    op_stack.push(str[i]);
                }
                else if (str[i] == ')')
                {
                    while (op_stack.top() != '(')
                    {
                        answer.push_back(op_stack.top());
                        op_stack.pop();
                    }
                    op_stack.pop();
                }
                else if (hasHigherPrecedence(str[i]) || ((str[i] == '^') && (op_stack.top() == '^')))
                {
                    op_stack.push(str[i]);
                }
                else if (!(hasHigherPrecedence(str[i])))
                {
                    if (op_stack.top() == '(')
                    {
                        op_stack.push(str[i]);
                    }
                    else
                    {
                        while (!(op_stack.empty()) && !(hasHigherPrecedence(str[i])) && op_stack.top() != '(')
                        {
                            answer.push_back(op_stack.top());
                            op_stack.pop();
                        }
                        op_stack.push(str[i]);
                    }
                }
            }
            else
            {
                answer.push_back(str[i]);
            }
        }

        while (!(op_stack.empty()))
        {
            answer.push_back(op_stack.top());
            op_stack.pop();
        }        
        
        return answer;
    }

    bool isValidOperator(char& ch)
    {
        // Linear Search:
        for (int i = 0; i < op_str.size(); i++)
        {
            if (ch == op_str[i])
            {
                return true;
            }
        }
        return 0;
    }

    bool hasHigherPrecedence(char& ch)
    {
        if (opNumber(ch) > opNumber(op_stack.top()))
        {
            return 1;
        }
        return 0;
    }

    int opNumber(char c)
    {
        if (c == '(')
        {
            return 3;
        }
        else if (c == '^')
        {
            return 2;
        }
        else if (c == '/' || c == '*')
        {
            return 1;
        }
        else if (c == '+' || c == '-')
        {
            return 0;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cout << "Enter string: " << endl;
    getline(cin, str);

    Solution sol;
    string ans = sol.infixToPostfix(str);
    cout << ans << endl;

    return 0;
}