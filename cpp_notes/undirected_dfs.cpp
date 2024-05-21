#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &ans) {
      if (visited[u] == true) return;

      /* if not visited, mark true */
      visited[u] = true;
      ans.push_back(u);

      for (int &v : adj[u]) {
        if (visited[v] == false) {
          DFS(adj, v, visited, ans);
        }
      }
    }

    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
      unordered_map<int, vector<int>> adj;
      for (int u = 0; u < V; u++) {
        for (auto v = mp[u].begin(); v != mp[u].end(); v++) {
          adj[u].push_back(*v);
        }
      }

      vector<int> ans;
      vector<bool> visited(V, false);

      DFS(adj, 0, visited, ans);

      return ans;
    }
};

int main() {
  int testCases;
  cin >> testCases;

  while (testCases--) {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v; // starting node and ending node
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    Solution sol1;
    vector<int> ans = sol1.dfsOfGraph(V, adj);

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
