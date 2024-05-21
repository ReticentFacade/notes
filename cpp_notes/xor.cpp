#include<bits/stdc++.h>
using namespace std;

int main() {
  /* icnt a = 8, b = 15; */

  /* cout << (a ^ b) << endl; */

  int nums[4] = [4, 2, 1, 2];
  int ans = nums[0];
  for (int i = 1; i < nums.length(); i++) {
    ans ^= nums[i];
  }
  cout << ans << endl;

  return 0;
}
