#include <iostream>
using namespace std;
int fib =0;
int n=5;

int main() {
  if (n<=1)return n;
  n--;
  main();
  fib+=main();
  n--;
  fib+=main();
  cout<<fib;
}
