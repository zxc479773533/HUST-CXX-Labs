/*
 * HUST-CXX-Labs Command line parser::implementation
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#include "cmd_parser.h"

cmd_paresr::cmd_paresr(int argc, char **argv) {
  pos = 0;
  opnum = 0;
  for (int i = 1; i < argc; i++) {
    // Set operation
    ops.push(argv[i][1]);
    queue<int> tmp;
    opnum++;
    i++;
    // Get args
    while (i < argc && argv[i][0] != '-')
      tmp.push(atoi(argv[i++]));
    // Set args
    args.push(tmp);
    i--;
  }
}

char cmd_paresr::next_step(queue<int> &arg_queue) {
  if (pos < opnum) {
    char op = ops.front();
    arg_queue = args.front();
    ops.pop();
    args.pop();
    pos++;
    return op;
  }
  return '\0';
}

int cmd_paresr::now_pos() {
  return pos;
}

int cmd_paresr::ops_num() {
  return opnum;
}