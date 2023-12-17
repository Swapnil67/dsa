// * WAP to reverse a stack using recursion

#include<iostream>
#include<stack>
using namespace std;

void insertAtEnd(stack<int> &s, int val) {
  // * End of stack
  if(s.empty()) {
    s.push(val);
    return;
  }
  int cur_top = s.top();
  s.pop();
  
  // * Recursive Call
  insertAtEnd(s, val);
  s.push(cur_top);
}

void reverseStack(stack<int> &s) {
  // * End of stack
  if(s.empty()) {
    return;
  }
  int cur_top = s.top();
  s.pop();

  // * Recursive Call
  reverseStack(s);

  insertAtEnd(s, cur_top);
}

int main() {
  stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  reverseStack(a);
  return 0;
}