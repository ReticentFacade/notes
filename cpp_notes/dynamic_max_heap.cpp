#include<bits/stdc++.h>
using namespace std;

typedef struct MaxHeap {
  int *array;
  int capacity; // will hold the maximum number of elements 
  int size; // will hold the current number of elements
} MaxHeap; 

MaxHeap *createMaxHeap(int cap) {
  MaxHeap *maxHeap = (MaxHeap *) malloc(sizeof(MaxHeap));

  if (maxHeap == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  maxHeap->capacity = cap;
  maxHeap->size = 0;
  maxHeap->array = (int *) malloc(sizeof((int) * cap);
  if (maxHeap->array == NULL) {
    printf(Memory alloc failed\n);
    exit(1);
  }

  return maxHeap;
}

void swap(int *a, int *b) {
  int t = *a; 
  *a = *b;
  *b = t;
}

void maxHeapify(MaxHeap *mh, int idx) {
  int largest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < mh->size && mh->array[left] > mh->array[largest]) {
    largest = left;
  }

  if (right < mh-size && mh->array[right] > mh->array[largest]) {
    largest = right;
  }

  if (largest != idx) {
    swap(&mh->array[idx], &mh->array[largest]);
    maxHeapify(mh, largest);
  }
}

void insert(MaxHeap *mh, int val) {
  if (mh->size == mh->capacity) {
    printf("Heap overflow\n");
    // Ideally you should double the size and REALLOCATE new array 
    return; 
  }

  int idx = mh->size;
  while (idx != 0 && mh->array[(idx - 1)/2] < mh->array[idx]) {
    swap(&mh->array[(idx - 1)/2], &mh->array[idx]);
    idx = (idx - 1)/2;
  }


}

int main() {
  

  return 0;
}
