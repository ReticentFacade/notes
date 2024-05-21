#include<iostream>
#include<new>
// using namespace std;

int main() {
  int* num_ptr = nullptr;

  try {
    // allocating memory to store that dynamic integer: 
    num_ptr = new int;

    *num_ptr = 42;
    // dereferencing the pointer 
    std::cout << "Dynamic Number : " << *num_ptr << std::endl;
  } catch (const std::bad_alloc& e) {
    return 1; // sentinel value;
  }
  
  // deallocating memory
  delete num_ptr;

  return 0;
}

