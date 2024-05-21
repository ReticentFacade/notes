#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums) {
  unordered_set<int> st;
  for (int i : nums) {
    if (st.count(i) > 0) return 1;
    st.insert(i);
  }

  return 0;
}


int main() {
  vector<int> nums = {1, 2, 3, 4, 1, 9};
  bool dupli = containsDuplicate(nums);

  cout << "Ans: " << dupli << endl;

  return 0;
}
