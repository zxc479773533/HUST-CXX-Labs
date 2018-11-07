/*
 * HUST-CXX-Labs lab01::implementation
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#include "stack.h"

/*
 * initSTACK - Initial the stack with m elem at most
 */
void initSTACK(STACK *const p, int m) {
	p->elems = (int*)malloc(sizeof(int) * m);
	if (p != NULL) {
		p->max = m;
		p->pos = 0;
	}
}


/*
 * initSTACK - Initial the stack using another stack
 */
void initSTACK(STACK *const p, const STACK &s) {
	p->elems = (int*)malloc(sizeof(int) * s.max);
	if (p != NULL) {
		memcpy(p->elems, s.elems, s.max * sizeof(int));
		p->max = s.max;
		p->pos = s.pos;
	}
}

/*
 * size - Get the max elem num of stack p
 */
int size(const STACK *const p) {
	if (p == NULL)
		return 0;
	return p->max;
}

/*
 * howMany - Get the elem num in stack p
 */
int howMany(const STACK *const p) {
	if (p == NULL)
		return 0;
	return p->pos;
}

/*
 * getelem - Get the elem at pos x in stack p
 */
int getelem(const STACK *const p, int x) {
	if (p == NULL || x < 0 ||  x >= p->pos)
		return 0;
	return p->elems[x];
}

/*
 * push - Push e into stack p
 */
STACK *const push(STACK *const p, int e) {
	if (p == NULL)
		return NULL;
	// Stack full
	if (p->pos == p->max)
		return NULL;
	// Add new data
	p->elems[p->pos] = e;
	p->pos++;
	return p;
}

/*
 * pop - Pop an elem out of stack p
 */
STACK *const pop(STACK *const p, int &e) {
	if (p == NULL)
		return NULL;
	// Stack empty
	if (p->pos == 0)
		return NULL;
	// New data
	e = p->elems[p->pos];
	p->pos--;
	return p;
}

/*
 * assign - Assign data from s to p
 */
STACK *const assign(STACK *const p, const STACK &s) {
  if (p != NULL) {
    memcpy(p->elems, s.elems, s.max * sizeof(int));
    p->max = s.max;
    p->pos = s.pos;
  }
  return p;
}

/*
 * print - Print data of p
 */
void print(const STACK *const p) {
	if (p != NULL && p->pos > 0) {
		for (int i = 0; i < p->pos - 1; i++) {
			printf("%d ", p->elems[i]);
		}
		printf("%d", p->elems[p->pos - 1]);
	}
}

/*
 * destroySTACK - Destroy the stack
 */
void destroySTACK(STACK *const p) {
	if (p != NULL) {
		free(p->elems);
		free(p);
	}
}
