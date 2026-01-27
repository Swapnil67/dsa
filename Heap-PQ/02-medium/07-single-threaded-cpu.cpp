/*
 * Leetcode - 1834
 * Single-Threaded CPU
 * 
 * You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks,
 * where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at
 * enqueueTimei and will take processingTime 'i' to finish processing.

 * You have a single-threaded CPU that can process at most one task at a time and will act in the following way:
 * 
 * - If the CPU is idle and there are no available tasks to process, the CPU remains idle.
 * - If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing 
 *   time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
 * - Once a task is started, the CPU will process the entire task without stopping.
 * - The CPU can finish a task then start a new one instantly.
 * 
 * Return the order in which the CPU will process the tasks.

 * Example 1
 * input  : tasks = [[1,2],[2,4],[3,2],[4,1]]
 * output : [0,2,3,1]

 * Example 2
 * input  : tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
 * output : [4,3,2,0,1]
 * 
 * https://leetcode.com/problems/single-threaded-cpu/description/
*/

// ! Google

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

typedef std::pair<int, int> P;

// * ------------------------- Optimal Approach -------------------------
// * Sort the task in ASC order of start time
// * Creating a new sorted tasks array.
std::vector<int> cpuTasks(std::vector<std::vector<int>> &tasks) {
  int n = tasks.size();

  // * Create the sorted task array with each task index
  std::vector<std::vector<int>> sorted_tasks;
  for (int i = 0; i < n; ++i) {
    int start_time = tasks[i][0];
    int processing_time = tasks[i][1];
    sorted_tasks.push_back({start_time, processing_time, i});
  }
  std::sort(begin(sorted_tasks), end(sorted_tasks));
  // * For debugging
  // std::cout << "Tasks: " << std::endl;
  // for (auto &vec : sorted_tasks)
  //   printArr(vec);

  std::vector<int> ans;
  long time = 0, i = 0;
  // * Heap = {processing_time, index}
  std::priority_queue<P, std::vector<P>, std::greater<>> busy; 
  while (i < n || !busy.empty()) {
    // * initial task time start
    if (busy.empty()) {
      time = std::max(time, (long)tasks[i][0]);
    }
    // std::cout << time << std::endl;
    
    // * Here we are push all the task which can be given to cpu
    // * if they have arrived before the time  
    while (i < n && sorted_tasks[i][0] <= time) {
      // std::cout << "push: " << sorted_tasks[i][0] << std::endl;
      busy.push({sorted_tasks[i][1], sorted_tasks[i][2]}); // * {processing_time, index}
      i++;
    }

    // * Get the task with least processing time
    auto [processing_tm, index] = busy.top();
    busy.pop();
    time += processing_tm; // * Add the processing time to `time`
    ans.push_back(index);
  }

  return ans;
}

// * ------------------------- Optimal Approach -------------------------`
// * Sort the task in ASC order of start time
// * Using Input Array itself.
std::vector<int> cpuTasks2(std::vector<std::vector<int>> &tasks) {
  int n = tasks.size();

  // * Create the sorted task array with each task index
  for (int i = 0; i < n; ++i) {
    tasks[i].push_back(i);
  }
  std::sort(begin(tasks), end(tasks));
  // * For debugging
  // std::cout << "Tasks: " << std::endl;
  // for (auto &vec : tasks)
  //   printArr(vec);

  std::vector<int> ans;
  long time = 0, i = 0;
  // * Heap = {processing_time, index}
  std::priority_queue<P, std::vector<P>, std::greater<>> busy; 
  while (i < n || !busy.empty()) {
    // * initial task time start
    if (busy.empty()) {
      time = std::max(time, (long)tasks[i][0]);
    }
    // std::cout << time << std::endl;
    
    // * Here we are push all the task which can be given to cpu
    // * if they have arrived before the time  
    while (i < n && tasks[i][0] <= time) {
      busy.push({tasks[i][1], tasks[i][2]}); // * {processing_time, index}
      i++;
    }

    // * Get the task with least processing time
    auto [processing_tm, index] = busy.top();
    busy.pop();
    time += processing_tm; // * Add the processing time to `time`
    ans.push_back(index);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  
  // * testcase 2
  // std::vector<std::vector<int>> tasks = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};

  std::cout << "Tasks: " << std::endl;
  for (auto &vec : tasks)
    printArr(vec);
  
  std::vector<int> ans = cpuTasks(tasks);
  std::cout << "Process order index: " << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-single-threaded-cpu.cpp -o output && ./output