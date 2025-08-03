/*
 * Leetcode - 224
 * Basic Calculator
 * Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
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

#include <stack>
#include <iostream>

int calculate(std::string s) {
  int n = s.length();

  std::stack<char> st;

  int sign = 1;
  int number = 0;
  int result = 0;
  for (char &ch : s) {
    if (isdigit(ch)) {
      number = number * 10 + (ch - '0');
    }
    else if (ch == '-' || ch == '+') {
      // * Add the cur number to result with sign
      result += (number * sign);
      number = 0;   // * reset the cur number
      sign = ch == '+' ? 1 : -1;
    }
    else if (ch == '(') {
      st.push(result);    // * Push the result on to stack
      st.push(sign);      // * Push the sign on to stack
      result = 0;         // * Reset the result
      number = 0;         // * Reset the number
      sign = 1;           // * Reset the sign
    }
    else if (ch == ')') {
      // * Add the cur number to result with sign
      result += (number * sign);
      number = 0;

      // * Add the sign to cur result
      int stack_sign = st.top();
      st.pop();
      result *= stack_sign;

      // * Add the prev result to cur result
      int last_result = st.top();
      st.pop();
      result += last_result;
    }
  }

  // * Add number to result
  result += (number * sign);
  return result;
}

int main() {
  std::string s = " 2-1 + 2 ";
  // std::string s = "(1+(4+5+2)-3)+(6+8)";
  std::cout << "Expression: " << s << std::endl;
  
  int ans = calculate(s);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 06-basic-calculator.cpp -o output && ./output
