/*
 * Leetcode - 1882
 * Process Tasks Using Servers
 * 
 * You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. 
 * servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.
 * 
 * Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.
 * 
 * At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). 
 * As long as there are free servers and the queue is not empty, the task in the front of the queue will be 
 * assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server 
 * with the smallest index.
 * 
 * If there are no free servers and the queue is not empty, we wait until a server becomes free and 
 * immediately assign the next task. If multiple servers become free at the same time, then multiple tasks 
 * from the queue will be assigned in order of insertion following the weight and index priorities above.
 * 
 * A server that is assigned task j at second t will be free again at second t + tasks[j].

 * Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.

 * Example 1
 * input  : servers = [3,3,2], tasks = [1,2,3,2,1,2]
 * output : [2,2,0,2,1,2]

 * Example 2
 * input  : servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
 * output : [1,4,1,4,1,3,2]
 * 
 * https://leetcode.com/problems/process-tasks-using-servers/description/
*/

// ! Google

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::vector<int> assignTasks(std::vector<int> &servers, std::vector<int> &tasks) {
  int n = servers.size(), m = tasks.size();

  typedef long long ll;
  typedef std::pair<ll, ll> P;

  // * 1. Push all the servers to available min heap
  std::priority_queue<P, std::vector<P>, std::greater<>> free;
  for (int i = 0; i < n; ++i) {
    free.emplace(servers[i], i);
  }

  // * for debugging
  // while (!free.empty()) {
  //   P p = free.top();
  //   free.pop();
  //   std::cout << p.first << " " << p.second << std::endl;
  // }

  std::priority_queue<std::vector<ll>, std::vector<std::vector<ll>>, std::greater<>> busy;

  long long time = 0;
  std::vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    time = std::max(time, (ll)i);

    // * If there is no free server 
    if (free.empty()) { // * check testcase 3
      time = busy.top()[0];
    }

    // * Find servers whose tasks are finished and push them to `free` heap
    while (!busy.empty() && busy.top()[0] <= time) {
      auto server = busy.top();
      busy.pop();
      free.emplace(server[1], server[2]);
    }

    auto [weight, index] = free.top();
    free.pop();
    ans[i] = index;
    busy.push({(time + (long long)tasks[i]), weight, index});
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<int> servers = {3, 3, 2}, tasks = {1, 2, 3, 2, 1, 2};
  
  // * testcase 2
  std::vector<int> servers = {5, 1, 4, 3, 2}, tasks = {2, 1, 2, 4, 5, 2, 1};
  
  // * testcase 2
  // std::vector<int> servers = {10, 63, 95, 16, 85, 57, 83, 95, 6, 29, 71}, tasks = {70, 31, 83, 15, 32, 67, 98, 65, 56, 48, 38, 90, 5};

  std::cout << "Servers: ";
  printArr(servers);
  std::cout << "Tasks: ";
  printArr(tasks);

  std::vector<int> ans = assignTasks(servers, tasks);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-process-tasks-using-servers.cpp -o output && ./output