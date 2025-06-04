/*
 * Leetcode - 921
 * Minimum Add to Make Parentheses Valid
 * 
 * Example 1
 * * Input  : s = "())"
 * * Output : 1
 * 
 * Example 2
 * * Input  : s = "((("
 * * Output : 3
 *
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
*/

#include <stack>
#include <iostream>

// * ------------------------- APPROACH A: Optimal Approach -------------------------`
// * Using Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int minAddToMakeValid(std::string s) {
  std::stack<char> st;
  for(char &ch: s) {
    if(!st.empty() && st.top() == '(' && ch == ')') {
      st.pop();
    }
    else {
      st.push(ch);
    }
  }
  return st.size();
}

// * ------------------------- APPROACH B: Optimal Approach -------------------------`
// * Without Using Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int minAddToMakeValid2(std::string s) {
  int size = 0; // * stack size
  int open = 0; // * open brackets required

  for(char &ch: s) {
    if (ch == '(') {
      size += 1;
    } 
    else {
      if (size > 0)
        size -= 1;
      else
        open += 1;
    }
  }

  return size + open;
}

int main() {
  // * testcase 1
  // std::string s = "())";

  // * testcase 2
  // std::string s = "(((";

  // * testcase 2
  std::string s = "()))((";

  std::cout << s << std::endl;

  int ans = minAddToMakeValid2(s);
  std::cout << "Minimum Add to Make Parentheses Valid: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 16-min-add-to-make-parenthesis-valid.cpp -o output && ./output
