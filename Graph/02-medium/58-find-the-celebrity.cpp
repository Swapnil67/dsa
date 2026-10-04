/*
 * Leetcode - ?
 * Find the Celebrity
 * 
 * https://neetcode.io/problems/find-the-celebrity/question
 * https://www.naukri.com/code360/problems/the-celebrity-problem_982769
 * https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
*/

#include <vector>
#include <iostream>

using namespace std;

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

bool knows(int i, int j) {
  return true;
}

int is_celebrity(int i, int &n) {
  // * i -> celebrity
  // * j -> other members
  for (int j = 0; j < n; ++j) {
    if (i == j)
      continue;
    // * knows(i, j) -> celebrity should not know anybody
    // * knows(j, i) -> Other should know the celebrity
    if (knows(i, j) || !knows(j, i))
      return false;
  }

  return true;
}

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------
// * TIME COMPLEXITY  O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(int n) {
  for (int i = 0; i < n; i++) {
    if (is_celebrity(i, n))  {
      return i;
    }
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(1)
int findCelebrity(int n) {
  int celebrity_candidate = 0;
  for (int j = 1; j < n; ++j) {
    if (knows(celebrity_candidate, j)) {
      celebrity_candidate = j;
    }
  }

  return is_celebrity(celebrity_candidate, n) ? celebrity_candidate : -1;
}


// * ------------------------- APPROACH 3: Optimal Approach -------------------------
// * Matrix Variant
int celebrity2(vector<vector<int>> &mat) {
  int m = mat.size(), n = mat[0].size();

  // * eliminate non-celebrity candidates 
  int top = 0, bottom = n - 1;
  while (top < bottom) {
    if (mat[top][bottom] == 1) {
      top++; // * 'top' knows 'bottom', so 'top' cannot be a celebrity.
    }
    else {
      bottom--; // * // 'top' does not know 'bottom', so 'bottom' cannot be a celebrity.
    }
  }

  for (int i = 0; i < m; ++i) {
    if (i == top)
      continue;
    if (mat[top][i] || !mat[i][top])
      return -1;
  }

  return top;
}

int main(void) {
  // * testcase 1
  // vector<vector<int>> mat = {{0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}, {1, 0, 1, 0}};

  // * testcase 2
  // vector<vector<int>> mat = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};

  // * testcase 3
  vector<vector<int>> mat = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

  cout << "Input Matrix" << endl;
  for (auto &vec: mat) printArr(vec);
  
  int ans = celebrity2(mat);
  cout << "Celebrity is: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 58-find-the-celebrity.cpp -o output && ./output
