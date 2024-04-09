#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left, *right;
};

struct TreeNode* createNode(int val) {
  struct TreeNode* newTreeNode = (struct TreeNode*) malloc(sizeof(struct TreeNode*));

  if (newTreeNode == nullptr) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  newTreeNode->val = val;
  newTreeNode->left = newTreeNode->right = nullptr;

  return newTreeNode;
}

void bstLinked(struct TreeNode* ptr) {
  int ele;
  printf("Enter the data: ");
  scanf("%d", ele);

  ptr->val = ele;

  char opt;
  printf("Does the node %d have child nodes? (y/n): ", ele);
  scanf("%c", &opt);

  if (opt == 'y' || opt == 'Y') {
    struct TreeNode* childPtr = createNode(-1);
    if ()
  }
}

int main() {
  
  
  return 0;
}
