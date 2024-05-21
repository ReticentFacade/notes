#include<bits/stdc++.h>
#include "Virus.h"
using namespace std;

#define MAX_VIRUS_POP 1000

class Patient {
  Virus* virusPop[MAX_VIRUS_POP];
  int numVirusCells;
  float immunity; // degree of immunity, in %

  bool checkRep();

  public:
  Patient(float initImmunity, init initNumViruses);
  ~Patient();
  void takeDrug();
  bool simulateStep();
};

void Patient::takeDrug() {
  assert(checkRep());
  // ...
  assert(checkRep());
}

Patient::Patient(float initImmunity) {
  // ...
  assert(checkRep());
}

int main() {
// STATIC OBJECT ALLOCATION:
  float initImmunity = 0.1;
  int initNumVirusCells = 5;

  Patient p(0.1, 5); // Calling the constructor
  p.takeDrug(); 
  // DELETING statically allocated objects -> Automatically Destroyed at the end of scope

// ---------------------------------

// Objects on HEAP:
  Patient* p = new Patient(0.1, 5); // `new` ~ malloc
  // ...
  delete p; // `delete` ~ free

  return 0;
}
