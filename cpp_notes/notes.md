# Function Overloading:

- `Advantages`:
  * Uniform user-definition of code 
  * Resuability of code 

- CPP knows when to call functions corresponding to the data type of the parameters. 
- In practical programming (OOP), overloading operator is a bad practice. It's not used commonly, but you should know about it.

- Overloading is suitable when the number of types and parameters are different. 

- Based on return type of the function overloading concept is not applicable. It throws `compilation error` if you try to overload ONLY based on the return type of two functions.

----

# Function Templates [GENERIC PROGRAMMING]: 

- Overloaded functions may have the same definition. 

- Overloading has a disadvantage that if there are 4 datatypes you're gonna have to create 4 different functions for each of them. 
- To CONVERT this disadvantage into an advantage, we use `generic types`, called `FUNCTION TEMPLATES.`
- Syntax of function template: 
```CPP
template <template parameters> function declaration
```

- The template parameters are separated by commas. 
- These parameters can be generic template types by specifying either the class or typename keyword followed by an identifier. 

- Type is specified with keyword class or keyword `typename` in the template argument. 
- Syntax: 
```CPP
template <typename T> 
T myMax(T x, T y) {
  return (x > y) ? x : y;
}
```

- C++ compiler automatically instantiates and calls each time with appropriate version of the datatype that was provided during the function calling time. 

- Generic type T is used as a parameter for the function sum, the C++ compiler is even able to deduce teh datatype automatically without having to explicitly specify it within angle brackets therefore instead of explicitly specifying template with args with 
```
k = sum<int> (i, j);
h = sum<double> (f, g);
```

Instead of writing above snippet of code, we can write: 
```
k = sum(i, j); 
h = sum(f, g);
```

* WITHOUT THE DATATYPE ENCLOSED IN ANGLE BRACKETS, naturally for that type will be ambiguous. If sum is called with arguments of different types, then COMPILER MAY NOT BE ABLE TO DEDUCE THE TYPE OF T AUTOMATICALLY.

---
*SIDE NOTE:* Since in C++ compiler does all this at `COMPILE TIME,` IT IS FASTER. Unlike languages like JAVA, which depend on `RUNTIME` factors.
---

- Templates are powerful and versatile. They can have multiple template parameters, and the function can still use regular non-templated types. 

---
```CPP
───────┬─────────────────────────────────────────────────────────────────────────────────────────────
       │ File: template_types2.cpp
───────┼─────────────────────────────────────────────────────────────────────────────────────────────
   1   │ #include<bits/stdc++.h>
   2   │ using namespace std;
   3   │
   4   │ template <class T, class U>
   5   │ bool areEqual(T a, U b) {
   6   │   return (a == b);
   7   │ }
   8   │
   9   │ int main() {
  10   │   cout << areEqual(10, 10) << endl;
  11   │   cout << areEqual(10, 10.9) << endl;
  12   │   cout << areEqual(10, 10.0) << endl;
  13   │
  14   │   return 0;
  15   │ }
───────┴─────────────────────────────────────────────────────────────────────────────────────────────
```
- In this example, automatic template parameter deduction in the function call of areEqual.
`areEqual(10, 10.0) === areEqual<int, double> (10, 10.0);`
---

- This is also called `STATIC POLYMORPHISM`.

- Non-template arguments 
- The template arguments not only include the 

# HETEROGENEOUS TEMPLATE OVERLOADING: 
```CPP
➜  cpp_notes git:(master) ✗ cat template_types3.cpp
#include<bits/stdc++.h>
using namespace std;

// HETEROGENEOUS TEMPLATE OVERLOADING: STATIC POLYMORPHISM
template <class T, int N>
T fixedMultiply(T val){
  return val * N;
}

int main() {
  cout << fixedMultiply<int, 2>(10) << endl;
  cout << fixedMultiply<int, 3>(10) << endl;

  return 0;
}
```

- There is a major difference: the value of the template parameters is determined on the COMPILE TIME (static) to generate a different instantiation of the function `fixedMultiply` in the main function essentially call two version of the function: one that always multiplies by 2 and one that always multiplies by 3. 
For that same reason the second template argument...

# NAME VISIBILITY: 

