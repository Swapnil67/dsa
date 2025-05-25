/*
  * Leetcode - 150
  * Evaluate Reverse Polish Notation
  * You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
  * The valid operators are '+', '-', '*', and '/'.
  * Each operand may be an integer or another expression.
  * The division between two integers always truncates toward zero.
  * There will not be any division by zero.
  * The input represents a valid arithmetic expression in a reverse polish notation.
  * The answer and all the intermediate calculations can be represented in a 32-bit integer.
  * 
  * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<std::string> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

#define BINARY_OP(st, op)             \
  {                                   \
    if (!st.empty())                  \
    {                                 \
      int num1 = st.top();            \
      st.pop();                       \
      int num2 = st.top();            \
      st.pop();                       \
      int ans = num2 op num1;         \
      st.push(ans);                   \
    }                                 \
  }

int evalRPN(std::vector<std::string> &tokens) {
  int n = tokens.size();
  std::stack<int> st;
  for(std::string &s: tokens) {
    if(s == "+") { BINARY_OP(st, +) }
    else if(s == "-") { BINARY_OP(st, -) }
    else if(s == "*") { BINARY_OP(st, *) }
    else if(s == "/") { BINARY_OP(st, /) }
    else { st.push(std::stoi(s)); }
  }
  return st.empty() ? 0 : st.top();
}

int main() {
  // std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
  // std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
  std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  printArr(tokens);
  int ans = evalRPN(tokens);
  std::cout << ans << std::endl;

  return 0;
}

// * Run the code
// * $CXX 01-evaluate-rpn.cpp -o output && ./output