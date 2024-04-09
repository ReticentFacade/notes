#include<bits/stdc++.h>
using namespace std;

string directions = "DLRU";
int dirr[4] = { 1, 0, 0, -1 };
int dirc[4] = { 0, -1, 1, 0 };

bool isValid(int row, int col, int n, vector<vector<int>> &maze) {
  return row >= 0 && col >= 0 && row < n && col < n && maze[row][col];
}

void findPath(int row, int col, int n, string &currPath, vector<string> &ans, vector<vector<int>> &maze) {
  if (row == n - 1 && col == n - 1) {
    ans.push_back(currPath);
    return;
  }

  maze[row][col] = 0;
  for (int i = 0; i < 4; i++) {
    int nextRow = row + dirr[i];
    int nextCol = col + dirc[i];

    if (isValid(nextRow, nextCol, n, maze)) {
      currPath += directions[i];
      findPath(nextRow, nextCol, n, currPath, ans, maze);

      /* backtrack */
      currPath.pop_back();
    }
  }
  maze[row][col] = 1;
}

int main() {
  vector<vector<int>> maze = { { 1, 0, 0, 0 }, 
                               { 1, 1, 0, 1 }, 
                               { 1, 1, 0, 0 }, 
                               { 0, 1, 1, 1 } };
  
  int n = maze.size();
  vector<string> ans;
  string currPath = "";

  if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0) findPath(0, 0, n, currPath, ans, maze);

  if (ans.size() == 0) cout << -1;
  else {
    for (int i = 0; i < ans.size(); i++) {
      cout << "[" << ans[i] << "], [";
    }
    cout << endl;
  }

  return 0;
}
