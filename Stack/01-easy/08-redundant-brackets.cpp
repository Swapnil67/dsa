// * Check if redundant bracket

#include <stack>
#include <string>
#include <iostream>

bool checkRedundantBrackets(std::string &s) {
  std::stack<char> st;
  for(char &ch : s) {
    if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
      st.push(ch);
    } else {
      if(ch == ')') {
        bool isRedundant = true;
        if (st.empty()) {
          return isRedundant;
        }
        while (st.top() != '(') {
          char top = st.top();
          if (top == '+' || top == '-' || top == '*' || top == '/' || top == '%') {
            isRedundant = false;
          }
          st.pop();
        }

        if (isRedundant == true) 
          return true;
        
        st.pop();
      }
    }
  }
  return false;
}

int main() {
  // * Redundant = "((a+b))"
  // * Not Redundant = "(c+(a+b))"

  std::string st = "(a+b)";
  // std::string st = "((a+b))";
  bool isRedundantBracket = checkRedundantBrackets(st);
  std::cout << "isRedundantBracket: " << isRedundantBracket << std::endl;
  return 0;
}


// * g++ --std=c++20 08-redundant-brackets.cpp -o output && ./output