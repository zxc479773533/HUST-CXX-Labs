/*
 * HUST-CXX-Labs lab04::implementation
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#include "queue.h"
#include <stdexcept>

/*
 * QUEUE::QUEUE - Initial the queue with m elem at most
 * parameters：
 *  m: max elem nums
 * 
 * Constructor
 */
QUEUE::QUEUE(int m) : STACK(m), s2(m) {}

/*
 * QUEUE::QUEUE - Initial the queue using another queue
 * parameters：
 *  s: another stack's reference
 * 
 * Constructor
 */
QUEUE::QUEUE(const QUEUE &s) : STACK(s), s2(s.s2) {}

/*
 * QUEUE::operator int - Get the elem num in queue p
 * parameters：
 *  None
 * return: the elem num in p
 */
QUEUE::operator int () const {
	return this->STACK::operator int() + int(s2);
}

/*
 * QUEUE::full - Judge if the queue is full
 * parameters：
 *  None
 * return: return 1 for full or return 0
 */
int QUEUE::full() const {
  if (this->STACK::operator int() == this->size() && int(s2) != 0)
    return 1;
  return 0;
}


/*
 * QUEUE::operator[] - Get the elem at pos x in queue p
 * parameters：
 *  x: pos
 * return: the elem at pos x
 */
int QUEUE::operator[](int x) const {
  if (x < 0 || x >= int(*this))
    throw std::out_of_range("[ERROR] Index out of range!");
  // If x in the output stack
	if (x < this->STACK::operator int())
    return s2[int(s2) - 1 - x];
  // X in the input stack
  else
    return this->STACK::operator[](x - int(s2));
}

/*
 * QUEUE::operator << - Push e into queue p
 * parameters：
 *  e: new elem
 * return: the stack'reference
 */
QUEUE &QUEUE::operator << (int e) {
  if (full() == 1)
    throw std::overflow_error("[ERROR] Queue overflowed!");
	// If input stack is full
  int tmp;
  int input_length = this->STACK::operator int();
  if (input_length == this->size()) {
    for (int i = 0; i < input_length; i++) {
      this->STACK::operator>>(tmp);
      s2 << tmp;
    }
  }
  this->STACK::operator<<(e);
	return *this;
}

/*
 * QUEUE::operator >> - Pop an elem out of queue p
 * parameters：
 *  &e: new elem
 * return: the stack'reference
 */
QUEUE &QUEUE::operator >> (int &e) {
  if (int(*this) == 0 && e != 0)
    throw std::underflow_error("[ERROR] Queue underflowed!");
	// If output stack is empty
  int tmp;
  int input_length = this->STACK::operator int();
  if (int(s2) == 0) {
    for (int i = 0; i < input_length; i++) {
      this->STACK::operator>>(tmp);
      s2 << tmp;
    }
  }
  s2 >> e;
	return *this;
}

/*
 * QUEUE::operator = - Assign data from s to p
 * parameters：
 *  &s: data
 * return: the stack'reference
 */
QUEUE &QUEUE::operator = (const QUEUE &s) {
  this->STACK::operator=(s);
  s2 = s.s2;
  return *this;
}

/*
 * QUEUE::print - Print data of p
 * parameters：
 *  None
 * return: void
 */
void QUEUE::print() const {
  int output_len = int(s2);
  int input_len = this->STACK::operator int();
  if (output_len != 0) {
    for (int i = 0; i < output_len; i++) {
      std::cout << s2[output_len - 1 - i];
      if (i != output_len - 1)
        std::cout << " ";
    }
  }
  if (output_len != 0 && input_len != 0)
    std::cout << " ";
  if (input_len != 0) {
    for (int i = 0; i < input_len; i++) {
      std::cout << this->STACK::operator[](i);
      if (i != input_len - 1)
        std::cout << " ";
    }
  }
}

/*
 * QUEUE::~QUEUE - Destroy the queue
 * parameters：
 * 
 * Destructor
 */
QUEUE::~QUEUE() {}