## 1. SCOPE:
- Named entities such as variables, (programmer-defined name entities), functions, and compount types (i.e., classes, structs) - need to be declared before being used in C++. 
- The point in the program where this declaration happens influences its visibility. 
- An entity declared outside any code block has `GLOBAL` scope (Available throughout the program execution), meaning that the name is valid anywhere in the code.
- While an entity declared within a block, such as function or an iterative or selection statement, has `BLOCK` scope, and is only visible within the specific block in which it is declared but not outside it. 

- Variables with `BLOCK` scope = `LOCAL` variables

- Two or more variables in the same scope results in `COMPILE TIME ERROR` [CTE] IN C++.
- The visibility of an entity with the block scope extends until the inner block ends.

- If a variable is visible in inner block, the variable's value (if avaiable) outside the block is HIDDEN.

### STATIC SCOPING VS DYNAMIC SCOPING: 
- WHEN THE SCOPE-RESOLUTION IS DONE DURING COMPILE-TIME, IT IS STATIC SCOPING.
- WHEN THE SCOPE-RESOLUTINO IS DONE DURING RUN-TIME, IT IS DYNAMIC SCOPING.

MOSTLY, STATIC SCOPING IS USED. 
- EXAMPLES OF STATIC SCOPING: JAVA, C++.
- EXAMPLES OF DYNAMIC SCOPING: PASCAL, ADA ETC.

- In static scoping, your outer block's value tends to change if you change the value in inner block. 

## 2. NAMESPACE: 

- 3 main streams exist in C++: `stdout`, `stdin', `stderr`.
- Non-local names bring more possibilities for `name collision`. Especially considering that libraries may declare many functions types and variable neither of them local in nature, and some of them very generic (LIKE: `sort`) namespaces allow us to group entities that otherwise would have global scope into narrow scopes giving them the namespace scope (programmer-defined naming scopes).
- This allows organising the elements of programs into different logical scopes, referred to by the programmer defined names. 

- Syntax: 
```cpp
namespace identifier 
{
  // named_entities;
}
```

---
Q: What is the purpose of namespace programming construct in C++?
ANS: To avoid any kind of name collision either with standard library or any peer developers library. 
---

-------
-------

# STORAGE CLASSES: 
- Also known as static storage 
- When the value of a variable is stored for the *entirety* of the program. 
[ Static storage = basically, wherever `static` is used it means it's done at = COMPILE TIME]

- Local variables have AUTOMATIC storage.
[ AUTOMATIC = automatically referenced AND DEFERENCED according to the storage block. ]

- `static` keyword STORES THE value of the variable irrespective of the dereferrencing of the variable's value;
- Example: 
```cpp
#include<bits/stdc++.h>
using namespace std; 

int f() {
  // int ans = 0;
  static int ans = 0;
  
  ans += 1;
  
  return a;
}

