#include<bits/stdc++.h> 
using namespace std;

class ABC; // = CALLED FORWARD CLASS DECLARATION - YOU'RE TELLING THE COMPILER THAT YOU'RE GOING TO CREATE A TEMPLATE; 

class XYZ {
  int data;
  public:
    void setValue(int value) {
      data = value;
    }

    friend void add(XYZ, ABC);
    // friend function declaration 
};

// NOW DEFINING (OR DECLARING??) CLASS ABC, like promised earlier: 
class ABC {
  int data; 
public: 
  void setValue(int value) {
    data = value;
  }
  friend void add(XYZ, ABC);
};

void add(XYZ obj1, ABC obj2) {
  cout << "Sum: " << obj1.data + obj2.data << endl;
}

//float mean(Test t) {
//  return float(t.a * t.b) / 2.0; 
//}

int main() {
  // Test t1;
  // t1.setValue();
  // cout << "mean val: " << mean(t1) << endl;

  XYZ x;
  ABC a;
  x.setValue(5);
  a.setValue(10);

  add(x, a);

  return 0;
}
