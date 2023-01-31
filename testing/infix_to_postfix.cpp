#include<iostream>
using namespace std;

template <class T1 = char> class Stack
{
    int size;

public:
    pair<T1 *, int> top;
    T1 *ptr;
    Stack(int size)
    {
        this->size = size;
        top.second = -1;
        ptr = new T1[size];
        top.first = &ptr[top.second];
    }
    ~Stack()
    {
        delete[] ptr;
    }
    bool isEmpty()
    {
        if (top.second < 0)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top.second == size - 1)
        {
            return true;
        }
        return false;
    }
    void push(int value)
    {
        if (!isFull())
        {
            ptr[top.second + 1] = value;
            top.second++;
            top.first++;
        }
    }
    T1 pop()
    {
        if (!isEmpty())
        {
            T1 popped_element = ptr[top.second];
            top.second--;
            top.first--;
            return popped_element;
        }
        return -1;
    }
    T1 Top()
    {
        return *top.first;
    }
};

int precedence(char value){
    if(value == '+' || value == '-'){
        return 0;
    }
    else if (value == '*' || value == '/')
    {
        return 1;
    }
    else if (value == '^')
    {
        return 2;
    }
    else if (value == '(' || value == ')')
    {
        return 3;
    }
    return -1;
}

void infixToPostfix(char *const &infix , Stack<char> &stackobj)
{
    string postfix;
    for (int i = 0; infix[i]!=0; i++)
    {
        if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/' && infix[i] != '^' && infix[i] != '(' && infix[i] != ')')
        {
            postfix += infix[i];
        }
        else
        {
            char charAtTopStack = stackobj.Top();
            if (stackobj.isEmpty() || infix[i]=='(')
            {
                stackobj.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (charAtTopStack != '(')
                {
                    char popped_ele = stackobj.pop();
                    postfix += popped_ele;
                    charAtTopStack = stackobj.Top();
                }
                char popped_ele = stackobj.pop();
                // postfix += popped_ele;
            }
            else
            {
                charAtTopStack = stackobj.Top();
                char charAtInfix = infix[i];

                int precedenceStack = precedence(charAtTopStack);
                int precedenceInfix = precedence(charAtInfix);

                if(precedenceInfix>precedenceStack || precedenceStack == 3)
                {
                    stackobj.push(infix[i]);
                }
                else if (precedenceInfix == 2 && precedenceStack == 2)
                {
                    stackobj.push(infix[i]);
                }
                else if(precedenceInfix<=precedenceStack)
                {
                    while (!stackobj.isEmpty() && precedenceInfix <= precedenceStack && charAtTopStack!='(')
                    // if (!stackobj.isEmpty())
                    // while (precedenceInfix > precedence(*stackobj.top.first))
                    {
                        char popped_ele = stackobj.pop();
                        postfix += popped_ele;
                        charAtTopStack = stackobj.Top();
                        precedenceStack = precedence(charAtTopStack);
                        // precedenceInfix = precedence(charAtInfix);
                    }
                    stackobj.push(infix[i]);
                }
            }
        }
    }
    while (!stackobj.isEmpty())
    {
        char popped_ele = stackobj.pop();
        postfix += popped_ele;
    }
    cout << postfix << endl;
}
int main(int argc, char const *argv[])
{
    Stack stack(100);
    char *arr = new char[100];
    cout << "Enter a infix expression: ";
    cin.getline(arr, 100);
    infixToPostfix(arr, stack);
    delete[] arr;
    return 0;
}