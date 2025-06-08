// * Next Greater
// ! greater requires decreasing, smaller requires increasing stacks.

#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void printStack(std::stack<int> st) {
  std::stack<int> temp = st;
  while(!temp.empty()) {
    std::cout << temp.top() << std::endl;
    temp.pop();
  }
}

// * Next Greater
std::vector<int> nextGreaterElement(std::vector<int> arr) {
  int n = arr.size();
  
  // * initialize nextGreater array, this array hold the output
  // * initialize all the elements are -1 (invalid value)
  std::vector<int> nextGreater(n, -1);
  
  std::stack<int> st;
  for(int i = 0; i < n; ++i) {
    // * the element represented by stack top is STRICTLY SMALLER than the current element
    while (!st.empty() && arr[st.top()] < arr[i]) {
      // * pop out the top of the stack, it represents the index of the item
      int stackTop = st.top();
      nextGreater[stackTop] = i;
      st.pop();
    } 

    // * Push the cur element
    st.push(i);

  }

  return nextGreater;
}

// * Previous Greater
std::vector<int> previousGreaterElement(std::vector<int> arr) {
  int n = arr.size();
  
  // * initialize all the elements are -1 (invalid value)
  std::vector<int> prevGreater(n, -1);
  
  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    // * This means, the stack will always be strictly decreasing (type 3) - because elements are popped when they are equal
    // * so equal elements will never stay in the stack (definition of strictly decreasing stack)
    while (!st.empty() && arr[st.top()] <= arr[i])
      st.pop();
    
    // * after the while loop, only the elements which are greater than the current element are left in stack
    if (st.size()) {
      prevGreater[i] = st.top();
    }
  
    st.push(i);
  }

  return prevGreater;
}

int main(void) {
  std::vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
  std::cout << "Input Array:" << std::endl;
  printArr(arr);
  
  // * Next Greater elements
  std::vector<int> ans = nextGreaterElement(arr);
  std::cout << "Next Greater Elements:" << std::endl;
  printArr(ans);

  // * Prev Greater elements
  ans = previousGreaterElement(arr);
  std::cout << "Previous Greater Elements:" << std::endl;
  printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 greater.cpp -o output && ./output