int main() {
  cout << f() << endl;
  cout << f() << endl;

  return 0;
}
```

# CLASSES: 

- Concept of CLASSES came from STRUCTURES;
- Classes are extensions to the concept of structures; Structures were used for Heterogeneous data structures only. So, to tackle this problem and expand the use of structs, to polymorphism, encapsulation etc., Classes were introduced. 

- Member functions = Methods 

- THE ONLY Difference b/w struct and classes = by default members of a class are private whereas those in structs are public. 

----
- Mutator = Function which is responsible to give values to the class 
- Accessor = Helps print the data 
----

- Members [member functions] are object dependent; whereas Functions are object-independent.


# MESSAGE PASSING: 

= Nested of member functions 

- 

# ** MEMORY ALLOCATION: **


# STATIC DATA MEMBERS:

- Members functions/Variables that are shared between all objects. 
- It is initialised to zero for numeric data types and default values for other data types. 

- No OTHER initialisation is permitted.


----
- Static member functions can have access to ONLY static methods. 
- 
----

# OBJECTS AS ARGUMENTS: 

- DEEP COPY =  a copy of entire copy is passed to the function = deep copy.
- Expensive operation
- Example = copy and pasting an entire file 
- Programs with deep copy take more time to load.

- SHALLOW COPY = a reference of the object's address is being passed to the function. 
- Lighter operation 
- Example = cutting and pasting a file (only the reference to the address is changed).

------
------
14th March, 2024 

# Friend Function: 

- When the word `friend` is used, we don't have private or public. 
- That means no class permission is required to use `friend` function. 

- It is not in the scope of the class (in which it has been declared as friend). 
- It is available throughout the program.
- Since it is NOT in the scope of the class, it cannot be called using the object of the class.

- It is NOT an object level member. 

- It can be INVOKED LIKE A NORMAL FUNCTION. [Obviously makes sense because its scope is program-level.]
- Unlike member objects, it CANNOT access the member names directly and has to use an object name like "t.a".

It means, to access variables you're gonna have to use dot operator. But not for the friend funciton itself.

- It can either be declared either in public or the private section of the class without affecting its meaning. 

- Generally, in friend functions parameters/arguments are objects. 

---
FORWARD DECLARATION: You promised the compiler that you'll declare the class properly later, so you just do forward-declaration for now like: `Class ABC;`
---

- Not only can you pass objects in friend functions, you can also RETURN objects. 


# CONST Member Function: 

- CHECK: Is `const` in C++ analogous to `final` in Java? 

- Syntax: 
```cpp
void fname(int, float, char) const;
```

# LOCAL CLASSES:

- Classes that are defined inside and used inside a FUNCTION or BLOCK. 
- Examples: If we're developing a DS like singly linked list, in that case we have an inner class called Node and that Node class will contain integer `data` and `Node next`. 

-----

# **CONSTRUCTOR AND DESTRUCTOR:** 

- It's called a `special` member function because NO OTHER MEMBER FUNCTION IS ALLOWED TO HAVE THE SAME NAME AS THAT OF THE CLASS. But only constructor is allowed.

- The point is to initialise the member variables WITHOUT EXPLICIT DEFINITION EVERY TIME. 
- So, a constructor AUTOMATICALLY initialises the member variables WITH DEFAULT VALUES;

- This is called AUTOMATIC INITIALISATION OF OBJECTS. 

- It also provides another member function called `destructor` - the purpose is to deallocate objects when they're no longer required.

- If you don't define constructor yourself, the language provides it automatically.
THAT SAID, if you do define a constructor, the language won't provide then. 

- It's called constructor because it builds the object in the memory, i.e., constructs the object in memory.


===

## Special characteristics of Constructors: 

1. They're always declared in public section of the class. [There is NO concept of private constructors in C++.]

2. They are invoked/called automatically when the objects are created. 

3. Constructors do NOT have any kind of return-type.
- There is NO return-type compilation model for constructors. 

---
# NEED TO UNDERSTAND THIS POINT BELOW: 

4. Constructors CANNOT BE INHERITED, though a derived class can call the base class constructor.
---

5. Constructors can have default argument: MEANING -> 
```cpp
Integer::Integer(int a = 7) {}

