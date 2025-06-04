/*
 * Leetcode - 402
 * Remove K Digits
 * Given string num representing a non-negative integer num, and an integer k, return the smallest possible 
 * integer after removing k digits from num.
 * 
 * * Example 1
 * * Input  : num = "1432219", k = 3
 * * Output : "1219"
 * 
 * * Example 2
 * * Input  : num = "10200", k = 1
 * * Output : "200"

 * * Example 2
 * * Input  : num = "10", k = 2
 * * Output : 0

* https://leetcode.com/problems/remove-k-digits/description/
*/

#include <iostream>
#include <climits>
#include <stack>

// ! Monotonic Stack

std::string bruteForce(std::string str, int k) {
  int n = str.size();
  int min_num = INT_MAX;
  std::string ans = "";

  if (n == k)
    return "0";

  for (int i = 0; i < n; ++i) {
    std::string temp = "";
    for (int j = 0; j < n; ++j) {
      if (j == i && j + k < n)
        j += k;
      temp += str[j];
    }
    if(std::stoi(temp) < min_num) {
      min_num = std::stoi(temp);
      ans = std::to_string(min_num);
    }
    // std::cout << temp << std::endl;
  }
  return ans;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * TIME COMPLEXITY O(2N) ~ O(N)
// * SPACE COMPLEXITY O(1)

// * Use the following logic
// * one's ten's hundred's thousand's place
std::string removeKdigits(std::string str, int k) {
  int n = str.size();
  std::string ans = "";

  if (n == k)
      return "0";

  // * Monotonic Stack
  for (int i = 0; i < n; ++i) {

    // * If top of stack is greater than current value
    while(ans.length() && ans.back() > str[i] && k > 0) {
      ans.pop_back();
      k--;
    }

    // * To avoid the case when we have preceding zeros
    if (ans.length() > 0 || str[i] != '0')
      ans.push_back(str[i]);
  }

  // std::cout << ans << " " << k << std::endl;

  // * When the num string is already sorted
  while (k > 0 && ans.length()) {
    ans.pop_back();
    k--;
  }

  // std::cout << ans << std::endl;

  return ans.length() == 0 ? "0" : ans;
}

int main() {
  int k = 3;
  std::string num = "1432219";

  // int k = 1;
  // std::string num = "112";

  // int k = 1;
  // std::string num = "10200";

  // int k = 9;
  // std::string num = "1234567890";

  std::cout << num << std::endl;

  // std::string ans = bruteForce(num, k);
  std::string ans = removeKdigits(num, k);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-remove-k-digits.cpp -o output && ./output