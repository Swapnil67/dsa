/*
 * Leetcode - 1701
 * Average Waiting Time
 
 * Example 1:
 * Input       : customers = [[1,2],[2,5],[4,3]]
 * Output      : 5.0000
 * Explanation :
 * 1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1,
 * and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
 * 2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, 
 * and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
 * 3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, 
 * and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
 * So the average waiting time = (2 + 6 + 7) / 3 = 5.
 * 
 * Example 2:
 * Input      : customers = [[5,2],[5,4],[10,3],[20,1]]
 * Output     : 3.2500
 * 
 * https://leetcode.com/problems/average-waiting-time/description/
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
double averageWaitingTime(std::vector<std::vector<int>> &customers) {
  int n = customers.size();

  double total_wait_time = 0.0;
  double cur_time = customers[0][0];

  for (auto &order: customers) {
    double arrival_time = (double)order[0];
    double cook_time = (double)order[1];

    if (arrival_time <= cur_time) {
      // * Only if arrival time is less than the current time
      total_wait_time += (cur_time + cook_time) - arrival_time;
      cur_time += cook_time;
      // std::cout << total_wait_time << " " << cur_time << std::endl;
    } else {
      cur_time = arrival_time + cook_time;
      total_wait_time += cur_time - arrival_time;
      // std::cout << total_wait_time << " " << cur_time << std::endl;
    }
  }
  return (double)(total_wait_time / n);
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};

  // * testcase 2
  std::vector<std::vector<int>> customers = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};

  std::cout << "Customers" << std::endl;
  for (auto &vec : customers)
    printArr(vec);

  double ans = averageWaitingTime(customers);
  std::cout << "Average Waiting Time: " << ans << std::endl;
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 01-average-waiting-time.cpp -o output && ./output