int main() {
  Integer a;
}
```
Will print a = 7


6. We CANNOT REFER TO THE ADDRESS OF A CONSTRUCTOR - For security reasons (that is why they don't have return-types. If they did, then their addresses could be traced back - which can lead to security breaches).

7. They make implicit calls to to the operators `new` (for allocation) and `delete` (for deallocation). [`new` is mainly used when we're allocating objects in the STACK (& HEAP IN JAVA); so do not confuse this explicit call with `new` keyword.]

===

## Parameterized Constructors: 

- The constructor that takes minimum 1 parameter and maximum `n` parameters. 

## CONSTRUCTOR OVERLOADING: Multiple Constructors in a class: 

- Example: in java you have println - irrespective of the datatype, it prints value. That is an example of Constructor Overload.
[It is kinda like Method Overload.]


-- Refer to the notes of lecture 16 for HOMEWORK QUESTIONS: -- 
- // Implement the addition function of two Complex Numbers.  
- // Leetcode homework: 1480, 1021, 1614.
--

-----
-----
_19th March, 2024_

# Linked List: 

-----
-----
4th April, 2024

# Binary Tree 

- Finite set of nodes 
- Special form of tree (TreeNodes), such that 
if T is empty (called Empty Binary Tree) or,
if T contains a specially designated node = Root Node 
and because of this root-node concept, we don't have the concept of Tree DS, instead we have `rooted tree` because of root node present in the tree. 

So, when you say `binary tree`, it actually means `rooted binary tree`.

It means, one node is designated as the root. 

- T contains the specially designated node called the root node, and the remaining nodes of T form the `Disjoint Binary Tree`.
T1 & T2 are called left sub tree (LST) and right sub tree (RST) respectively.

- No node can have more than 2 child nodes, that means a node can have 0, 1, 2 child nodes;

- A tree DS can NEVER be empty (due to AXIOMS OF GRAPH THEORY) BUT a Binary Tree DS can be empty.

- Remember, whatever we're studying here is ROOTED BINARY TREE. 
Tree > Binary Tree > Rooted Binary Tree

## Full Binary Tree and Complete Binary Tree: 

- Full Binary Tree: A binary tree is a full binary tree IF if contains the maximum possible number of nodes at all levels. 

- [Every full binary tree is a complete binary tree.]

- Complete Binary Tree: A binary tree is a complete binary tree IF all its levels, except possibly the last level, have the maximum number of possible nodes, and all the nodes at the last level appear as LEFT as possible.

- Complete binary tree MUST BE AS **LEFT-BIASED** AS POSSIBLE.

- Multiple trees = forest data structure 

## Properties of Binary Trees: 

# ASK SIR about this :-> 
- How does sometimes suddenly bank accounts receive huge number of amounts - SINCE BANKING SYSTEMS USE PRIME NUMBERS for generating unique IDs -
BECAUSE OF BIT MANIPULATION IT SOMETIMES HAPPENS that they receive huge amounts of money. 

-----
-----
8th April, 2024

- Binary trees can be implemented USING double linked lists. 

Convention: Left Child and Right Child are two link fields === reference fields === pointer fields;
and are used to store address of left child and right child tree nodes. 


- The two forms: Tree structure and Linked structre are lamost similar. 

- This similarity implies that the `linked representation` of binary tree very closely resembles the *logical structure of the data involved in linked list*.

- Other advantages: It allows `dynamic memory allocation`.

-----
*NOTE:*
- HW: Read about 'Locality of reference', "Why arrays are more cache-friendly and trees are not."
------

- The need for storing `reference of pointers`, requires extra memory and this can cause `Memory Overhead` ----> smth about `memory fragmentation` (ref: `memory defragmentation`)

- Array representation of tree: `buildTree.cpp` [Traversal = In-order]
- Linked representation of tree: `buildTree2.cpp` [Traversal = In-order]

- What if malloc fails to allocate memory? Ans: It returns `NULL`.

----

# Binary Search Tree: [BST]

## Operations on BST: 

*CRUD:*
- Create: in array, in linked list
- Read = Traversals: level order, in order 
- Update: insert/modify an element -> ANY MATHEMATICAL OPERATIONS CAN BE EXPECTED.
- Delete: delete one or more nodes 

## Insertion: 

- Insertion w.r.t. array: `bstArray.cpp`

----
*NOTE:*
HW: Write linked list representation of this. 
----

Ask about XOR linked lists and how they save memory, so why aren't they used for caching, if they arne't. I'm assuming complexity nah.

----
----
10th April, 2024 

# Level order traversal and all 


-------
-------
11th April, 2024

# Building Tree from Order:

File: `tree_from_level_order.cpp`


## Expression tree: 

An expression tree is binary tree which stores an arithmetic expression.
eg: 2 + 3 

- The leaf nodes of an expression are the operands such as constants and var names. 
- It is always a binary tree becaues expressions mostly have binary operators.

- 3 Types: 
  * 1. `Infix`: 2+3 
  * 2. `Postfix`: 23+ 
  * 3. `Prefix`: +23 
  
-- 
*Note:* STUDY `COMPILER DESIGN`.
** Expression tree is VV IMportant. 
--

* V cool he taught about how stacks use binary trees for postfix and all check. 
* Related to compiler design :) 

## Controversies related to Binary Search Tree (BST) 

- CLRS for BST
- Adam Drozdek for recursion
- Mark Allen Weiss for hashing

- 

----
----
15th April, 2024

# Hashing and Hashtable:

- Hash table is a data structure which organises data w.r.t. the hash functions in order to support quick read, update or delete operations.

- How quick? **ALMOST CONSTANT ORDER** TIME COMPLEXITY.

- There are 2 different kinds of hash tables: 
1. Hash Set 
2. Hash Map 

- HashSet is one of the implementations of `set` data structure to store NON-REDUNDANT DATA.
i.e., {1, 3, 2} == {1, 2, 1, 3, 3}

- HashMap is one of the implementation of `map` data structure to store `KEY-VALUE PAIRS`.

- `HashMap` in Java === `unordered_map` in C++ === `dict` data structure in Python

- `HashSet` in Java === `set` in C++ === `set` in Python

## OBJECTIVES: Hash Table: 

----
### Possible Interview Questions: 

- Q1: What is the principle of hash table? 
- Q2: How to design a hash table (HIGH LEVEL DESIGN and LOW LEVEL DESIGN)?
- Q3: How to use hash set to solve duplicacy-related problems? 
- Q4: How to use hash maps to aggregate information by key? 
- Q5: How to design proper keys in hash table? The design aspects focuses on how effectively key can be calculated so that the operations can be performed in constant time complexity (or somewhat equivalent).
- Q6: What factors influence the choice of the hash function and the collision resolution strategy? 
- Q7: Difference between hash map in hash set?  {Like, are they asking `Implementation`, `Design`, `Mathematical` aspects or what}

----

### Table: 

- When files are stored in the disk, they're stored in the form of KEYS.

- When the data is present in the disk === file structure === file handling
- When the data is present in the memory during program execution === data structure

- We want to find a record with a given key, K ->
  * The simplest way is to perform the linear search or sequential search (VERY different, both; depends on the context which search you go for), that is, start from the location of the first record, compare the given key K with the current record, if matches the nstop and return the location, else, proceed to the next data record till the end of the DS or the element is found. 

  * The searching time required is directly proportional to the number of records in the file. 
  * IF the number of records increases, then the computational time also increases for the search operation. HOWEVER, this searching time can be reduced significantly - even can made `Independent of the number of records`.

  * This change from `linear computational time` to `constant computational time` can be done using `DIRECT ACCESS TABLE`.

- *Direct Access Table*: 

-- The table may store the location of all the records of the file [LIKE, creating a reference of an app on desktop (like a shortcut)]

-- Info retrieval through table look up
-- This table look up is used every time you use a compiler. 

-- Symbol table [part of a compiler; used for token parsing] === Variation [implementation] of Hash table

-- STORAGE:
-- key -> passed to hashing function -> function creates an index -> data is stored in that index

-- RetrievalRETRIEVAL:
-- index -> passed to function -> function creates the reference to key -> key can be accessed

-- This method of accessing _ is called *table lookup* 


### Types of Tables: 

- Rectangular Tables === matrices
- Jagged Tables === ragged arrays === ragged tables === var length arrays in every location of 1D array === 

-- Ragged table's advantage is that it's memory-friendly because it saves storage space in main memory. 
-- Ragged table's disadvantage is that it's NOT cache-friendly because the locations cannot be precomputed => which means locality of reference princple [is NOT respected] in caching FAILS.

-----
NOTE: 
-- Implement matrices as ADT [= Abstract Data Type] on FRIDAY.
-----

## Direct Access Table ** (V. imptt.) 

- It is the principle on which Hash Tables are based.

- It is a simple technique that works well when the universe of discourse U of keys is reasonably small.

- Suppose, that an applicatin needs a dynamic set in which each element has a distinct key dran from the universe. U = [1, 2, ..., m - 1] where m < ∞

- To represent this dynamic set, we can use array, or DAT as an abstract type in python, ruby.

- This DAT (array, low level) is denoted by T: [0, 1, ..., n - 1] in which each position/slotcorresponds to Key in the universe U.

- For DAT, the create operation takes linear complexity.

- To overcome the problem of static size array for DAT, dynamic array can be used. 

- There's a lot of space wasted in DAT, hence, it is not good for memory perspective.

----
----
16th April, 2024

- Arrays are mostly restricted to size 10^7.

- Since there are memory 


-- Array itself is a hash table. How? Because your array is a sequence where every slot can be considered as an { index, val } pair. Where `index` is the key and `value` is the actual data.

- Based on the index, the correct memory location can be mapped.

- A hash table uses a hash function to compute the index, also called the hash value === hashcode, into an array of buckets, ...value can be found for corresponding hash <WHAT?>

- So during the look up operation the key is hashed and resulting hash indicates where the corresponding value is stored. 

----
- Amortization = taking average of all inputs. 
----

- Hashing generates the option for `Space vs Time Tradeoff`. 
- Generally, `time` is given the 1st priority and then space is given.
- Compared to the compute power, the memory is available in abundance. 


- If memory in infinite, the entire key can be used directly as an index to locate its value with single memory access instruction; practically, it is NOT possible; Direct Access Table (DAT) works the best in this case. 

- If infinite time is available, values can be stored without the regard of the keys, and Binary Search or Linear Search would work to retrieve the stored element.

- In many situations, hash table turn out to be, on average, more efficient than the search trees, or any other table lookup structure. 

- For this reason, it is used in many applications. 

## Properties of Hashing:

1. Deterministic (= The hashing function should always produce the same value for the key)
2. Collision Resistant (= Minimum collision)
3. Quick Computation (Almost/mostly constant time complexity)
4. Irreversible -->

Acceptable: 
```
key -> f(key) -> hash code 
```

*NOT ACCEPTABLE:*
```
hash code -> g(hc) -> index/key
```


----
----
18th April, 2024

Q: What is the mathematical reason behind collisions in hashing? 

A: Because of many-one functions in this more than 1 input from the domain set is mapped to a single output

The function that GOVERNS this mapping with or without collision is the HASH FUNCTION - is subset of the cartesian product of domain set (key set) and the range set (index set).

Again, HASH FUNCTION IS ALWAYS THE SUBSET OF DOMAIN SET (KEY SET) AND THE RANGE SET (INDEX SET).

- A particular hashing technique is a particular hash function. The hash function plays a dominant role in any certain hashing technique.

- The two principle criteria in deciding the hash function `H : K -> I` as follows: 

  * The function `H` should be computed using primitive instructions that takes constant computational time; 
  * The hash function algo will execute always a fixed number of steps to generate the indices present in the hash table table or the size of hash table.
  * `Quick` === `Constant computational time`.
  * The function `H` as far as possible should give two different indices for two different key values. In simple terms, the collision should be as simple as possible, IF not ZERO.

- As an example, consider a hash function whose indices are: 0, 1, 2, 3, ..., 8, 9.
- Suppose the key values are: 10, 19, 35, 43, 62, 59, 31,49, 77, 33.
- Let us assume that the hash function `H` is stated as below: 
  * Add both the digits of the 2 digit number considering that domain of keys are numbers less than 100. 
  * Then, take the digit at the unit place 10^0 of the result as an INDEX, ignore the tens place digit. 
  E.g. If number is 87, then digit sum is 15 mode 10, 5. Take that 5.
  * Using the above stated hash function... 
  Table and all - I'm not drawing here right now. 

  * What we got out of this example is that: The hash table had some empty slots. Space was wasted. Collision occurred and in some indices, more than one values were stored. 


### Some popular hash functions: 

1. `Division method` / `Modulo arithmetic function`: 

- One of the fastest hashing function and perhaps the most accepted. 
- Choose a number `h` larger than the number of keys `N` in key set in `K` === `h` should be slightly larger than the size of hash table.

- Generally, the mod hash function `H` is defined as follows: 
-- 0-based indexing: `H(k) = k(mod h)` + 0 
-- 1-based indexing: `H(k) = k(mod h) + 1`
-- i-based indexing: `H(k) = k(mod h) + i`

- The operator mod defines the modulo arithmetic operation, which is equal to the remainder of dividing `k` by `h`.
- For example, if `k = 31`, and table size is `30, we will take `h = 31`. 
Why prime? Because prime numbers have two factors and because of that too many collisions do not occur. Actual proof in cryptography. Idk rn.

