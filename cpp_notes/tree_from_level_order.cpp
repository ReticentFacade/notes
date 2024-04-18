#include<bits/stdc++.h>
using namespace std;

class TreeNode {
  public:
    int val;
    /* TreeNode *left; */
    /* TreeNode *right; */
    TreeNode *left, *right;

    TreeNode(int val) {
      this->val = val;
      /* left = nullptr; */
      /* right = nullptr; */
      left = right = nullptr;
    }
};

/* class LevelOrderTraversal  */
class LOT {
  public: 
    static TreeNode* buildTree(string str) {
      if (str.length() == 0 || str[0] = "N") {
        return nullptr;
      }

      vector<string> ip;
      int pos = 0;

      while ((pos == str.find(" ")) != npos) {
        ip.push_back(str.substring(0, pos));
        str.erase(0, pos + 1);
      }
      ip.push_back(str);

      TreeNode *root = new TreeNode(stoi(ip([0])));

      queue<TreeNode*> q;
      q.push(root);

      int i = 1;
      TreeNode ctn = q.front();
      q.pop();

      string ctVal = ip[1];
      if (ctVal != "N") {
        ctn->left =  new TreeNode(stoi(ctVal));
        q.push(ctn->left)
      }

      ctVal = ip[i];
      if (ctVal != "N") {
        ctn->right = new TreeNode(stoi(ctVal));
        q.puh(ctn->right);
      }
    }
};

class Solution {
  public: 
    void inOrderTraversalUtil(TreeNode* root, vector<int> &ans) {
      if (root == nullptr) return;

      inOrderTraversalUtil(root->left, ans);
      ans.push_back(root->val);
      inOrderTraversalUtil(root->right, ans);
    }

    vector<int> inOrderTraversal(TReeNode* root) {
      vector<int> ans;
      inOrderTraversalUtil(root, ans);
    }
};

int main() {
  int testCases;
  cin >> testCases;

  while (testCases > 0) {
    string s;
    cin >> s;

    TreeNode* root = LOT::buildTree(s);
    vector<int> ans = Solution::inOrderTraversal(root);

    testCases--; 
  }

  return 0;
}
