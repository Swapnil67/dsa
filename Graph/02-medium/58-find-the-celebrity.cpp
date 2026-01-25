/*
 * Leetcode - ?
 * Find the Celebrity
 * 
 * https://neetcode.io/problems/find-the-celebrity/question
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
int findCelebrity(int n) {
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

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 58-find-the-celebrity.cpp -o output && ./output
