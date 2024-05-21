#include<bits/stdc++.h> 
using namespace std;

// HETEROGENEOUS TEMPLATE OVERLOADING
template <class T, int N> 
T fixedMultiply(T val){
  return val * N;
}

int main() {
  cout << fixedMultiply<int, 2>(10) << endl;
  cout << fixedMultiply<int, 3>(10) << endl;

  return 0;
}
