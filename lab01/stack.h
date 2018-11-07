/*
 * HUST-CXX-Labs lab01::headfile
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#ifndef HUST_CXX_LAB01
#define HUST_CXX_LAB01

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STACK {
  int *elems; // Store the elem
  int max;    // Max elem nums
  int pos;    // Elem nums
} STACK;

// Operations on stack

/*
 * initSTACK - Initial the stack with m elem at most
 * parameters：
 *  p: stack pointer
 *  m: max elem nums
 * return: void
 */
void initSTACK(STACK *const p, int m);

/*
 * initSTACK - Initial the stack using another stack
 * parameters：
 *  p: stack pointer
 *  m: another stack's reference
 * return: void
 */
void initSTACK(STACK *const p, const STACK &s);

/*
 * size - Get the max elem num of stack p
 * parameters：
 *  p: stack pointer
 * return: the max elem num of p
 */
int size(const STACK *const p);

/*
 * howMany - Get the elem num in stack p
 * parameters：
 *  p: stack pointer
 * return: the elem num in p
 */
int howMany(const STACK *const p);

/*
 * getelem - Get the elem at pos x in stack p
 * parameters：
 *  p: stack pointer
 *  x: pos
 * return: the elem at pos x
 */
int getelem(const STACK *const p, int x);

/*
 * push - Push e into stack p
 * parameters：
 *  p: stack pointer
 *  e: new elem
 * return: the stack pointer
 */
STACK *const push(STACK *const p, int e);

/*
 * pop - Pop an elem out of stack p
 * parameters：
 *  p: stack pointer
 *  &e: new elem
 * return: the stack pointer
 */
STACK *const pop(STACK *const p, int &e);

/*
 * assign - Assign data from s to p
 * parameters：
 *  p: stack pointer
 *  &s: data
 * return: the stack pointer
 */
STACK *const assign(STACK *const p, const STACK &s);

/*
 * print - Print data of p
 * parameters：
 *  p: stack pointer
 * return: void
 */
void print(const STACK *const p);

/*
 * destroySTACK - Destroy the stack
 * parameters：
 *  p: stack pointer
 * return: void
 */
void destroySTACK(STACK *const p);

#endif // !HUST_CXX_LAB01
