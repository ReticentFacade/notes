#include<bits/stdc++.h> 
using namespace std;

class Integer {
  int m, n;
  public: 
  Integer(void); // constructor declaration -> YOU CAN DEFINE IT OUTSIDE THE CLASS AS WELL AS INSIDE THE CLASS.
};

Integer::Integer(void) {
  cout << "Constructor called" << endl;
  m = 0; 
  n = 0; 
}

int main() {
  Integer a; // IMPLICIT CALL 
  Integer c = Integer(); // EXPLICIT CALL

  return 0;
}
