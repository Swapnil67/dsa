/*
 * Leetcode - 227
 * Basic Calculator II
 * Given a string s which represents an expression, evaluate this expression and return its value. 

 * Example 1
 * * Input       : s = "3+2*2"
 * * Output      : 7
 * 
 * Example 2
 * * Input       : s = " 3/2 "
 * * Output      : 1
 * 
 * Example 3
 * * Input       : s = " 3+5 / 2 "
 * * Output      : 5
 * 
 * https://leetcode.com/problems/basic-calculator-ii/description/
*/

#include <stack>
#include <iostream>

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * Using Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int calculate(std::string s) {  
  int n = s.size();
  char sign = '+';
  int number = 0;
  int result = 0;
  std::stack<int> st;

  for (int i = 0; i <= n; ++i) {
    char ch = s[i];

    // * form a number
    if (i < n && isdigit(ch)) {
      number = number * 10 + (ch - '0');
    }
    
    // * do operation
    if(!isdigit(ch) && !isspace(ch)) {
      // std::cout << "number: " << number << std::endl;
      if(sign == '+') {
        st.push(number);
      } 
      else if(sign == '-') {
        st.push(number * -1);
      }
      else if(sign == '*') {
        int operand = st.top();
        st.pop();
        st.push(operand * number);
      }
      else if(sign == '/') {
        int operand = st.top();
        st.pop();
        st.push(operand / number);
      }
      
      sign = ch;         // * this is the key to this sum
      number = 0;
    }
  }

  // * Build answer
  int sum = 0;
  while(!st.empty()) {
    sum += st.top();
    st.pop();
  }

  return sum;
}

// * 5 + 2
int main() {
  std::string s = "3+2*2";
  // std::string s = " 3/2 ";
  // std::string s = " 3+5 / 2 ";

  std::cout << "Expression: " << s << std::endl;

  int ans = calculate(s);
  std::cout << "Answer " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 21-basic-calculator-ii.cpp -o output && ./output