- h(31) = 31(mod 13) + 0 = 5, 0-based indexing
- h(31) = 31(mod 13) + 1 = 5 + 1 = 6, 1-based indexing

- The number `h` is usually chosen to be a PRIME number or a number without smaller divisors, since this generally minimizes the number of collision. 

- Generally `h` is a prime number >= size of the hash table (just the next prime number compared to the hash table size). 

---- 
Write a program for it.
----

2. `Midsquare method`

- The hash function `H` is defined by `H(k) = x`, where `x` is obtained by selecting an appropriate number of bits of digits, from the middle of the square of the key value `k`.
e.g.: pick even pos digits: 23478, res = 73.

- Check online for examples. 

- Where Midsquare helps: If the DAT (Direct Access Table) limit is to handle 1K values, then if the input keys are of order 8 digits, then by Midsquare technique of hashing, we can adjust the values in order of 10^3.

- Here, it needs to be emphasized that same criteria should be used for selecting the bits for binary representation of digits for the decimal representation for all the keys.

- The downside of Midsquare method is that it is a time consuming algo because it involves mutiiplication. And multiplication requires repeated addition, hence, more pressure on the `adder circuit` at the architectural level of programming. 

- Microprogramming: `Multiplier Circuit`, `Adder circuit`


3. `Folding method`:

