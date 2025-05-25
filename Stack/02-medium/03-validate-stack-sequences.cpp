/*
 * Leetcode - 946
 * Validate Stack Sequences
 * Given two integer arrays pushed and popped each with distinct values, return true if this could have 
 * been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
 * 
 * * Example 1
 * * Input  : pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * * Output : true

 * * Example 2
 * * Input  : pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * * Output : false

* https://leetcode.com/problems/validate-stack-sequences/description/
*/

#include<iostream>
#include<stack>
#include<vector>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

bool validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped) {
  int n = pushed.size();
  std::stack<int> st;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    st.push(pushed[i]);

    // * keep popping if st.top() == popped[j]
    while (!st.empty() && st.top() == popped[j]) {
      st.pop();
      j++;
    }
  }

  return st.size() ? false : true;
}

int main() {
  // std::vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
  // std::vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 3, 5, 1, 2};
  std::vector<int> pushed = {2, 1, 0}, popped = {1, 2, 0};

  std::cout << "Pushed Array: " << std::endl;
  printArr(pushed);
  std::cout << "Popped Array: " << std::endl;
  printArr(popped);

  bool ans = validateStackSequences(pushed, popped);
  std::cout << "Validate Stack Sequences: " << ans << std::endl;

  return 0;
}

// * Run the code
// * $CXX 03-validate-stack-sequences.cpp -o output && ./output 