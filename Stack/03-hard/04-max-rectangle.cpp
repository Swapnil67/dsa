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
#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

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
  int largest_rect = 0;

  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    // * While popping the elements we find the area of the popped element
    // * its nse will be current element
    // * its pse will be st.top() element
    while (!st.empty() && heights[st.top()] >= heights[i]) {
      // * find the area of element of top of stack
      int top = st.top();
      st.pop();

      int nse_idx = i;
      int pse_idx = -1;
      if (!st.empty()) {
        pse_idx = st.top();
      }

      int rect = heights[top] * (nse_idx - pse_idx - 1);
      largest_rect = std::max(largest_rect, rect);
    }
    st.push(i);
  }

  // printStack(st);
  // std::cout << "=======" << std::endl;
  
  // * Handle all untouched elements on stack
  // * Here for all elements the nse will be n & pse will be st.top()
  while (!st.empty()) {
    int top = st.top();
    st.pop();

    int nse_idx = n;       // * next smaller index for st.top() will be 'n'
    int pse_idx = -1;      // * prev smaller index for st.top() will be prev st.top()
    if (!st.empty()) {
      pse_idx = st.top();
    }

    int rect = heights[top] * (nse_idx - pse_idx - 1);
    largest_rect = std::max(largest_rect, rect);
  }

  return largest_rect;
}

int maximalRectangle(std::vector<std::vector<char>> &matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  // * Get the first row from matrix 
  std::vector<int> heights(cols, 0);
  for(int i = 0; i < cols; ++i) {
    heights[i] = matrix[0][i] - '0';
  }
  // printArr(heights); // * For debugging
  int max_area = largestRectangleArea(heights);
  
  for (int i = 1; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == '0') {
        heights[j] = 0;
      } else {
        heights[j] = heights[j] + matrix[i][j] - '0';
      }
    }
    // printArr(heights); // * For debugging
    max_area = std::max(max_area, largestRectangleArea(heights));
  }

  return max_area;
}

int main() {
  // * testcase 1
  std::vector<std::vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};

  // * testcase 2
  // std::vector<std::vector<char>> matrix = {{'0', '1'}, {'1', '0'}};

  std::cout << "Vector Matrix" << std::endl;
  printMatrix(matrix);

  int ans = maximalRectangle(matrix);
  std::cout << "Largest Rectangle in Histogram " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++20 04-max-rectangle.cpp -o output && ./output
