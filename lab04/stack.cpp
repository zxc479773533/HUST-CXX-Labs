/*
 * HUST-CXX-Labs lab03::implementation
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#include "stack.h"
#include <stdexcept>

/*
 * STACK::STACK - Initial the stack with m elem at most
 * parameters：
 *  m: max elem nums
 * 
 * Constructor
 */
STACK::STACK(int m) : elems(new int [m]), max(m), pos(0) {}

/*
 * STACK::STACK - Initial the stack using another stack
 * parameters：
 *  s: another stack's reference
 * 
 * Constructor
 */
STACK::STACK(const STACK &s) : elems(s.elems), max(s.max), pos(s.pos) {}

/*
 * STACK::size - Get the max elem num of stack p
 * parameters：
 *  None
 * return: the max elem num of p
 */
int STACK::size() const {
  return max;
}

/*
 * STACK::operator int - Get the elem num in stack p
 * parameters：
 *  None
 * return: the elem num in p
 */
STACK::operator int () const {
	return pos;
}

/*
 * STACK::operator[] - Get the elem at pos x in stack p
 * parameters：
 *  x: pos
 * return: the elem at pos x
 */
int STACK::operator[](int x) const {
  if (x < 0 || x >= pos)
    throw std::out_of_range("[ERROR] Index out of range!");
	return elems[x];
}

/*
 * STACK::operator << - Push e into stack p
 * parameters：
 *  e: new elem
 * return: the stack'reference
 */
STACK &STACK::operator << (int e) {
  if (pos == max)
    throw std::overflow_error("[ERROR] Stack overflowed!");
	elems[pos] = e;
	pos++;
	return *this;
}

/*
 * STACK::operator >> - Pop an elem out of stack p
 * parameters：
 *  &e: new elem
 * return: the stack'reference
 */
STACK &STACK::operator >> (int &e) {
  if (pos == 0)
    throw std::underflow_error("[ERROR] Stack underflowed!");
	e = elems[pos - 1];
	pos--;
	return *this;
}

/*
 * STACK::operator = - Assign data from s to p
 * parameters：
 *  &s: data
 * return: the stack'reference
 */
STACK &STACK::operator = (const STACK &s) {
  memcpy(elems, s.elems, s.max * sizeof(int));
  *((int*)&max) = s.max;
  pos = s.pos;
  return *this;
}

/*
 * STACK::print - Print data of p
 * parameters：
 *  None
 * return: void
 */
void STACK::print() const {
  for (int i = 0; i < pos; i++) {
    std::cout << elems[i];
    if (i != pos - 1)
      std::cout << " ";
  }
}

/*
 * STACK::~STACK - Destroy the stack
 * parameters：
 * 
 * Destructor
 */
STACK::~STACK() {
  if (elems)
    delete [] elems;
}
