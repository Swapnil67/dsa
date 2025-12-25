/*
 * Leetcode - 224
 * Basic Calculator
 * 
 * Given a string s representing a valid expression, implement a basic calculator to evaluate it, 
 * and return the result of the evaluation.
 * 
 * Example: 1
 * Input: s = "1 + 1"
 * Output: 2
 * 
 * Example: 2
 * Input: s = " 2-1 + 2 "
 * Output: 3
 * 
 * Example: 3
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * 
 * https://leetcode.com/problems/basic-calculator/description/
*/

// ! Google, Meta, Airbnb

#include <stack>
#include <iostream>

int calculate(std::string s) {
  int n = s.length();

  std::stack<char> st;

  int sign = 1;
  int num = 0;
  int res = 0;
  for (char &ch : s) {
    if (isdigit(ch)) {
      num = num * 10 + (ch - '0');
    }
    else if (ch == '-' || ch == '+') {
      // * Add the cur num to res with sign
      res += (num * sign);
      num = 0;   // * reset the cur num
      sign = ch == '+' ? 1 : -1;
    }
    else if (ch == '(') {
      st.push(res);  // * Push the cur res on to stack
      st.push(sign); // * Push the sign on to stack
      res = 0;       // * Reset the cur res
      num = 0;       // * Reset the num
      sign = 1;      // * Reset the sign
    }
    else if (ch == ')') {
      // * Add the cur num to res with sign
      res += (num * sign);
      num = 0;

      // * Add the sign to cur res
      int stack_sign = st.top();
      st.pop();
      res *= stack_sign;

      // * Add the prev res to cur res
      int last_result = st.top();
      st.pop();
      res += last_result;
    }
  }

  // * Add num to res
  res += (num * sign);
  return res;
}

int main() {
  // * testcase 1
  // std::string s = " 2-1 + 2 ";

  // * testcase 2
  // std::string s = "(1+(4+5+2)-3)+(6+8)";

  // * testcase 3
  // std::string s = "10 - (4+5+2)-3+(6+8)";

  // * testcase 4
  std::string s = "(1+(4+5+2)-3)+(6+8)";

  std::cout << "Expression: " << s << std::endl;
  
  int ans = calculate(s);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 06-basic-calculator.cpp -o output && ./output
