#include<bits/stdc++.h>
using namespace std;

# define INIT_SIZE 10

typedef struct KeyValuePair {
  int key, val;
  int isDeleted; // flag to mark the deleted entities
} KeyValuePair;

typedef struct DynamicArray {
  KeyValuePair *data;
  int size; // size represents the number of elements present in the dynamic array currently
  int capacity; // max no. of elements that the dynamic array can currently hold
} DynamicArray;

typedef struct HashTable {
  DynamicArray *array;
  int size; // represents the number of elements present in the hashtable currently
  int count; // will hold the number of key-val pairs stored in the hashtable
} HashTable; // based on the Dynamic Array

int hash(int key, int size) {
  // for simplicity, we've taken `size` here, but in the real world - the next prime number should be taken compared to the size of the table.
  int hv = key % size;
  return hv;
}

void initDynamicArray(DynamicArray *array, int cap) {
  array->data = (KeyValuePair *) malloc(sizeof(KeyValuePair) * cap);

  for (int i = 0; i < cap; i++) {
    array->data[i].isDeleted = 0; // because no element is deleted till now;
  }

  // since no element is present, size = 0;
  array->size = 0;
  array->capacity = cap;
}

void addToDynamicArray(DynamicArray *array, int key, int val) {
  if (array->size == array->capacity) {
    // double the capacity of the array: 
    it newCap = array->capacity * 2;

    array->data = (KeyValuePair *) realloc(array->data, sizeof(KeyValuePair) * newCap);

    if (array->data == NULL) {
      printf("`realloc` failed to allocated memory\n");
      exit(1);
    }

    for (int i = array->capacity; i < newCap; i++) {
      array->data[i].isDeleted = 0;
    }

    array->capacity = newCap;
  }

  // After resizing: 
  array->data[array->size].key = key;
  array->data[array->size].val = val;
  array->size += 1;
}

void initHashTable(HashTable *ht, int initSize) {
  ht->array = (DynamicArray *) malloc(sizeof(DynamicArray));

  ht->size = initSize;
  ht->count = 0;

  for(int i = 0; i < initSize; i++) {
    initDynamicArray(&ht->array[i], INIT_SIZE);
  }
}

// check if key exists already:
int findKey(DynamicArray *array, int key) {
  for (int i = 0; i < array->size; i++) {
    if (array->data[i].isDeleted != 0 && array->data[i].key == key) {
      return i;
    }
  }
  return -1; // when the key is not found
}

void insert(HashTable *ht, int key, int value) {
  int idx = hash(key, ht->size);
  // check for duplicate keys: 
  if(findKey(&ht->array[idx], key) != -1) {
    printf("Duplicate key %d, insertion failed\n", key);
    return;
  }

  // Now, perform linear probing for insertion:
  while (ht->array[idx].size == ht->array[idx].capacity) {
    // Resize the hash table if full: 
    int newCap = ht->array[idx].capacity * 2;
    // Reallocate the memory;
    ht->array[idx].data = (KeyValuePair *) realloc(ht->array[idx].data, sizeof(KeyValuePair) * newCap);

    if (ht->array[idx].data == NULL) {
      printf("realloc failed\n");
      exit(1);
    }

    for (int i = ht->array[idx].capacity; i < newCap; i++) {
      ht->array[idx].data[idx].isDeleted = 0;
    }

    ht->array[idx].capacity = newCap;
  }

  // Now, insert the key-val pair: 
  addToDynamicArray(&ht->array[idx], key, value);
  ht->count += 1;
}

int search(HashTable *ht, int key) {
  int idx = hash(key, ht->size);
  int keyIdx = findKey(&ht-array[idx], key);
  if (keyIdx != -1) {
    return ht->array[idx].data[keyIdx].val;
  }

  return -1;
}

void deleteKey(HashTable *ht, int key) {
  int idx = hash(key, ht->size);
  int keyIdx = findKey(&ht->array[idx], key);
  if (keyIdx != -1) {
    ht->array[idx].data[keyIdx].isDeleted = 1;
    ht->count -= 1;
  }
}

void printHashTable(HashTable *ht) {
  printf("{");
  int printed = 0;
  
  for (int i = 0; i < ht->size; i++) {
    DynamicArray *currArr = &ht->array[i];
    for (int j = 0; j < currArr->size; j++) {
      if (currArr->data[j].isDeleted != 0) {
        if (printed > 0) {
          printf(", "); // means more elements are present so we're printing a comma
        }
        printf("%d: %d", currArr->data[j].key, currArr->data[j].val);
        printed += 1;
      }
    }
  }

  printf("}\n");
}

int main() {
  Hashtable ht;
  initHashTable(&ht, INIT_SIZE);

  int ch, key, val;
  while (1) {
    printf(
        "1. Insert key-vla pair\n"
        "2. Search for key\n"
        "3. Print\n"
        "4. Quit\n"
        "5. Delete\n"
        "Enter choice: "
        );
    scanf("%d", ch);
    switch(ch) {
      case 1:
        printf("Enter key, val: ");
        scanf("%d %d", &key, &val);
        insert(&ht, key, val); // in Object Oriented you might call like this: `ht.insert(key, val);`
        break;

      case 2:
        printf("Enter key to be searched: ");
        scanf("%d", &key);
        val = search(&ht, key);
        if (val != -1) {
          printf("Val for key %d is: \n", key, val);
        } else {
          printf("Key %d is not found\n", key);
        }
        break;

      case 3:
        printHashTable(&ht);
        break;

      case 4: 
        printf("Exiting...\n");
        break;

      case 5:
        printf("Enter key to be deleted: \n");
        scanf("%d", &key);
        deleteKey(&ht, key);
        break;

      default: printf("Wrong choice, try again\n");
    }
  }

  return 0;
}
