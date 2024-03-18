#include<bits/stdc++.h>
using namespace std;

class Time {
  int hrs, mns;
  public: 
  void setTime(int h, int m) {
    hrs = h;
    mns = m;
  }

  void getTime(void) {
    cout << "hours: " << hrs << endl;
    cout << "minutes: " << mns << endl;
  }
  void sum(Time, Time);
};

void Time::sum(Time t1, Time t2) {
  mns = t1.mns + t2.mns;
  hrs = mns/60;
  mns = mns % 60;
  hrs = hrs + t1.hrs + t2.hrs;
}

int main() {
  Time t1, t2, t3;
  t1.setTime(2, 45);
  t2.setTime(3, 30);

  t3.sum(t1, t2);

  t1.getTime();
  t2.getTime();
  t3.getTime();

  return 0;
}
