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

char solve(std::vector<char> &arr, char operation) {
  if (operation == '!') {
    return arr[0] == 't' ? 'f' : 't';
  }

  bool ans = false;
  if (operation == '&')
    ans = true;
  for(int i = 0; i < arr.size(); ++i) {
    bool cur = true;
    if (arr[i] == 'f')
      cur = false;

    if(operation == '|') {
      if (cur)
        return true;
      ans = ans | cur;
    } 
    else if(operation == '&') {
      ans = ans & cur;
    }
  }

  return ans == 0 ? 'f' : 't';
}


// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * Using Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
bool parseBoolExpr(std::string expression) {
  std::stack<char> st;
  for(char &ch: expression) {
    if (ch == ',')
      continue;

    if (ch == ')') {
      std::vector<char> vec;
      while (!st.empty() && st.top() != '(') {
        vec.push_back(st.top());
        st.pop();
      }

      // * pop the opening bracket
      st.pop();

      // * Get the last operation
      char operation = st.top(); // * !, |, &
      // * pop the last operation

      st.pop();

      st.push(solve(vec, operation));
    } else {
      st.push(ch);
    }
  }

  return st.top() == 'f' ? false : true;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using Stack (More Simple)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
bool parseBoolExpr2(std::string expression) {
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
      else if(operation == '|') {
        if (t) st.push('t');
        else st.push('f');
      }
      else if(operation == '&') {
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
  // std::string expression = "!(f)";
  // std::string expression = "&(|(f))";
  // std::string expression = "|(f,f,f,t)";
  std::string expression = "!(&(f,t))";

  std::cout << "Expression: " << expression << std::endl;

  // bool ans = parseBoolExpr(expression);
  bool ans = parseBoolExpr2(expression);
  std::cout << ans << std::endl;
}

// * run the code
// * g++ --std=c++17 08-parse-bool-expr.cpp -o output && ./output
