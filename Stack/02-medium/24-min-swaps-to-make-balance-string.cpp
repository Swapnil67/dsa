/*
 * Leetcode - 1963
 * Minimum Swaps To Make Balance String
 * 
 * You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '['
 * and n / 2 closing brackets ']'.
 * 
 * Example 1:
 * Input : s = "][]["
 * Output: 1
 * Explanation :  You can make the string balanced by swapping index 0 with index 3.
 *                The resulting string is "[[]]".
 * 
 * Example 2:
 * Input : s = "]]][[["
 * Output: 2
 * Explanation : You can do the following to make the string balanced:
 *              - Swap index 0 with index 4. s = "[]][][".
 *              - Swap index 1 with index 5. s = "[[][]]".
 *              The resulting string is "[[][]]".

 * https://www.naukri.com/code360/problems/minimum-number-of-swaps-for-bracket-balancing_1115682
 * https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/
*/

// ! Google, Amazon, Facebook

#include <stack>
#include <iostream>

// ! Intuition
// * Keep the count of closing brackets
// * Note each swap cancel's out 2 closing bracket
// * i.e. if there are 3 closing bracket and 1 swap is made then the remaining will be 1 bracket
// * therefore we divide maxClosing brackets by 2

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minSwaps(std::string s) {
  std::stack<char> st;
  for (auto &c : s) {
    if (c == ']') {
      if (!st.empty())
        st.pop();
    }
    else {
      st.push(c);
    }
  }
  if (st.empty())
    return 0;
  return (st.size() + 1) / 2;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minSwaps(std::string s) {
  int closingBrakets = 0, maxClosing = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == ']') {
      closingBrakets += 1;
    }
    else {
      closingBrakets -= 1;
    }
    maxClosing = std::max(maxClosing, closingBrakets);
  }
  // std::cout << maxClosing << std::endl;
  return (maxClosing + 1) / 2;
}

int main() {
  // * testcase 1
  // std::string s = "][][";

  // * testcase 2
  // std::string s = "]]][[[";

  // * testcase 3
  std::string s = "]][]][[[][";

  std::cout << "Input string: " << s << std::endl;
  int ans = minSwaps(s);
  std::cout << "Minimum swaps required to make balanced string is " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 24-min-swaps-to-make-balance-string.cpp -o output && ./output