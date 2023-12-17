#include<stack>
#include<string>
#include<iostream>
using namespace std;

bool redundantBrackets(string &s) {
  stack<char> st;
  for(int i=0; i<s.length(); i++) {
    char ch = s[i];
    // cout<<ch<<" ";
    if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
      st.push(ch);
    } else {
      if(ch == ')') {
        bool isRedundant = true;
        if(st.empty()) {
          return isRedundant;
        }
        while(st.top() != '(') {
          char top = st.top();
          if(top == '+' || top == '-' || top == '*' || top == '/' || top == '%') {
            isRedundant = false;
          }
          st.pop();
        }
        if(isRedundant == true) 
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

  string st = "(a+b))";
  bool isRedundantBracket = redundantBrackets(st);
  cout<<"\nisRedundantBracket: "<<isRedundantBracket;
  return 0;
}