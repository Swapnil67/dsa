/*
 * Leetcode - 621
 * Task Scheduler
 * 
 * You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
 * Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order,
 * but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
 * 
 * Return the minimum number of CPU intervals required to complete all tasks.
 * 
 * Example 1:
 * Input       : tasks = ["A","A","A","B","B","B"], n = 2
 * Output      : 8
 * Explanation : A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * Example 2:
 * Input       : tasks = ["A","C","A","B","D","B"], n = 1
 * Output      : 6
 * Explanation : A possible sequence is: A -> B -> C -> D -> A -> B.

 * 
 * https://leetcode.com/problems/task-scheduler/
*/
#include <queue>
#include <vector>
#include <iostream>

void printArr(std::vector<char> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << "'" << arr[i] << "' ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using max_heap
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(26)
int leastInterval(std::vector<char>& tasks, int n) {
  // * map task to freq
  std::vector<int> mp(26, 0);
  for (char &t : tasks) {
    mp[t - 'A']++;
  }

  // * Push all the task freq to max_heap
  std::priority_queue<int> max_heap; // * max-size = 26 
  for (int i = 0; i < 26; ++i) { 
    if (mp[i] > 0)
      max_heap.push(mp[i]);
  }

  int intervals = 0;
  while (!max_heap.empty()) {

    std::vector<int> temp; // * current tasks freq

    // * we can only perform upto (n + 1) tasks
    for (int i = 0; i <= n; ++i) {
      if (!max_heap.empty()) {
        int freq = max_heap.top();
        // std::cout << freq << std::endl;
        max_heap.pop();
        freq--;
        temp.push_back(freq);
      }
    }

    // * Push the updated tasks freq again in max_heap
    for (int &f : temp) {
      if (f > 0)
        max_heap.push(f);
    }

    if (max_heap.empty()) { // * Edge case
      intervals += temp.size();
    } else {
      intervals += n + 1; // * (here +1 is for idle time for next task)
    }
  }

  return intervals;
}

int main(void) {
  // int n = 2;
  // std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  
  // int n = 1;
  // std::vector<char> tasks = {'A', 'C', 'A', 'B', 'D', 'B'};
  
  int n = 3;
  std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};

  std::cout << "Tasks: ";
  printArr(tasks);

  int ans = leastInterval(tasks, n);
  std::cout << "Least Intervals: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 03-task-scheduler.cpp -o output && ./output

