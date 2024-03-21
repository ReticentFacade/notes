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

