/*
 * HUST-CXX-Labs lab04::main
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#include <iostream>
#include "queue.h"
#include "cmd_parser.h"

using namespace std;

int main(int argc, char **argv) {
  char op;
  int arg;
  QUEUE *myqueue = nullptr;
  // Set output file
  cmd_paresr lab01_parser = cmd_paresr(argc, argv);
  while (lab01_parser.now_pos() < lab01_parser.ops_num()) {
    queue<int> arg_list;
    op = lab01_parser.next_step(arg_list);
    switch (op) {
      case 'S': {
        cout << "S";
        arg = arg_list.front();
        myqueue = new QUEUE(arg);
        cout << " " << arg;
        arg_list.pop();
        break;
      }
      case 'I': {
        cout << " I";
        int size = arg_list.size();
        for (int i = 0; i < size; i++) {
          // Test if the stack can overflow
          if (myqueue->full()) {
            if (myqueue->size() - int(*myqueue) < size) {
              cout << " E" << endl;
              exit(0);
            }
          }
          arg = arg_list.front();
          *myqueue << arg;
          arg_list.pop();
        }
        cout << " ";
        myqueue->print();
        break;
      }
      case 'O': {
        cout << " O";
        int e;
        arg = arg_list.front();
        // Test if the stack can be empty
        if (int(*myqueue) < arg) {
          cout << " E" << endl;
          exit(0);
        }
        for (int i = 0; i < arg; i++)
          *myqueue >> e;
        arg_list.pop();
        if (int(*myqueue) != 0) {
          cout << " ";
          myqueue->print();
        }
        break;
      }
      case 'A': {
        cout << " A";
        arg = arg_list.front();
        QUEUE *new_stack = new QUEUE(arg);
        *new_stack = *myqueue;
        myqueue = new_stack;
        arg_list.pop();
        cout << " ";
        myqueue->print();
        break;
      }
      case 'C': {
        cout << " C";
        QUEUE *new_stack = new QUEUE(*myqueue);
        myqueue = new_stack;
        cout << " ";
        myqueue->print();
        break;
      }
      case 'N': {
        cout << " N";
        cout << " " << int(*myqueue);        
        break;
      }
      case 'G': {
        cout << " G";
        arg = arg_list.front();
        if (arg >= int(*myqueue)) {
          cout << " E" << endl;
          exit(0);
        }
        cout << " " << myqueue[arg];
        arg_list.pop();
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
