/*
 * Leetcode - 85
 * Maximal Rectangle
 * 
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 * Example 1
 * * Input  : matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
 * * Output : 6
 * 
 * Example 2
 * * Input   : matrix = [["0"]]
 * * Output  : 0
 * 
 * Example 3
 * * Input   : matrix = [["1"]]
 * * Output  : 1
 * 
 * https://leetcode.com/problems/maximal-rectangle/description/
*/

#include <stack>
#include <climits>
#include <vector>
#include <iostream>

// * Print the matrix
void printMatrix(std::vector<std::vector<char>> matrix) {
  int r = matrix.size();
  int c = matrix[0].size();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

// * This is similar to 'largest rectangle in histogram'
// * From largest rectangle in 1D array
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

int maximalRectangle(std::vector<std::vector<char>> &matrix) {
  int n = matrix[0].size();
  
  // * Get the first row from matrix 
  std::vector<int> heights(n);
  for(int i = 0; i < n; ++i) {
    heights[i] = matrix[0][i] - '0';
  }
  
  int maxArea = largestRectangleArea(heights);
  
  int r = matrix.size();
  for (int row = 1; row < r; ++row) {
    for (int col = 0; col < n; ++col) {
      heights[col] += matrix[row][col] - '0';
    }
    maxArea = std::max(maxArea, largestRectangleArea(heights));
  }

  return maxArea;
}

int main() {
  std::cout << "Vector Matrix" << std::endl;
  std::vector<std::vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};

  printMatrix(matrix);

  int ans = maximalRectangle(matrix);
  std::cout << "Largest Rectangle in Histogram " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 04-max-rectangle.cpp -o output && ./output
