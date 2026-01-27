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

// * Next Smaller (strictly smaller)
std::vector<int> nextSmallerElement(std::vector<int> arr) {
  int n = arr.size();
  
  // * initialize nextSmaller array, this array hold the output
  // * initialize all the elements are -1 (invalid value)
  std::vector<int> nextSmaller(n, -1);
  
  std::stack<int> st;
  for(int i = 0; i < n; ++i) {
    // * the element represented by stack top is STRICTLY GREATER than the current element
    while (!st.empty() && arr[st.top()] > arr[i]) {
      // * pop out the top of the stack, it represents the index of the item
      nextSmaller[st.top()] = i;
      st.pop();
    } 

    // * Push the cur element
    st.push(i);

  }

  return nextSmaller;
}

// * Previous Smaller (strictly smaller)
std::vector<int> prevSmallerElement(std::vector<int> arr) {
  int n = arr.size();
  
  // * initialize prevSmaller array, this array hold the output
  // * initialize all the elements are -1 (invalid value)
  std::vector<int> prevSmaller(n, -1);
  
  std::stack<int> st;
  for(int i = 0; i < n; ++i) {
    // * the element represented by stack top is LARGER OR EQUAL to the current element
    // * This means, the stack will always be monotonic strictly increasing (type 1)
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }

    if (st.size()) {
      prevSmaller[i] = st.top();
    }

    // * Push the cur element
    st.push(i);
  }

  return prevSmaller;
}

int main(void) {
  std::vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
  std::cout << "Input Array:" << std::endl;
  printArr(arr);

  // * Next Smaller elements
  std::vector<int> ans = nextSmallerElement(arr);
  std::cout << "Next Smaller Elements:" << std::endl;
  printArr(ans);
  
  // * Prev Smaller elements
  ans = prevSmallerElement(arr);
  std::cout << "Prev Smaller Elements:" << std::endl;
  printArr(ans);
  return 0;
}


// * run the code
// * g++ --std=c++17 smaller.cpp -o output && ./output
