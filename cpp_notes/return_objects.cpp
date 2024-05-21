#include<bits/stdc++.h> 
using namespace std;

class Matrix {
  int m[3][3];
  public: 
  void read(void) {
    int d= 3;

    cout << "Enter the elements: " << endl;

    for (int i = 0; i < d; i++) {
      for (int j = 0; j < d; j++) {
        cout << "m[" << i << "][" << j << "] ";
        cin >> m[i][j];
      }
    }
  }

  void display(void) {
    int d = 3;
    for (int i = 0; i < d; i++) {
      for (int j = 0; j < d; j++) {
        cout << m[i][j] << ", ";
      }
      cout << endl;
    }
  }

  // Returning Matrix [i.e., OBJECT AS RETURN TYPE]
  friend Matrix transpose(Matrix);
};

Matrix transpose(Matrix m1) {
  Matrix m2; // Another matrix declared to store the transpose in 

  int d = 3;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      m2.m[i][j] = m1.m[j][i];
    }

    return m2;
  }
}

int main() {
  Matrix m1, m2;
  m1.read();
  cout << "Input matrix" << endl;
  
  m2 = transpose(m1);
  cout << "Output matrix" << endl;
  m2.display();

  return 0;
}
