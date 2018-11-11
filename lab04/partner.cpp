/*
 * HUST-CXX-Labs lab04::partner
 * 
 * Created by zxcpyp
 * 
 * Github: zxc479773533
 */

#include "queue.h"

using namespace std;

int main() {
  int M, F;
  int m, f;
  // Input data
  cout << "Please input the Male and Female num: " << endl;
  cin >> M >> F;
  cout << "Please input the man and woman No. :" << endl;
  cin >> m >> f;
  // Initial queue
  QUEUE *male_queue = new QUEUE(M);
  QUEUE *famale_queue = new QUEUE(F);
  for (int i = 0; i < M; i++) {
    if (i == m - 1)
      *(male_queue) << 1;
    else
      *(male_queue) << 0;
  }
  for (int i = 0; i < F; i++) {
    if (i == f - 1)
      *(famale_queue) << 1;
    else
      *(famale_queue) << 0;
  }
  // Solve
  int count = 0;
  while (true) {
    count++;
    int now_man, now_woman;
    *(male_queue) >> now_man;
    *(famale_queue) >> now_woman;
    if (now_man == 1 && now_woman == 1)
      break;
    *(male_queue) << now_man;
    *(famale_queue) << now_woman;
  }
  cout << "The answer is " << count << endl;
  return 0;
}