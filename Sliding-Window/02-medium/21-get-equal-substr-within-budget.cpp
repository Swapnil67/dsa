/**
 * * Leetcode - 1208
 * * Get Equal Substrings Within Budget
 * 
 * * Example 1
 * * Input  : s = "abcd", t = "bcdf", maxCost = 3
 * * Output : 3
 * * Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.

 * * Example 2
 * * Input  : s = "abcd", t = "cdef", maxCost = 3
 * * Output : 1
 * * Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
 * 
 * * Example 3
 * * Input  : s = "abcd", t = "acde", maxCost = 0
 * * Output : 1
 * * Explanation: You cannot make any change, so the maximum length is 1.
 * 
 * * https://leetcode.com/problems/get-equal-substrings-within-budget/description/
*/

#include <iostream>

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible substrings
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(26)
int bruteForce(std::string s, std::string t, int max_cost) {  
  int n = s.size();
  int ans = 0;
  for(int i = 0; i <n; ++i) {
    int cur_cost = 0, j = i;
    for (; j < n; ++j) {
      int diff = std::abs(s[j] - t[j]);
      if (cur_cost + diff <= max_cost) {
        cur_cost += diff;
      } else {
        break;
      }
    }
    ans = std::max(ans, j - i);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int equalSubstring(std::string s, std::string t, int max_cost) {  
  int n = s.length();
  int i = 0, j = 0;
  int ans = 0, cur_cost = 0;

  while(j < n) {
    // * Add the abs difference to current cost
    cur_cost += std::abs(t[j] - s[j]);

    // * Shrink the window from left
    if (cur_cost > max_cost) {
      cur_cost -= std::abs(t[i] - s[i]);
      i++;
    } else {
      // * calculate new max substring
      ans = std::max(ans, j - i + 1);
    }
    j++;
  }
  
  return ans;
}

int main() {

  // * testcase 1
  int max_cost = 3;
  std::string s = "abcd", t = "bcdf";

  // * testcase 2
  // int max_cost = 3;
  // std::string s = "abcd", t = "cdef";

  // * testcase 3
  // int max_cost = 0;
  // std::string s = "abcd", t = "acde";

  std::cout << "s: " << s << std::endl;
  std::cout << "t: " << t << std::endl;

  // int ans = bruteForce(s, t, max_cost);
  int ans = equalSubstring(s, t, max_cost);
  std::cout << ans << " Equal Substrings Within Budget" << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 21-get-equal-substr-within-budget.cpp -o output && ./output