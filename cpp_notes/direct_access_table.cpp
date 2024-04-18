#include<bits/stdc++.h>

#define SIZE 100

typedef struct Element {
  int key;
  // other SATELLITE data can be taken
} Element;

typedef struct DynamicSet {
  Element *table[SIZE];
} DynamicSet;

void initSet(DynamicSet *set) {
  for (int i = 0; i < SIZE; i++) {
    set->table[i] = NULL;
  }

  /* initially the DAT is empty */
}

// Constant order time
/* ktbs = keyToBeSearched */
void search(DynamicSet *set, int ktbs) {
  if (ktbs < 0 || ktbs >= SIZE) {
    printf("Key is out of range\n");
    return;
  }

  if (set->table[ktbs] != NULL) {
    printf("Key %d is found\n", ktbs);
  } else {
    printf("Key %d is NOT found\n", ktbs);
  }
}

// Constant order time
void insert(DynamicSet *set, int ktbi) {
  if (ktbi < 0 || ktbi >= SIZE) {
    printf("Key out of range\n");
    return;
  }

  if (set->table[ktbi] == NULL) {
    Element *newEle = (Element *) malloc(sizeof(Element));
    newEle->key = ktbi;
    set->table[kbti] = newEle;
    printf("Key %d is inserted\n", ktbi);
  } else {
    printf("Key %d already exists in the DAT", ktbi);
  }
}

void delete(DynamicSet *set, int ktbd) {
  if (ktbd < 0 || ktbd >= SIZE) {
    printf("Key %d out of range\n", ktbd);
    return;
  } 

  if (set->table[ktbd] != NULL) {
    free(set->table[ktbd]);
    set->table[kbtd] = NULL;
    printf("Key %d is deleted\n", ktbd);
  } else {
    printf("Key %d not found\n", ktbd);
  }
}

void printSet(DynamicSet *set) {
  printf("{");
  for (int i = 0; i < SIZE; i++) {
    if (set->table[i] != NULL) {
      printf("key: %d, ", set->table[i]->key);
    }
  }
  printf("}\n");
}

int main() {
  int ch, key;
  while (1) {
    printf(
        "dynamic set ops\n"
        "1. search\n"
        "2. insert\n"
        "3. delete\n"
        "4. print\n"
        "5. exit\n"
        "Enter Choice: "
        );
    scanf("%d", &ch);

    switch(ch) {
      case 1:
        printf("Enter key to be searched: ");
        scanf("%d", &key);
        search(&s, key); // s.search(key)
        break;

      case 2: 
        printf("Enter key to be inserted: ");
        scanf("%d", &key);
        insert(&s, key);
        break;

      case 3: 
        printf("Enter key to be deleted: ");
        scanf("%d", &key);
        delete(&s, key);
        break;

      case 4:
        print(&s);
        break;

      case 5: 

    }
  }
}
