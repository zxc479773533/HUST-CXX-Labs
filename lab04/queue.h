/*
 * HUST-CXX-Labs lab04::headfile
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#ifndef HUST_CXX_LAB04
#define HUST_CXX_LAB04

#include "stack.h"

class QUEUE : public STACK {
  STACK s2;
public:
  QUEUE(int m);                             // Initial a 2m length queue
  QUEUE(const QUEUE &s);                    // Initial the queue using another queue
  virtual operator int() const;             // Get the elem num in queue p
  virtual int full() const;                 // Judge if the queue is full, return 1 for full or return 0
  virtual int operator[](int x) const;      // Get the elem at pos x in queue p
  virtual QUEUE &operator<<(int e);         // Push e into queue p
  virtual QUEUE &operator>>(int &e);        // Pop an elem out of queue p
  virtual QUEUE &operator=(const QUEUE &s); // Assign data from s to p
  virtual void print() const;               // Print data of p
  virtual ~QUEUE();                         // Destroy the stack
};

#endif // !HUST_CXX_LAB04
