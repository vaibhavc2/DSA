#include<iostream>
using namespace std;

int main() {
  char st[] = "ABCD";
  for(int i = 0; st[i] != '\0'; i++) {
     cout << st[i] << *(st)+i << *(i+st) << i[st];
  }
  char ch = 'a';
  cout << endl;
  cout << ++ch << endl;
  cout << ch++ << endl;
  int x = 5;
  // the following will always be interpreted as int, impicit conversion of 'char' to 'int' takes place when cout is given char with '+' or '-'
  cout << ch + x << endl; // prints int
  cout << ch + 2 << endl; // prints int
  cout << ch + 'B' << endl; // prints int
  cout << 'd' - ch << endl; // prints int
  // But the following way ensures that it is char
  char l = ch + x;
  char m = ch + 2;
  char n = ch + 'B';
  char o = 'd' - ch;
  cout << l << " " << m << " " << n << " " << o << endl; // prints char
  // OR we can also do this:
  cout << (char)(ch + 'B') << endl; // explicit conversion to char
  // BUT, the following will still print 'int'
  cout << (char)65 + char(59) << endl;
  return 0;
}