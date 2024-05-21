// ARRAY REPRESENTATION: 

#include<bits/stdc++.h>
using namespace std;

#define SIZE 100
// define size of binary tree

int tree[SIZE];

void buildTree(int idx) {
  int val;
  printf("Enter the data for the node: ");
  scanf("%d", &val);

  tree[idx] = val;
  
  char opt;
  printf("Does the node %d have left subtree (LST) or not? (y/n): ", val);
  scanf("%c", &opt);

  if (opt == 'y' || opt == 'Y') {
    buildTree(2 * idx); // This will build the LEFT subtree recursively;
  } 

  printf("Does the node %d have right subtree (RST) or not? (y/n): ", val);
  scanf("%c", &opt);

  if (opt == 'y' || opt == 'Y') {
    buildTree(2 * idx + 1);
  }
}

int main() {
  // init the tree with -1:
  for (int i = 0; i < SIZE; i++) {
    tree[i] = -1;
  }

  // start building the tree: 
  buildTree(1);

  // display the buildTree: LEVEL-ORDER TRAVERSING: 
  for (int i = 0; i < SIZE; i++) {
    if (tree[i] != -1) { // if tree's value isn't -1, then it is valid:
      printf("%d ", tree[i]);
    }
  }

  return 0;
}
