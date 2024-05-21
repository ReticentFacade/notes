#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int profit;
};

int helper() {}

int knapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return ;
}

int main() {
    int n; cin>>n;
    int maxWeight; cin>>maxWeight;

    // initializing every element in the 2D dp-array as `-1`:
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    vector<Item> items(n); 
    for (int i = 0; i < n; i++) {
        cin>>items[i].weight>>items[i].profit;
    }

    int capacity; cin>>capacity;

    int ans = knapsack(capacity, items);

    cout<<ans<<endl;

    return 0;
}