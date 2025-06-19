/**
 * * Leetcode - 3174
 * * Clear Digits
 * * Your task is to remove all digits by doing this operation repeatedly:
 * * Delete the first digit and the closest non-digit character to its left.

 * * Example 1
 * * Input  : s = "abc"
 * * Output : "abc"
 * 
 * * Example 2
 * * Input  : s = "cb34"
 * * Output : ""
 * 
 * * https://leetcode.com/problems/clear-digits/description/
*/

#include <stack>
#include <string>
#include <iostream>
#include <algorithm>

// * ------------------------- APPROACH 1: Better Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::string clearDigits(std::string s) {
  int n = s.size();
  std::stack<char> st;
  for (char &ch : s) {
    if (ch >= '0' && ch <= '9') {
      if (!st.empty() && isalpha(st.top())) {
        st.pop();
      }
    } else {
      st.push(ch);
    }
  }

  std::string ans = "";
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }


  std::reverse(ans.begin(), ans.end());
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::string clearDigits2(std::string s) {
  int n = s.size();
  std::string ans = "";
  for (char &ch : s) {
    if (ch >= '0' && ch <= '9') {
      if (ans.size() && isalpha(ans.back())) {
        ans.pop_back();
      }
    } else {
      ans += ch;
    }
  }
  return ans;
}

int main() {
  // * testcase 1
  // std::string s = "abc";

  // * testcase 2
  std::string s = "cb34";

  std::string ans = clearDigits(s);
  std::cout << "Clear Digits: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 12-clear-digits.cpp -o output && ./output