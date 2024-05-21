#include "Patient.h"
using namespace std;

// DYNAMIC OBJECT CREATION:
Patient::Patient(float initImmunity, int initNumVirusCells) {
  float resistance;
  immunity = initImmunity;

  for (int i = 0; i < initNumVirusCells; i++) {
    // randomly generate resistance, between 0.0 and 1.0
    resistance = (float) rand() / RAND_MAX;

    virusPop[i] = new Virus(resistance);
  }

  numVirusCells = initNumVirusCells;
}

// Using Dynamically allocated objects: 
bool Patient::simulateStep() {
  Virus* virus;
  bool survived = false;

  // ...
  for (int i = 0; i < numVirusCells; i++) {
    virus = virusPop[i];

    survived = virus->survive(immunity);
    if (survived) {
      // ...
    } else {
      // ...
    }
    // ...
  }
}

// DESTRUCTOR IS AUTOMATICALLY called:
Patient::~Patient() {
  for (int i = 0; i < numVirusCells; i++) {
    delete virusPop[i];
  }
}

bool Patient::checkRep() {
  return (immunity >= 0.0) && (immunity < 1.0) && 
    (numVirusCells >= 0) &&
    (numVirusCells < MAX_VIRUS_POP);
} // the purpose of this function is to PRESERVE REPRESENTATIONAL INVARIANTS of Patient Class :)

int main() {
  Patient* p = new Patient(0.1, 5);
  // ... 
  delete p;

  return 0;
}