- In this hashing method, we create partition for the key `k`, in number of parts as `k1`, `k2`, ..., `kn`, where each part, except possibly the last part, has same number of bits for binary representation and digits for the decimal representation as the required address width.

- Then the parts are added together, ignoring the last carry, if any carry exists. 

- Then, these parts are added together. 

- Alternatively, `H(k) = k1 + k2 + k3 + ... + kn`; where the last carry (if generated) is ignored. 

- If the keys are in binary form, then XOR operation is used because addition level is more expensive at bit level - from hardware point of view. 

- There can be many variations in the `Folding method`:

  * One is called `Fold Shifting Method`, where the even parts, k2, k4, ..., are reversed before the addition. 

  * `Pure Folding`
  * `Fold Shifting`
  * `Fold boundary`

- `Folding` is a hashing function which is also useful in converting `multi-word` keys into a single word so that another hashing function can be used on that.
- EXAMPLE: SEARCHING ON WIKIPEDIA

- In fact, the term hashing comes from this technique of chopping a key into smaller pieces.


4. `Digit Analysis Method`:

- The basic idea is: form the hash addresses by extracting and/or shifting the extracted digits or bits. 
- `Midsquare` is a special case of `Digit Analysis Method`.

- ...

...

- This method is particularly used in the case of static files where the key values of all the recods are known in advance we have assummed that the key values as integers in our prev discussion but it can be in text format or even binary file. 

