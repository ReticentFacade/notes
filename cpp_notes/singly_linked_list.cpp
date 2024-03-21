#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data) {
  Node *nn = (Node*) malloc(sizeof(Node)); // Creates Node in the heap memory
  if (nn == NULL) {
    printf("Memory allocation failed");
    exit(1); // 1 means error
  }

  nn->data = data;
  nn->next = NULL;

  return nn;
}

void insertAtFront(Node **head) { // passing head as pointer
  Node *nn = createNode(data);
  nn->next = NULL;
  *head = nn;
}

void insertAtEnd(Node** head, int data) {
  Node* nn = createNode(data);
  if (head == NULL) {
    *head = nn;
    return;
  }

  Node *cn = *head;
  while (cn->next != NULL) {
    cn = cn->next;
  }

  cn->next = nn;
}

void insertAtPosition(Node** head, int data, int position) {
  Node* nn = createNode(data);
  if (position < 0) {
    printf("Invalid position");
    return;
  }
  if (position == 0) {
    nn->next = *head;
    *head = nn;
    return;
  } 

  Node* cn = *head;
  int cp = 0;
  while (cn != NULL && cp < position) {
    cn = cn->next;
    cp++;
  }

  if (cn == NULL) {
    printf("Position out of bounds");
    return;
  }

  nn->next = cn->next;
  cn->next = nn;
}

void deleteFromFront(Node** head) {
  if (*head == NULL) {
    printf("List is empty");
    return;
  }

  Node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteFromEnd(Node** head) {
  if (*head == NULL) {
    printf("List is empty!");
    return;
  }

  if ((*head)->next == NULL) { // means only single element is there in the list 
    free(*head);
    *head = NULL;
    return;
  }

  // going to the 2nd last element: 
  Node* cn = *head;
  while (cn->next->next != NULL) {
    cn = cn->next;
  }

  free(cn->next);
  cn->next = NULL;
}

void deleteFromPosition(Node** head, int position) {
  if (*head == NULL) {
    printf("List is empty");
    return;
  }

  if (position < 0) {
    printf("Invalid position");
    return;
  }

  if (position == 0) {
    deleteFromFront(head);
  }

  Node* cn = *head;
  int cp = 0
  while (cn->next != NULL && cp < position - 1) {
    cn = cn->next;
    cp++;
  }

  if (cn->next == NULL) {
    printf("Position out of bounds/range");
    return;
  }
  
  Node* temp = cn->next;
  cn->next = cn->next->next;
  
  free(temp);
}

int search(Node head, int key) {
  int pos = 0;
  Node* cn = head;
  while (cn != NULL) {
    if (cn->data == key) return pos;
    cn = cn->next;
    pos++;
  }
  return -1; // `-1` is the `SENTINEL VALUE` here.
}

void printList(Node* head) {
  Node* cn = head;
  printf("[");

  while (cn != NULL) {
    printf("%d", cn->data);
    if (cn->next != NULL) {
      printf(", ");
    }
    cn = cn->next;
  }
  
  printf("]");
  // printf("%d", cn->data);
}

void freeList(Node* head) {}

// void mergeLinkedList(Node** head1, Node** head2) {
  // if (*head1 == NULL) {}
// }



int main() {
  

  return 0;
}
