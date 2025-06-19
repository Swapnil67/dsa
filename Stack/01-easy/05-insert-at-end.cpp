// * WAP to insert a element at the end of stack

#include <stack>
#include <iostream>

using namespace std;

void printStack(std::stack<int> st) {
  while (!st.empty()) {
    std::cout << st.top() << std::endl;
    st.pop();
  }
}

void insertAtEnd(stack<int>& a, int val) {
  // * End of stack
  if (a.empty()) {
    a.push(val);
    return;
  }

  // * pop the top element
  int cur_top = a.top();
  a.pop();

  insertAtEnd(a, val);
  a.push(cur_top);
}

int main() {
  stack<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  insertAtEnd(a, 4);

  printStack(a);

  return 0;
}

// * g++ --std=c++20 05-insert-at-end.cpp -o output && ./output