#include<bits/stdc++.h>
using namespace std;

#define MAX_HEAP_SIZE 10

int maxHeap[MAX_HEAP_SIZE];
int heapSize = 0;

/* take a swap function because we will need multiple swap functions */
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to maintain the heap property
void maxHeapify(int idx) {
  int largest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < heapSize && maxHeap[left] > maxHeap[largest]) {
    largest = left;
  }

  if (right < heapSize && maxHeap[right] > maxHeap[largest]) {
    largest = right;
  }

  if (largest != idx) {
    swap(&maxHeap[idx], &maxHeap[largest]);
    maxHeapify(largest);
  }
}

void insert(int val) {
  if (heapSize == MAX_HEAP_SIZE) {
    printf("Heap overflow (Heap is full!)\n");
    return;
  }

  int currIdx = heapSize;
  maxHeap[currIdx] = val;
  heapSize += 1;

  // This new element may disturb the heap property; so to take care of this we will use `re-heapify`
  while (currIdx > 0 && maxHeap[currIdx] > maxHeap[(currIdx - 1)/2]) {
    swap(&maxHeap[currIdx], &maxHeap[(currIdx - 1)/2]);
    currIdx = (currIdx - 1)/2;
  }
}

void deleteMax() {
  if (heapSize <= 0) {
    printf("Heap underflow\n");
    return;
  }

  maxHeap[0] = maxHeap[heapSize - 1]; // put the last element of an array at 0th index
  heapSize -= 1;
  maxHeapify(0);
}

int findMax() {
  if (heapSize <= 0) {
    printf("Heap is empty\n");
    return -1;
  }

  return maxHeap[0];
}

void printTree() {
  for (int i = 0; i < heapSize; i++) {
    printf("%d", maxHeap[i]);
  }
  printf("\n");
}

int main() {
  int ch;
  do {
    printf(
        "1. Insert\n"
        "2. Delete max\n"
        "3. Find max\n"
        "4. Find min\n"
        "5. Print\n"
        "6. Exit\n"
        );
    scanf("%d", &ch);

    /* int val; */
    switch(ch) {
      case 1:
        int val;
        printf("Enter val: ");
        scanf("%d", &val);
        insert(val);
        printf("Inserted %d into heap\n", val);
        break;

      case 2: 
        if (heapSize > 0) {
          int max = findMax();
          deleteMax();
          printf("Deleted max %d\n", max);
        } else {
          printf("Heap is empty\n");
        }
        break;

      case 3: 
        printf("Max %d\n", findMax());
        break;

      case 4: 
        /* printf("Min %d\n", findMin()); */
        break;

      case 5: 
        printTree();
        break;

      case 6: 
        printf("Exitting...\n");
        break;

      default:
        printf("Wrong choice!\n");
    } while (ch != 6)
  }

  return 0;
}
