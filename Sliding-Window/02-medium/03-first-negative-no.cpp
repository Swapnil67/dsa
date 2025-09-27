/**
 * * First Negative In Every Window
 * * You have been given an array of integers 'ARR' of size 'N'. You are also provided with a positive integer 'K'.
 * * Your task is to find the first negative element in every window (contiguous subarray) of length 'K'. 
 * * If there is no negative element in a window, then print 0 for that window.
 * 
 * * Example 1
 * * Input  : nums = [5, -3, 2, 3, -4] and k = 2
 * * Output : [-3 -3 0 -4]
 * 
 * * Example 2
 * * Input  : nums = [8 1 -2 2 -3 6 8 -1] and k = 3
 * * Output : [-2 -2 -2 -3 -3 -1 ]
 * 
 * * https://www.naukri.com/code360/problems/first-negative-in-every-window_759333
*/

#include <deque>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all k size windows
// * TIME COMPLEXITY O(N * 3)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  std::vector<int> ans;
  for (int i = 0; i <= n - k; ++i) {
    int neg_num = 0;
    for(int j = i; j < i + k; ++j)  {
      if(arr[j] < 0) {
        neg_num = arr[j];
        break;
      }
    }
    ans.push_back(neg_num);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Save the -ve numbers to deque
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> firstNegative(std::vector<int> arr, int k) {
  int n = arr.size();
  std::deque<int> dq;
  std::vector<int> ans;
  int i = 0, j = 0;

  while (j < n) {
    // * If -ve then push to dequeue
    if (arr[j] < 0)
      dq.push_back(arr[j]);

    // * Shrink the window & Pop from queue
    if (j - i + 1 > k) {
      if (arr[i] < 0 && !dq.empty())
        dq.pop_front();
      i++;
    }

    // * first -ve in 'k' window
    if (j - i + 1 == k) {
      if (!dq.empty()) {
        ans.push_back(dq.front());
      } else {
        ans.push_back(0);
      }
    }

    j++;
  }
  return ans;
}

int main() {
  // * testcase 1
  int window_size = 2;
  std::vector<int> arr = {5, -3, 2, 3, -4};

  // * testcase 2
  // int window_size = 3;
  // std::vector<int> arr = {8, 1, -2, 2, -3, 6, 8, -1};
  
  printArr(arr);
  
  // std::vector<int> ans = bruteForce(arr, window_size);
  std::vector<int> ans = firstNegative(arr, window_size);
  std::cout << "First Negative In Every Window" << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++17 03-first-negative-no.cpp -o output && ./output
