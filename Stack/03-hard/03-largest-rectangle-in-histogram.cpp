/*
 * Leetcode - 84
 * Largest Rectangle in Histogram
 * 
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
 * return the area of the largest rectangle in the histogram.

 * Example 1
 * * Input   : heights = [2,1,5,6,2,3]
 * * Output  : 10
 * 
 * Example 2
 * * Input   : heights = [2,4]
 * * Output  : 4
 * 
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

#include <climits>
#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void getNextAndPreviousSmallerElements(std::vector<int> arr,
                                       std::vector<int> &nse, std::vector<int> &pse)
{
  int n = arr.size();

  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    while(!st.empty() && arr[st.top()] >= arr[i]) {
      // * Next Smaller Element
      nse[st.top()] = i;
      st.pop();
    }

    // * Previous Smaller Element
    if (st.size()) {
      pse[i] = st.top();
    }

    st.push(i);
  }
}


// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Use Next & Previous smaller elements
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(3N)
int bruteForce(std::vector<int> heights) {
  int n = heights.size();
  
  // * Find Next & Previous Smallest Elements
  std::vector<int> nse(n, -1);
  std::vector<int> pse(n, -1);
  getNextAndPreviousSmallerElements(heights, nse, pse);
  // printArr(nse);
  // printArr(pse);
  
  int largestArea = -1;
  for (int i = 0; i < n; ++i) {
    int curArea = heights[i] * (nse[i] - pse[i] - 1);
    largestArea = std::max(largestArea, curArea);
  }

  return largestArea;
}



// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Use Next & Previous smaller elements
// * While popping the elements we find the area of the popped element
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int largestRectangleArea(std::vector<int> heights) {
  int n = heights.size();
  int largestRect = INT_MIN;

  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    // * While popping the elements we find the area of the popped element
    // * its nse will be current element
    // * its pse will be st.top() element
    while (!st.empty() && heights[st.top()] >= heights[i]) {
      // * find the area of element of top of stack
      int stackTop = st.top();
      st.pop();

      int nextSmallerIdx = i;
      int prevSmallerIdx = -1;
      if (!st.empty()) {
        prevSmallerIdx = st.top();
      }

      int rect = heights[stackTop] * (nextSmallerIdx - prevSmallerIdx - 1);
      largestRect = std::max(largestRect, rect);
    }
    st.push(i);
  }

  // printStack(st);
  // std::cout << "=======" << std::endl;
  
  // * Handle all untouched elements on stack
  // * Here for all elements the nse will be n & pse will be st.top()
  while (!st.empty()) {
    int stackTop = st.top();
    st.pop();

    int prevSmallerIdx = -1;
    if (!st.empty()) {
      prevSmallerIdx = st.top();
    }

    int rect = heights[stackTop] * (n - prevSmallerIdx - 1);
    largestRect = std::max(largestRect, rect);
  }

  return largestRect;
}


int main() {
  // * testcase 1
  // std::vector<int> heights = {2, 1, 5, 6, 2, 3};
  
  // * testcase 2
  // std::vector<int> heights = {2, 4};
  
  // * testcase 3
  // std::vector<int> heights = {1, 1};
  
  // * testcase 4
  std::vector<int> heights = {1};

  printArr(heights);

  int ans = largestRectangleArea(heights);
  std::cout << "Largest Rectangle in Histogram " << ans << std::endl;
}

// * run the code
// * g++ --std=c++17 03-largest-rectangle-in-histogram.cpp -o output && ./output
