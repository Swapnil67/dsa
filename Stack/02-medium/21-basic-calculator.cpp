#include <stack>
#include <iostream>

int calculate(std::string s) {  
  std::stack<char> st;
  for (char &ch : s) {
    st.push(ch);
  }
  
  int ans = 0;
  while (!st.empty()) {
    char ch = st.top();
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      
    }
  }
}

int main() {
  std::string s = "3+2*2";  
  return 0;
}