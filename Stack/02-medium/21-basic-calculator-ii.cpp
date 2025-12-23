/*
 * Leetcode - 227
 * Basic Calculator II
 * 
 * Given a string s which represents an expression, evaluate this expression and return its value. 

 * Example 1
 * * Input       : s = "3 + 2 * 2"
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
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int calculate(std::string s) {  
  int n = s.size();
  long num = 0;
  std::stack<int> st;
  
  char sign = '+';
  for (int i = 0; i <= n; ++i) {
    char ch = s[i];

    // * form a num
    if (isdigit(ch)) {
      num = num * 10 + (ch - '0');
    }
    
    // * do operation
    if(!isdigit(ch) && !isspace(ch)) {
      // std::cout << "num: " << num << std::endl;
      if(sign == '+') {
        st.push(num);
      } 
      else if(sign == '-') {
        st.push(num * -1);
      }
      else if(sign == '*') {
        int operand = st.top();
        st.pop();
        st.push(operand * num);
      }
      else if(sign == '/') {
        int operand = st.top();
        st.pop();
        st.push(operand / num);
      }
      
      sign = ch;         // * this is the key to this sum
      num = 0;
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

// * ------------------------- APPROACH : Optimal Approach -------------------------`
// * Using Only Helper Variables
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int calculate2(std::string s) {  
  int n = s.size();
  char prev_op = '+';
  int sum = 0;
  int prev_num = 0, num = 0;
  std::stack<int> st;

  for (int i = 0; i < n; ++i) {
    char ch = s[i];

    // * form a number
    if (std::isdigit(ch)) {
      num = num * 10 + (ch - '0');
    }
    
    // * do operation
    if (!isdigit(ch) && !isspace(ch) || i == n - 1) {
      // std::cout << "number: " << number << std::endl;
      if (prev_op == '+') {
        sum += prev_num;
        prev_num = num;
      }
      else if(prev_op == '-') {
        sum += prev_num;
        prev_num = (num * -1);
      }
      else if(prev_op == '*') {
        prev_num = (prev_num * num);
      }
      else if(prev_op == '/') {
        prev_num = (prev_num / num);
      }
      
      prev_op = ch;         // * this is the key to this sum
      num = 0;
    }
  }

  sum += prev_num;

  return sum;
}

int main() {
  // * testcase 1 (Ans: 7)
  // std::string s = "3+2*2";
  
  // * testcase 2 (Ans: 1)
  // std::string s = " 3/2 ";
  
  // * testcase 3 (Ans: 5)
  // std::string s = " 3+5 / 2 ";
  
  // * testcase 4 (Ans: 1)
  std::string s = "1";

  std::cout << "Expression: " << s << std::endl;

  // int ans = calculate(s);
  int ans = calculate2(s);
  std::cout << "Answer " << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++20 21-basic-calculator-ii.cpp -o output && ./output
