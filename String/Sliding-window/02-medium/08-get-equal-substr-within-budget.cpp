/**
 * * Get Equal Substrings Within Budget
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

int bruteForce(std::string s, std::string t, int max_cost) {  
  int n1 = s.length(), n2 = t.length();
  int ans = 0;
  for(int i = 0; i < n1; ++i) {
    int cur_cost = 0;
    for(int j = i; j < n2; ++j) {
      int diff = std::abs(t[j] - s[j]);
      if(diff + cur_cost <= max_cost) {
        cur_cost += diff;
        ans = std::max(ans, j - i + 1);
      }
      else {
        break;
      }
    }
  }
  
  return ans;
}

// * Classic Sliding Window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int equalSubstring(std::string s, std::string t, int max_cost) {  
  int n1 = s.length(), n2 = t.length();
  int ans = 0;
  int i = 0, j = 0;
  int cur_cost = 0;
  while(j < n2) {
    cur_cost += std::abs(t[j] - s[j]);

    // * Shrink the window
    if(cur_cost > max_cost) {
      cur_cost -= std::abs(t[i] - s[i]);
      i++;
    }

    if(cur_cost <= max_cost) {
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

  int ans = bruteForce(s, t, max_cost);
  // int ans = equalSubstring(s, t, max_cost);
  std::cout << ans << " Equal Substrings Within Budget" << std::endl;

  return 0;
}

// * Run the code
// * $CXX --std=c++17 08-get-equal-substr-within-budget.cpp -o output && ./output