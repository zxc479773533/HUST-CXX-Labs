/*
 * HUST-CXX-Labs lab02::main
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
        if (mystack->size() - mystack->howMany() < size) {
          cout << " E" << endl;
          exit(0);
        }
        for (int i = 0; i < size; i++) {
          arg = arg_list.front();
          mystack->push(arg);
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
        if (mystack->howMany() < arg) {
          cout << " E" << endl;
          exit(0);
        }
        for (int i = 0; i < arg; i++)
          mystack->pop(e);
        arg_list.pop();
        if (mystack->howMany() != 0) {
          cout << " ";
          mystack->print();
        }
        break;
      }
      case 'A': {
        cout << " A";
        arg = arg_list.front();
        STACK *new_stack = new STACK(arg);
        new_stack->assign(*mystack);
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
        cout << " " << mystack->howMany();        
        break;
      }
      case 'G': {
        cout << " G";
        arg = arg_list.front();
        if (arg >= mystack->howMany()) {
          cout << " E" << endl;
          exit(0);
        }
        cout << " " << mystack->getelem(arg);
        arg_list.pop();
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
