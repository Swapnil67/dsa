/*
 * Leetcode - 739
 * Daily Temperatures
 * Given an array of integers temperatures represents the daily temperatures, return an array answer 
 * such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
 * If there is no future day for which this is possible, keep answer[i] == 0 instead.
 * * Example 1
 * * Input  : temperatures = [73,74,75,71,69,72,76,73]
 * * Output : [1,1,4,2,1,1,0,0]
 * 
 * * Example 2
 * * Input  : temperatures = [30,40,50,60]
 * * Output : [1,1,1,0]
 * 
 * https://leetcode.com/problems/daily-temperatures/description/
*/

// ! Monotonic Stack

#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> temperatures) {
  int n = temperatures.size();
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
    int warmer_temperature = temperatures[i];
    int days = 0;
    for (int j = i + 1; j < n; ++j) {
      days++;
      if (temperatures[j] > warmer_temperature) {
        warmer_temperature = temperatures[j];
        break;
      }
    }
    // * we did not get the warmer temperature than current
    if (warmer_temperature == temperatures[i])
      days = 0;
    ans.push_back(days);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Monotonic Stack
// * TIME COMPLEXITY O(2N) ~ O(N) 
// * SPACE COMPLEXITY O(N)
std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
  int n = temperatures.size();
  std::vector<int> ans(n);
  std::stack<int> st;    // * Monotonic stack
  
  for (int i = 0; i < temperatures.size(); ++i) {
     // * st.top() should only contain element greater than temperatures[i] 
    while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
      // * next greater element
      ans[st.top()] = i - st.top();
      st.pop(); 
    }

    st.push(i);
  }

  return ans;
}

int main() {
  // * testcase 1
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

  // * testcase 2
  // std::vector<int> temperatures = {30, 40, 50, 60};

  // * testcase 3
  // std::vector<int> temperatures = {30, 60, 90};

  printArr(temperatures);

  // std::vector<int> ans = bruteForce(temperatures);
  std::vector<int> ans = dailyTemperatures(temperatures);
  printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 07-daily-temperatures.cpp -o output && ./output