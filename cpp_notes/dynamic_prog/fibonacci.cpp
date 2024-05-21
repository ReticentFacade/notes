#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
  if (n <= 2) return 1;

  return fib(n - 1) + fib(n - 2);
}

int fibMemo(int n) {
  if (n == 0 || n == 1) return 1;
  vector<int> dp(n + 1);

  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  
  return dp[n];
}

int main() {
  int n; 
  cout<<"Enter the value of `n`: ";
  cin>>n;

  cout<<"The last term will be: "<<fib(n)<<endl;

  int newN;
  cout<<"Enter the value of `n` again: ";
  cin>>newN;
  cout<<"The last term will be: "<<fibMemo(newN)<<endl;

  return 0;
}
