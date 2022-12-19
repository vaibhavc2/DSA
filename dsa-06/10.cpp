#include<iostream>
using namespace std;
void swap (char const* x, char const* y) 
{
  char const *t = x;
  x = y;
  y = t;
}

int main()
{
   char const* x = "ninjasquiz";
   char const* y = "codingninjas";
   char const* t = NULL;
   swap(x, y); // this swap() function is a fake function to confuse only. it can't swap because these pointers were sent to the function by value and not by reference, hence swap() creates separate 'x' and 'y' and swaps their values but in the main() function, there is no effect of it.
   cout<<x << " "<<y;
   t = x;
   x = y;
   y = t;
   // here the real swap has been done!!
   cout<<" "<<x<< " "<<y;
   return 0;
}