#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left, *right;
};

struct TreeNode* createNode(int val) {
  struct TreeNode* newTreeNode = (struct TreeNode*) malloc(sizeof(struct TreeNode*));

  if (newTreeNode == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  newTreeNode->val = val;
  // newTreeNode->left = NULL;
  // newTreeNode->right = NULL;
  newTreeNode->left = newTreeNode->right = NULL;
  
  return newTreeNode;
}

void buildTree(struct TreeNode* ptr) {
  int ele;
  printf("Enter the data: ");
  scanf("%d", &ele);

  ptr->val = ele;

  char opt;
  printf("Does the node have LST? (y/n): ");
  scanf("%c", &opt);

  if (opt == 'y' || opt == 'Y') {
    struct TreeNode* leftChildPtr = createNode(-1); // Initially put invalid value
    ptr->left = leftChildPtr; // then put valid value 
    
    buildTree(leftChildPtr); // build the left subtree
  } else {
    ptr->left = NULL;
  }

  printf("Does the node have RST? (y/n): ");
  scanf("%c", &opt);

  if (opt == 'y' || opt == 'Y') {
    struct TreeNode* rightChildPtr = createNode(-1);
    ptr->right = rightChildPtr;

    buildTree(rightChildPtr);
  } else {
    ptr->right = NULL;
  }
}

// Now, function for in-order traversal:
void inOrder(struct TreeNode* root) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left);
  printf("%d ", root->val);
  inOrder(root->right);
  printf("%d ", root->val);
}

int main() {
  struct TreeNode* root = createNode(-1); // invalid value; to allocate memory for root node

  buildTree(root);
  
  inOrder(root);
  printf("\n");

  return 0;
}
