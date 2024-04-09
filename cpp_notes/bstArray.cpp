#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

int tree[SIZE];

void insert(int val, int idx) {
  if (tree[idx] == -1) {
    tree[idx] = val;
  } else {
    char opt; 
    printf("Does the node %d have LC or RC? (l/r): ", tree[idx]);
    scanf(" %c", &opt);

    if (opt == 'l' || opt == 'L') {
      insert(val, 2 * idx);
    } else if (opt == 'r' || opt == 'R') {
      insert(val, 2 * idx + 1);
    } else {
      printf("Invalid option\n");
      exit(1);
    }
  }
}

int main() {
  // initialize the tree with -1;
  for (int i = 0; i < SIZE; i++) {
    tree[i] = -1;
  }

  char ch;
  do {
    int val;
    printf("Enter data: ");
    scanf(" %d", &val);

    if (tree[1] == -1) {
      tree[1] = val;
    } else {
      insert(val, 1);
    }
    printf("Do you want to insert more data? (y/n): ");
    scanf(" %c", &ch);
  } while (ch == 'y' || ch == 'Y');

  return 0;
}
