/*
 * HUST-CXX-Labs Command line parser::head
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#ifndef HUST_CXX_CMDLINE

#include <iostream>
#include <queue>

using namespace std;

class cmd_paresr {
  int opnum;              // Operation nums
  int pos;                // The next ops to be parsed
  queue<char> ops;        // Operations
  queue<queue<int>> args; // Arguments for ops
public:
  cmd_paresr(int argc, char **argv);
  char next_step(queue<int> &arg_queue);
  int now_pos();
  int ops_num();
  ~cmd_paresr() = default;
};

#endif // !HUST_CXX_CMDLINE
