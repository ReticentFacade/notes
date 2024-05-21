#include<bits/stdc++.h>
using namespace std;

int tadd_ok(int x, int y) {
  int sum = x + y;
  return (sum - x == y) && (sum - y == x);
}

int main() {
  int x = 10;
  int y = 11;

  cout << tadd_ok(x, y) << endl;

  return 0;
}
