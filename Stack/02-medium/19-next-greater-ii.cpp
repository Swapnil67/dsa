/*
 * Leetcode - 503
 * Next Greater II
 * 
 * Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
 * return the next greater number for every element in nums.
 * 
 * Example 1
 * * Input       : nums = [1,2,3,4,3]
 * * Output      : [2,3,4,-1,4]
 * 
 * Example 2
 * * Input       : nums = [1,2,1]
 * * Output      : [2,-1,2]
 * 
 * https://leetcode.com/problems/next-greater-element-ii/
*/

// ! Amazon, Flipkart, Microsoft

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

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Double the array virtually
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> arr) {
  int n = arr.size();

  std::vector<int> nge(n, -1);
  for (int i = 0; i < n; ++i) {
    // * This will double the array hypothetically
   for (int j = i; j < i + n; ++j) {
      int idx = j % n;
      if (arr[idx] > arr[i]) {
        nge[i] = arr[idx];
        break;
      }
    }
  }

  return nge;
}

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Double the array virtually + Monotonic Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> nextGreaterElementA(std::vector<int> arr) {
  int n = arr.size();

  std::vector<int> nge(n, -1);
  std::stack<int> st;

  // * hypothetically increase the size of array 
  for (int i = 0; i < n + n - 1; ++i) {
      // * the element represented by stack top is STRICTLY SMALLER than the current element
      while (!st.empty() && arr[st.top()] < arr[i % n]) {
        nge[st.top()] = arr[i % n];
        st.pop();
      }

      st.push(i % n);
  }

  return nge;
}

// * ------------------------- APPROACH 2B: Optimal Approach -------------------------`
// * Using Monotonic Stack (little Magic)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> nextGreaterElementB(std::vector<int> arr) {
  int n = arr.size();

  std::vector<int> nge(n, -1);
  std::stack<int> st;

  // * run the outer loop two times
  for (int j = 0; j < 2 ; j++) {
    for (int i = 0; i < n; ++i) {
       // * the element represented by stack top is STRICTLY SMALLER than the current element
      while (!st.empty() && arr[st.top()] < arr[i]) {
        nge[st.top()] = arr[i];
        st.pop();
      }
      st.push(i);
    }
    // printStack(st);
  }

  return nge;
}

int main(void) {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 4, 3};

  // * testcase 2
  std::vector<int> arr = {1, 2, 1};

  std::cout << "Input Array:" << std::endl;
  printArr(arr);

  // std::vector<int> ans = bruteForce(arr);
  // std::vector<int> ans = nextGreaterElementA(arr);
  std::vector<int> ans = nextGreaterElementB(arr);

  std::cout << "Next Greater Elements:" << std::endl;
  printArr(ans);
  return 0;
}


// * run the code
// * g++ --std=c++17 19-next-greater-ii.cpp -o output && ./output