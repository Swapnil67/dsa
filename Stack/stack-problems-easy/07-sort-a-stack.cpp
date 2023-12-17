#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s, int val) {
  // * End of stack
  if(s.empty() || (!s.empty() && s.top() < val)) {
    s.push(val);
    return;
  }

  int cur_top = s.top();
  s.pop();

  // * Recursive Call
  sortedInsert(s, val);
  s.push(cur_top);
}

// * Time complexity O(n)
void printStack(stack<int> &s) {
  // stack<int> p;
  // p.push(1);
  // p.push(2);
  // p.push(3);
  stack<int> p = s;
  while(!p.empty()) {
    cout<<p.top()<<" ";
    p.pop();
  }
}

void sortStack(stack<int> &s) {

  if(s.empty()) {
    cout<<"\nStack is empty"<<endl;
    return;
  }

  int num = s.top();
  s.pop();
 
  // * Recursive Call
  sortStack(s);

  // * Insert at bottom
  sortedInsert(s, num);
}

int main() {
  stack<int> a;
  a.push(1);
  a.push(-2);
  a.push(3);
  a.push(-5);
  a.push(0);

  printStack(a);
  cout<<"\n-------------------------------------"<<endl;
  sortStack(a);
  cout<<"\n-------------------------------------"<<endl;
  printStack(a);
  return 0;
}