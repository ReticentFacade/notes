#include<bits/stdc++.h> 
using namespace std;

// NOTES FOR THIS FILE WRITTEN IN: `observer.md`

class AlarmListener {
  public: 
    virtual void alarm() = 0;
};

class SensorSystem {
  vector< AlarmListener * > listeners;
  public: 
    void attach(AlarmListener *al) {
      listeners.push_back(al);
    }

    void soundTheAlarm() {
      for (int i = 0; i < listeners.size(); i++) listeners[i]->alarm();
    }
};

class Lightening: public AlarmListener{
  public: 
    /* virtual */ void alarm() {
      cout << "Lights up" << endl;
    }
};

class Gates: public AlarmListener {
  public: 
    /*virtual*/ void alarm() {
      cout << "Gates closed" << endl;
    }
};

class CheckList {
  virtual void localize() {
    cout << "Establish a perimeter" << endl;
  }

  virtual void isolate () {
    cout << "Isolate the grid" << endl;
  }

  virtual void identify () {
    cout << "Identify the source" << endl;
  }

  public: 
  void byTheNumbers() {
    // Template method design pattern
    localize();
    isolate();
    identify();
  }
};

// Class inheritance, type inheritance
class Surveillance: public CheckList, public AlarmListener {
  /*virtual*/void isolate() {
    cout << " The train has a camera" << endl;
  }

  public: 
  /*virtual*/void alarm() {
    cout << "Surveillance by the numbers" << endl;
    byTheNumbers();
  }
};

int main() {
  SensorSystem ss;
  Gates gates;
  Lightening lightening;
  Surveillance surveillance;

  ss.attach(&gates);
  ss.attach(&lightening);
  ss.attach(&surveillance);
  ss.soundTheAlarm();
  
  return 0;
}
