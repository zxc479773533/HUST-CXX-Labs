/*
 * HUST-CXX-Labs lab02::headfile
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#ifndef HUST_CXX_LAB02
#define HUST_CXX_LAB02

#include <iostream>
#include <cstring>

class STACK {
  int *const elems; // Store the elem
  const int max;    // Max elem nums
  int pos;          // Elem nums
public:
  STACK(int m);                  // Initial the stack with m elem at most
  STACK(const STACK &s);         // Initial the stack using another stack
  int size() const;              // Get the max num in stack p
  int howMany() const;           // Get the elem num in stack p
  int getelem(int x) const;      // Get the elem at pos x in stack p
  STACK &push(int e);            // Push e into stack p
  STACK &pop(int &e);            // Pop an elem out of stack p
  STACK &assign(const STACK &s); // Assign data from s to p
  void print() const;            // Print data of p
  ~STACK();                      // Destroy the stack
};

#endif // !HUST_CXX_LAB02
