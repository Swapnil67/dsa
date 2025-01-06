#include<iostream>
#include<stack>

char getOpeningBracket(char ch) {
  if(ch == ')')
    return '(';
  else if(ch == ']')
    return '[';
  else if(ch == '}')
    return '{';
  else 
    return '0';
}

bool isValidParenthesis(std::string s) {
    std::stack<char> st;
  int n = s.size();
  for(int i = 0; i < n; ++i) {
    if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
    }
    else {
      char opening_bracket = getOpeningBracket(s[i]);
      if(st.empty() || st.top() != opening_bracket)
        return false;
      st.pop();
    }
  }
  // std::cout << st.size() << std::endl;
  return !st.size() ? true : false;
}

int main() {
  std::cout << "Valid Parenthesis: " << isValidParenthesis("[{}{}()]") << std::endl;
  std::cout << "Valid Parenthesis: " << isValidParenthesis("[{([])}]") << std::endl;
  std::cout << "Valid Parenthesis: " << isValidParenthesis("[{]]") << std::endl;
  return 0;
}

// * [ { } { } ( ) ] -> Valid Parenthesis
// * [ { ( [ ] ) } ] -> Valid Parenthesis
// * [ { ) ] -> Invalid Valid Parenthesis

// * Run the code
// * $CXX --std=c++20 04-valid-parenthesis.cpp -o output && ./output