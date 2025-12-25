/*
 * Leetcode - 1106
 * Parsing A Boolean Expression

 * Example 1
 * * Input       : expression = "&(|(f))"
 * * Output      : false
 * 
 * Example 2
 * * Input       : expression = "|(f,f,f,t)"
 * * Output      : true
 * 
 * Example 3
 * * Input       : expression = "!(&(f,t))"
 * * Output      : true
 * 
 * https://leetcode.com/problems/parsing-a-boolean-expression/description/
*/

#include<stack>
#include<vector>
#include<iostream>


// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using Stack (More Simple)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
bool parseBoolExpr(std::string expression) {
  std::stack<char> st;
  for(char &ch: expression) {
    if (ch == ',')
      continue;

    if (ch == ')') {
      bool t = false, f = false;
      while (!st.empty() && st.top() != '(') {
        if (st.top() == 't')
          t = true;
        else
          f = true;
        st.pop();
      }

      // * pop the opening bracket '('
      st.pop();

      // * Get the last operation
      char operation = st.top(); // * !, |, &
      st.pop();                  // * pop the last operation

      if (operation == '!') {
        if (t) st.push('f');
        else st.push('t');
      }
      else if (operation == '|') {
        if (t) st.push('t');
        else st.push('f');
      }
      else if (operation == '&') {
        if (f) st.push('f');
        else st.push('t');
      }
    }
    else {
      st.push(ch);
    }
  }

  return st.top() == 'f' ? false : true;
}

int main(void) {
  // * testcase 1
  // std::string expression = "!(f)";

  // * testcase 2
  // std::string expression = "&(|(f))";

  // * testcase 3
  // std::string expression = "|(f,f,f,t)";

  // * testcase 4
  std::string expression = "!(&(f,t))";

  std::cout << "Expression: " << expression << std::endl;

  bool ans = parseBoolExpr(expression);
  std::cout << ans << std::endl;
}

// * run the code
// * g++ --std=c++17 08-parse-bool-expr.cpp -o output && ./output
