#include<bits/stdc++.h>
using namespace std;

int uadd_ok(unsigned x, unsigned y) {
  return ((x + y >= x) || (x + y >= y));
}

int main() {
  unsigned x = 20;
  unsigned y = 11;

  if (uadd_ok(x, y)) {
    printf("Adding %u and %u does NOT cause overflow.\n", x, y);
    cout << x + y << endl;
  } else {
    printf("Adding %u and %u CAUSES overflow.\n", x, y);
    cout << x + y << endl;
  }

  return 0;
}
