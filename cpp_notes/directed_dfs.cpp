#include<bits/stdc++.h>
using namespace std;

class Graph {
  map<int, bool> visited;
  map<int, list<int>> adj;

  void addEdge(int v, int w);
  void dfs(int v);
};

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::dfs(int v) {
  visited[v] = true;
  cout << v << " ";

  list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
  

  return 0;
}
