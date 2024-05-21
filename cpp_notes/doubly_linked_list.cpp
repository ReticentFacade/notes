#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

Node* createNode(int data) {
  Node* nn = (Node*) malloc(sizeof(Node));
  if (nn == NULL) {
    printf("Memory allocation failed");
    return;
  }

  nn->data = data;
  nn->prev = NULL;
  nn->next = NULL;

  return nn;
}

void insertAtFront(Node** head, int data) {
  Node* nn = createNode(data);
  if (*head == NULL) {
    *head = nn;
  } else {
    nn->next = *head;
    (*head)->prev = nn;
    *head->next = nn;
  }
}

int main() {


  return 0;
}
