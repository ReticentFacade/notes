#include<bits/stdc++.h>
using namespace std;

// int f;

int test() {
  int f = 2; 
  return f;
}

int f = 12;
int main() {
  f = 1;
  int b = 2;

  cout << f << endl;

  // Re-definining in another scope: 
  {
    int f = 10;
    cout << f << endl;
  }

  return 0;
}
