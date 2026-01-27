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

// ! Greater requires Decreasing Stack

// * For Next Greater
// std::vector<int> nextGreaterElement(std::vector<int> &arr) {
// TODO
// }

// * For Prev Greater
// std::vector<int> previousGreaterElement(std::vector<int> &arr) {
// TODO
// }

// ! Smaller requires Increasing Stack

// * For Next Smaller
// std::vector<int> nextSmallerElement(std::vector<int> &arr) {
// TODO
// } 

// std::vector<int> prevSmallerElement(std::vector<int> &arr) {
// TODO
// }

int main() {
  std::vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
  std::cout << "Input Array:" << std::endl;
  printArr(arr);

  // * Next Greater elements
  // std::vector<int> ans = nextGreaterElement(arr);
  // std::cout << "Next Greater Elements:" << std::endl;
  // printArr(ans);

  // * Prev Greater elements
  // ans = previousGreaterElement(arr);
  // std::cout << "Previous Greater Elements:" << std::endl;
  // printArr(ans);

  // * Next Smaller elements
  // std::vector<int> ans = nextSmallerElement(arr);
  // std::cout << "Next Smaller Elements:" << std::endl;
  // printArr(ans);
  
  // * Prev Smaller elements
  // ans = prevSmallerElement(arr);
  // std::cout << "Prev Smaller Elements:" << std::endl;
  // printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 practice.cpp -o output && ./output