- In fact, any key value can be represented by a string of characters and then ASCII values can be taken:
e.g.: "abc" hash value is required, 
97, 98, 99; add(97, 98, 99) = 294
- There is a subtle point here, if abc are 3 distinct letters then total `3! = 6` permutations are possible.

- This would lead to many-to-one function generation which is not desirable in hashing. 
- If `n` distinct characters are there `n!` collisions.
- Asymptotically, `n! ~= n^n`, worst amount collisions would occur. 

- The solution that can be considered is `WEIGHTED CHAR METHOD`

- Weighted prime calculation would give minimum amount of collisions.

- `abc === 97 x 3^2 + 98 x 3^1 + 99 x 3^0`
- `abc === 1266`

- `cab === 99 x 3^2 + 97 x 3^1 + 98 x 3^0`
- `cab === 1280`

- Thus, o collisions.

- Now, for this weighted primes with ASCII value of characters would not create collisions and, hence, it solves the problem. 

- If `n` distinct letters are there, if weighted prime technique is applied then `n!` collisions won't take place compared to non weighted prime hash calculation.


## Collision Resolution Techniques (CRTs)

- Whatever the hash function is used, the complete removal of collisions is almost impossible. This can be understood by the concept of `Birthday Paradox (probability)`.

----
#### Birthday Paradox: 

Consider there are 24 students in class and they are having same year or birth. We want to know what is the probability that two students have the same DOB? 
The probability can be calculated based on the following assumptions: 
  * Consider the calender carries 365 days only (leaving lear year)
  * Start with any student, and put a tick on his/her birthday on the calender. Now, the probability that the second student has different birthday is: `p(364/365)`
  * Mark this day off. 
  * Now, the probability that the third student has a different birthday is: `p(363/365)`.

Continuing this way, we see that if the first (n - 1) students have distinct birtdays, then the probability that the n-th student has different birthday is: 
(365 - (n - 1))/365 = (365 - n + 1)/365 

- Since the birtdays of different students are independent, we obtain the probability of total event by multiplication principle:

364/365 x 364/365 x 363/365 x ... x (365 - n + 1)/365 

- This probability can be calculated as approximately, ~ 0.5 for n >= 24.

***
- In other words, suppose there is a hash table of size 365, and we want to store the records of all the 24 students based on their birthdays as their key values, it is therefore a `50-50` chance that two students have same b'day.

- Like, even though size of hash table is 365, and more than 200 places are values, even for just 24 values there is a almost `50-50` CHANCE OF COLLISIONS!
***

- So, from this probability model we can say that collision cannot be ignored 100%, except for the case of direct address table (DAT). 

- An ideal hash function must do one-to-one mapping. All input set (key set) and all index set (range), but this is almost impossible because of probability of the above paradox.

----

- Two major CRTs are: 

1. `Open Addressing (Also called, CLOSED HASHING)`
2. `Linear Probing`
3. `Quadratic Probing`
4. `Polynomial Probing` 

5. `Double hashing` - It comes under `Open Hashing`
6. `Separate Chaining` - Also called, `OPEN HASHING`: Because to handle the collision we use auxiliary DS like dynamic array or linked list or even trees.
