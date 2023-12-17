// * WAP to insert a element at the end of stack

#include<iostream>
#include<stack>
using namespace std;


void insertAtEnd(stack<int>& a, int val) {
  int cur_top = a.top();
  a.pop();
  // * End of stack
  if(a.empty()) {
    a.push(val);
    return;
  }
  insertAtEnd(a, val);
  a.push(cur_top);
}

int main() {
  stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  insertAtEnd(a, 4);
  return 0;
}
