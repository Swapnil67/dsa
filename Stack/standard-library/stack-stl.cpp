#include<iostream>
#include<stack>
using namespace std;

int main() {

  // * Creation of stack
  stack<int> s;

  // * Push operation
  s.push(10);
  s.push(20);

  // * Pop operation
  s.pop();

  cout<<"Printing top element: "<<s.top()<<endl;

  // * Check stack is empty or not
  if(s.empty()) {
    cout<<"Stack is empty"<<endl;
  } else {
    cout<<"Stack is not empty"<<endl;
  }

  return 0;
}