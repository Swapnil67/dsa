/*
 * Leetcode - 772
 * Basic Calculator III
 * 
 * Given a string s representing a valid expression, implement a basic calculator to evaluate it, 
 * and return the result of the evaluation.
 * 
 * Example: 1
 * Input: s = "1 + 1"
 * Output: 2
 * 
 * Example: 2
 * Input: s = "6-4/2"
 * Output: 4
 * 
 * Example: 3
 * Input: s = "2*(5+5*2)/3+(6/2+8)"
 * Output: 21
 * 
 * https://leetcode.com/problems/basic-calculator/description/
*/

// ! Google, Meta, Amazon, Microsoft, Snapchat, TikTok

#include <stack>
#include <vector>
#include <iostream>

int helper(int x, int y, char op) {
  if (op =='+') {
    return x;
  } else if (op =='-') {
    return -x;
  } else if (op =='*') {
    return x * y;
  }
  return x / y;
}

// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * Using vector as Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int calculate(std::string s) {
  s += '@';
  std::vector<std::pair<int, bool>> st;
  int num = 0;
  char prev_op = '+';
  for (auto &c: s) {
    if (isdigit(c)) {
      num = (num * 10) + c - '0';
    }
    else if (c == '(') {
      // * Push the prev_op onto the stack
      st.push_back({prev_op, false});
      prev_op = '+';
    }
    else {
      if (prev_op == '*' || prev_op == '/') {
        int top = st.back().first;
        st.pop_back();
        st.push_back({helper(top, num, prev_op), true});
      } else {
        st.push_back({helper(num, 0, prev_op), true});
      }

      num = 0;
      prev_op = c;

      if (c == ')') {
        while (!st.empty() && st.back().second) {
          num += st.back().first;
          st.pop_back();
        }
        prev_op = st.back().first;
        st.pop_back();
      }
    }
  }

  int ans = 0;
  for (auto &p: st) {
    ans += p.first;
  }
  return ans;
}

int main() {
  // * testcase 1
  // std::string s = "1+1";

  // * testcase 2
  std::string s = "6-4/2";

  // * testcase 3
  // std::string s = "2*(5+5*2)/3+(6/2+8)";

  std::cout << "Expression: " << s << std::endl;
  
  int ans = calculate(s);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++20 10-basic-calculator-iii.cpp -o output && ./output
