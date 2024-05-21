#include<bits/stdc++.h>
using namespace std;

int main() {
  int num[] = {1, 4, 8, 12, 16};
  int *a, *b;
  int i;
  a = num;
  b = num + 2;

  int m = 20;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "m: " << &m << endl;
  cout << "m: " << *(&m) << endl;

  i = *a + 1;
  cout << "i: " << i << endl;

  return 0;
}
