#include<bits/stdc++.h> 
using namespace std;

template <class T, class U> 
bool areEqual(T a, U b) {
  return (a == b);
}

int main() {
  cout << areEqual(10, 10) << endl;
  cout << areEqual(10, 10.9) << endl;
  cout << areEqual(10, 10.0) << endl;

  return 0;
}
