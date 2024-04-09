#include<bits/stdc++.h>
#include "Virus.h"
using namespace std;

// Constructor Definition:
Virus::Virus(float newResistance) {
  reproductionRate = defaultReproductionRate;
  resistance = newResistance;
}

// Constructor Definition:
Virus::Virus(float newReproductionRate, float newResistance) {
  reproductionRate = newReproductionRate;
  resistance = newResistance;
}

// Constructor can ALSO be defined AS: 
// Virus::Virus(float newReproductionRate, float newResistance) {
// reproductionRate(newReproductionRate), resistance(newResistance);
// }

// If this Virus Cell reproduces, returns a new offspring with identical genetic info, OTHERWISE returns NULL
Virus* Virus::reproduce(float immunity) {
  float prob = (float) rand() / RAND_MAX; // generate number between 0 and 1

  // If the patient's immunity is too strong, it cannot reproduce
  if (immunity > prob) return NULL;

  // Does the virus reproduce this time? 
  if (prob > reproductionRate) return NULL; // NO!

  return new Virus(reproductionRate, resistance); 
}

// METHOD DEFINITION:
// Returns true if this virus cell survives, given the patient's immunity:
bool Virus::survive(float immunity) {
  // If patient's immunity is too strong, then the cell cannot survive:
  if (immunity > resistance) return false;

  return true;
}

const float Virus::defaultReproductionRate;

int main() {
  

  return 0;
}
