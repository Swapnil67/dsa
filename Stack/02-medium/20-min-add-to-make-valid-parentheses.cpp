/*
 * Leetcode - 921
 * Minimum Add to Make Parentheses Valid
 * 
 * Return the minimum number of moves required to make s valid.
 * 
 * Example 1
 * * Input       : s = "())"
 * * Output      : 1
 * 
 * Example 2
 * * Input       : s = "((("
 * * Output      : 3
 * 
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
*/

#include <stack>
#include <iostream>

// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minAddToMakeValid(std::string s) {
  std::stack<int> st;
  for (char &ch : s) {
    if(ch == ')') {
      if (!st.empty() && st.top() == '(') {
        st.pop();
      } else {
        st.push(ch);
      }
    } else {
      st.push(ch);
    }
  }

  return st.size();
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minAddToMakeValid2(std::string s) {
  int balance = 0;
  for (int i = 0; i < s.size(); ++i) {
    char ch = s[i];
    if(ch == ')') {
      if (i > 0 && s[i - 1] == '(') {
        balance--;
      } else {
        balance++;
      }
    } else {
      balance++;
    }
  }

  return balance;
}

int main() {
  // * testcase 1
  std::string s = "())";

  // * testcase 2
  // std::string s = "(((";

  std::cout << s << std::endl;

  // int ans = minAddToMakeValid(s);
  int ans = minAddToMakeValid2(s);
  std::cout << "Min no of moves required: " << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 20-min-add-to-make-valid-parentheses.cpp -o output && ./output