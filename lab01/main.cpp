/*
 * HUST-CXX-Labs lab01::main
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#include <iostream>
#include "stack.h"
#include "cmd_parser.h"

using namespace std;

int main(int argc, char **argv) {
  char op;
  int arg;
  STACK *p = NULL;
  // Set output file
  cmd_paresr lab01_parser = cmd_paresr(argc, argv);
  while (lab01_parser.now_pos() < lab01_parser.ops_num()) {
    queue<int> arg_list;
    op = lab01_parser.next_step(arg_list);
    switch (op) {
      case 'S': {
        cout << "S";
        arg = arg_list.front();
        p = (STACK*)malloc(sizeof(STACK));
        initSTACK(p, arg);
        if (p == NULL) {
          cout << " E" << endl;
          exit(0);
        }
        cout << " " << arg;
        arg_list.pop();
        break;
      }
      case 'I': {
        cout << " I";
        int size = arg_list.size();
        // Test if the stack can overflow
        if (p->max - p->pos < size) {
          cout << " E" << endl;
          exit(0);
        }
        for (int i = 0; i < size; i++) {
          arg = arg_list.front();
          p = push(p, arg);
          arg_list.pop();
        }
        // Out put the elems in stack
        for (int i = 0; i < p->pos; i++) {
          cout << " " << p->elems[i];
        }
        break;
      }
      case 'O': {
        cout << " O";
        // Test if the stack can be empty
        if (p->pos < arg_list.size()) {
          cout << " E" << endl;
          exit(0);
        }
        int e;
        arg = arg_list.front();
        for (int i = 0; i < arg; i++)
          p = pop(p, e);
        arg_list.pop();
        // Out put the elems in stack
        for (int i = 0; i < p->pos; i++) {
          cout << " " << p->elems[i];
        }
        break;
      }
      case 'A': {
        cout << " A";
        arg = arg_list.front();
        STACK *new_stack = (STACK*)malloc(sizeof(STACK));
        initSTACK(new_stack, arg);
        new_stack = assign(new_stack, *p);
        p = new_stack;
        arg_list.pop();
        // Out put the elems in stack
        for (int i = 0; i < p->pos; i++) {
          cout << " " << p->elems[i];
        }
        break;
      }
      case 'C': {
        cout << " C";
        STACK *new_stack = (STACK*)malloc(sizeof(STACK));
        initSTACK(new_stack, *p);
        p = new_stack;
        break;
      }
      case 'N': {
        cout << " N";
        cout << " " << p->pos;        
        break;
      }
      case 'G': {
        cout << " G";
        arg = arg_list.front();
        cout << " " << p->elems[arg];
        arg_list.pop();
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
