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
  for (char &ch : s) {
    if (ch == ']' || ch == '}' || ch == ')') {
      char op = getOpeningBracket(ch);
      if(!st.empty() && st.top() != op) {
        return false;
      }
      st.pop();
    }
    else {
      st.push(ch);
    }
  }
  // std::cout << st.size() << std::endl;
  return st.empty();
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
// * g++ --std=c++20 04-valid-parenthesis.cpp -o output && ./output