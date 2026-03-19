/*
 * Leetcode - 
 * Kill Process
 * 
 * You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid, 
 * where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.
 * 
 * Each process has only one parent process but may have multiple children processes. Only one process has ppid[i] = 0, 
 * which means this process has no parent process (the root of the tree).
 * 
 * When a process is killed, all of its children processes will also be killed.
 * 
 * Given an integer kill representing the ID of a process you want to kill, return a list of the IDs 
 * of the processes that will be killed. You may return the answer in any order.
 * 
 * 
 * Example 1    :
 * Input        : pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5
 * Output       : [5, 10]
 * 
 * Example 2    :
 * Input        : pid = [1], ppid = [0], kill = 1
 * Output       : [1]
 * 
 * https://neetcode.io/problems/kill-process/question
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


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

void dfs(int u, vector<int> &ans, unordered_map<int, vector<int>> &adj) {
  ans.push_back(u);
  for (auto &v : adj[u]) {
    dfs(v, ans, adj);
  }
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
  // * Create an Adj out of given vectors
  unordered_map<int, vector<int>> adj;
  int n = pid.size();
  for (int i = 0; i < n; ++i) {
    int child = pid[i], parent = ppid[i];
    adj[parent].push_back(child);
  }

  // * Do dfs from kill node
  vector<int> ans;
  dfs(kill, ans, adj);
  return ans;
}

int main(void) {
  // * testcase 1
  int kill = 5;
  std::vector<int> pid = {1, 3, 10, 5}, ppid = {3, 0, 5, 3};
  
  // * testcase 2
  // int kill = 1;
  // std::vector<int> pid = {1}, ppid = {0};

  std::cout << "pid: ";
  printArr(pid);
  std::cout << "ppid: ";
  printArr(ppid);

  std::vector<int> ans = killProcess(pid, ppid, kill);
  std::cout << "Killed Processes: ";
  printArr(ans);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 63-kill-process.cpp -o output && ./output
