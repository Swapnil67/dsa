#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checkClosingMatch(char t, char ch) {
  if((t == '(' && ch == ')') || (t == '{' && ch == '}') || (t == '[' && ch == ']')) {
    return true;
  } else {
    return false;
  }
}

bool isValidParenthesis(string txt) {
  stack<char> carr;

  for(int i=0; i<txt.length(); i++) {
    char ch = txt[i];
    // * If opening bracket push in stack
    // * If closing bracket check stack top & pop
    if(ch == '(' || ch == '[' || ch == '{') {
      // cout<<"push "<<ch<<endl;
      carr.push(ch);
    } else {
      if(!carr.empty()) {
        char top = carr.top();
        if(checkClosingMatch(top, ch)) {
          carr.pop();
        } else {
          return false;
        }
      }
    }
  }

  if(carr.empty()) return true;
  else return false;
}

int main() {
  cout<<"Valid Parenthesis: "<<isValidParenthesis("[{}{}()]")<<endl;
  cout<<"Valid Parenthesis: "<<isValidParenthesis("[{([])}]")<<endl;
  cout<<"Valid Parenthesis: "<<isValidParenthesis("[{]]")<<endl;
  return 0;
}

// * [ { } { } ( ) ] -> Valid Parenthesis
// * [ { ( [ ] ) } ] -> Valid Parenthesis
// * [ { ) ] -> Invalid Valid Parenthesis
