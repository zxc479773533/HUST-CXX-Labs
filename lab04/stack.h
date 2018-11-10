/*
 * HUST-CXX-Labs lab03::headfile
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#ifndef HUST_CXX_LAB03
#define HUST_CXX_LAB03

#include <iostream>
#include <cstring>

class STACK {
  int *const elems; // Store the elem
  const int max;    // Max elem nums
  int pos;          // Elem nums
public:
  STACK(int m);                               // Initial the stack with m elem at most
  STACK(const STACK &s);                      // Initial the stack using another stack
  virtual int size() const;                   // Get the max num in stack p
  virtual operator int () const;              // Get the elem num in stack p
  virtual int operator[] (int x) const;       // Get the elem at pos x in stack p
  virtual STACK &operator << (int e);         // Push e into stack p
  virtual STACK &operator >> (int &e);        // Pop an elem out of stack p
  virtual STACK &operator = (const STACK &s); // Assign data from s to p
  virtual void print() const;                 // Print data of p
  virtual ~STACK();                           // Destroy the stack
};

#endif // !HUST_CXX_LAB03
