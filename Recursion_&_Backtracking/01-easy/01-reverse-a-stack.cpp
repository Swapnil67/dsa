/**
 * * Reverse Stack Using Recursion
 * 
 * * https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875
 */

#include <stack>
#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

template <typename T>
void printStack(std::stack<T> st) {
  while (!st.empty()) {
    std::cout << st.top() << std::endl;
    st.pop();
  }
}

void insertAtEnd(std::stack<int> &st, int val) {
  if (st.empty()) {
    st.push(val);
    return;
  }
  
  int top_val = st.top();
  st.pop();

  insertAtEnd(st, val);

  st.push(top_val);
}

void reverseStack(std::stack<int> &st) {
  if (st.empty())
    return;

  // * Take the top of stack
  int top_val = st.top();
  st.pop();

  reverseStack(st);

  insertAtEnd(st, top_val);
}

int main(void) {
  std::stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  std::cout << "Before reversing the stack" << std::endl;
  printStack(st);
  
  reverseStack(st);

  std::cout << "After reversing the stack" << std::endl;
  printStack(st);
  return 0;
}

// * Run the code
// * g++ --std=c++20 01-reverse-a-stack.cpp -o output && ./output

