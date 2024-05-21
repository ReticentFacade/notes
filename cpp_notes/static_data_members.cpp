#include<bits/stdc++.h>
using namespace std;

class Test {
  int a; 
  public: 
  static int n; // declaration NOT definition -> memory is NOT allocated here.
                // inside the class, you CANNOT define a static member variable. 
                // You gotta do it outside the class only.
};

Test::n; // definition & memory allocation is happening here 

int main() {
  Test t;
  cout << t.n << endl;

  return 0;
}
