#include<bits/stdc++.h>
using namespace std; 

class Virus {
  float reproductionRate; // rate of reproduction, in %
  float resistance; // resistance against drugs, in %
  static const float defaultReproductionRate = 0.1;

  public: 
  Virus(float newResistance);
  Virus(float newReproductionRate, float newResistance);
  Virus* reproduce(float immunity);
  bool survive(float immunity);
};
