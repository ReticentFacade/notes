#include<bits/stdc++.h>
using namespace std;

# define TS 5 
// TS = Table Size (and should be a prime number)

typedef struct HashTable {
  int keys[TS];
  int values[TS];
  int used[TS]; // this is for the track of empty slot
} HashTable;

// to initialize the hash table:
void initHastTable(HashTable *ht) {
  for (int i = 0; i < TS; i++) {
    ht->used[i] = 0; // all key-value pairs are unused
  }
}

// define the hash function:
int hash(int key) {
  int hv = key % TS;
  // TS should be taken for hash value next greater prime of table size is a better choice
  return hv;
}

int isKeyInTable(HashTable *ht, int key) {
  int idx = hash(key);

  int originalIdx = idx;

  do {
    if (ht->used[idx] != 0 && ht->keys[idx] == key) {
      return 1;
      // linear search algorithm
    }
    idx = (idx + 1) % TS;
  } while (idx != originalIdx);

  return 0;
}

void insert(HashTable *ht, int key, int val) {
  if (isKeyInTable(ht, key)) {
    printf("Key already exists\n");
    return;
  } else {
    int idx = hash(key);

    while (ht->used[idx] != 0) {
      idx = (idx + 1) % TS;
    }
    ht->keys[idx] = key;
    ht->values[idx] = val;
    ht->used[idx] = 1;
  }
}

int search(HashTable *ht, int key) {
  int idx = hash(key);

  while (ht->used[idx] != 0) {
    // keep on finding the element one-by-one by linear probing:
    if (ht->keys[idx] == key) {
      return ht->values[idx];
    }
    idx = (idx + 1) % TS;
  }

  return -1; // `-1` being a sentinal value 
}

void printHashTable(HashTable *ht) {
  printf("{");
  int printed = 0;
  for (int i = 0; i < TS; i++) {
    if (ht->used[i] == 1) {
      if (printed > 0) {
        printf(", ");
      }

      printf("%d, %d", ht->keys[i], ht->values[i]);
      printed += 1;
    }
  }
  printf("}\n");
}

int main() {
  HashTable ht;
  initHastTable(&ht);
  while (1) {
    printf(
        "1. Insert key-value pair\n"
        "2. Search for a key\n"
        "3. Print Hashtable\n"
        "4. Select the choice\n"
        );

    char ch;
    scanf("%d", &ch);
    switch(ch) {
      case 1: 
        printf("enter key, val: ");
        scanf("%d %d", &key, &val);
        insert(&ht, key, val);
        break;
      case 2:
        prtinf("enter key to be searched: ");
        scanf("%d", &key);
        val = search(&ht, key);
        if (val != -1) {
          printf("Val for key %d is %d\n", key, val);
        } else {
          printf("Key %d is not found\n", key);
        }
        break;
      case 3: 
        printHashTable(&ht);
        break;

      case 4: 
        printf("Exiting...\n");
        exit(0);

      default: printf("Wrong choice!\n");
    }
  }
  return 0;
}}
