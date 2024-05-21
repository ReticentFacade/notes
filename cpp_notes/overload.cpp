#include<bits/stdc++.h>
using namespace std;

int operate(int a, int b) {
  return (a + b);
}

double operate(double a, double b) {
  return (a / b);
}

int main() {
  int x = 5, y = 2;
  double m = 5.0, n = 2.0;
  cout << operate(x, y) << endl;
  cout << operate(m, n) << endl;

  return 0;
}
