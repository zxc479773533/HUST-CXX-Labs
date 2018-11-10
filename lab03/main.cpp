/*
 * HUST-CXX-Labs lab03::main
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
  STACK *mystack = nullptr;
  // Set output file
  cmd_paresr lab01_parser = cmd_paresr(argc, argv);
  while (lab01_parser.now_pos() < lab01_parser.ops_num()) {
    queue<int> arg_list;
    op = lab01_parser.next_step(arg_list);
    switch (op) {
      case 'S': {
        cout << "S";
        arg = arg_list.front();
        mystack = new STACK(arg);
        cout << " " << arg;
        arg_list.pop();
        break;
      }
      case 'I': {
        cout << " I";
        int size = arg_list.size();
        // Test if the stack can overflow
        if (mystack->size() - int(*mystack) < size) {
          cout << " E" << endl;
          exit(0);
        }
        for (int i = 0; i < size; i++) {
          arg = arg_list.front();
          *mystack << arg;
          arg_list.pop();
        }
        cout << " ";
        mystack->print();
        break;
      }
      case 'O': {
        cout << " O";
        int e;
        arg = arg_list.front();
        // Test if the stack can be empty
        if (int(*mystack) < arg) {
          cout << " E" << endl;
          exit(0);
        }
        for (int i = 0; i < arg; i++)
          *mystack >> e;
        arg_list.pop();
        if (int(*mystack) != 0) {
          cout << " ";
          mystack->print();
        }
        break;
      }
      case 'A': {
        cout << " A";
        arg = arg_list.front();
        STACK *new_stack = new STACK(arg);
        *new_stack = *mystack;
        mystack = new_stack;
        arg_list.pop();
        cout << " ";
        mystack->print();
        break;
      }
      case 'C': {
        cout << " C";
        STACK *new_stack = new STACK(*mystack);
        mystack = new_stack;
        cout << " ";
        mystack->print();  
        break;
      }
      case 'N': {
        cout << " N";
        cout << " " << int(*mystack);
        break;
      }
      case 'G': {
        cout << " G";
        arg = arg_list.front();
        if (arg >= int(*mystack)) {
          cout << " E" << endl;
          exit(0);
        }
        cout << " " << mystack[arg];
        arg_list.pop();
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
