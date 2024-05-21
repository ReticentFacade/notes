#include<bits/stdc++.h>
using namespace std;

class Binary {
  string s;
  public: 
  void read(void) {
    cout << "Enter a Binary number" << endl;
    cin >> s;
  }

  void checkBinary(void) {
    for (int i = 0; i < s.length(); i++) {
      if (s.at(i) != '0' || s.at(i) != '1') {
        cout << "Wrong binary number" << endl;
        exit(0);
      }
    }
  }

  void onesComplement(void) {
    checkBinary();
    for (int i = 0; i < s.length(); i++) {
      if (s.at(i) == '0') s.at(i) = '1'; 
      else s.at(i) = '0';
    }
  }

  void display(void) {
    onesComplement();
    cout << "1s complement: " << s << endl;
  }
};

int main() {
  Binary b;
  b.read();
  b.checkBinary();
  b.onesComplement();
  b.display();

  return 0;
}
