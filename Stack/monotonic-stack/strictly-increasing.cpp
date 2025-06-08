#include <stack>
#include <vector>
#include <iostream>

// ! greater requires decreasing, smaller requires increasing stacks.

void printStack(std::stack<int> st) {
  std::stack<int> temp = st;
  while(!temp.empty()) {
    std::cout << temp.top() << std::endl;
    temp.pop();
  }
}

void buildMonotonicStack(std::vector<int> arr) {
  int n = arr.size();
  std::stack<int> st;

  for(int i = 0; i < n; ++i) {
    int cur = arr[i];
    
    // * Remove all the greater elements than cur from stack
    // * push all removed elements to temp stack
    std::stack<int> temp;
    while (!st.empty() && st.top() > cur) {
      temp.push(st.top());
      st.pop();
    } 

    // * Push the cur element
    st.push(cur);

    // * Put back the popped elements again
    if(temp.size()) {
      while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
      }
    }
  }

  // * Print the stack
  printStack(st);
}

int main(void) {
  std::vector<int> arr = {1, 8, 2, 4, 0, 9};
  buildMonotonicStack(arr);
  return 0;
}


// * run the code
// * g++ --std=c++17 strictly-increasing.cpp -o output && ./output
