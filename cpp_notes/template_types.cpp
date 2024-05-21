#include<bits/stdc++.h>
using namespace std;

// Syntax of Template Function: template <typename T> 
// T myMax(T x, T y) {
//  return (x > y) ? x : y;
// } 
// IT IS NOT A MACRO REPLACEMENT. 
template <class T> 
T sum(int a, int b) {
  T ans;
  ans = a + b;
  return ans;
}

int main() {
  int i = 5, j = 6, k = 0;
  double f = 2.0, g = 2.5, h = 0;
  k = sum<int> (i , j);
  h = sum<double> (f, g);
  
  cout << k << endl;
  cout << h << endl;

  return 0;
}
