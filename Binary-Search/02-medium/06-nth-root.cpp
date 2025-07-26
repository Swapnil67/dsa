/*
 * Nth Root of a number
 
 * Example 1:
 * Input: n = 3, m = 37
 * Output: 3

 * Example 2:
 * Input: n = 4, m = 69
 * Output: -1

 * https://www.naukri.com/code360/problems/nth-root-of-m_1062679
 * https://www.youtube.com/watch?v=rjEJeYCasHs&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=54&t=181s
*/

#include<iostream>

// * return 0 if nthRoot == m
// * return 1 if nthRoot > m
// * return 2 if nthRoot < m
int checkRoot(int m, int mid, int power) {
  long long nthRoot = 1;
  // std::cout << "---------- " << mid << " --------------- " << std::endl;
  for (int i = 1; i <= power; i++) {
    nthRoot = mid * nthRoot;
    // std::cout << "nthRoot " << nthRoot << std::endl;
    // * Don't go to extreme nth root 
    if (nthRoot > m)  {
      return 1;
    }
  }
  
  if(nthRoot == (long long)m) {
    return 0;
  }

  // * nthRoot is smaller than m
  return 2;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Linear search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(int n, int m) {
  for (int i = 1; i <= m; i++) {
    int val = checkRoot(m, i, n);
    if(val == 0)
      return i;
    else if (val == 1)
      break;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Binary Search on answers
// * TIME COMPLEXITY O(logM) * O(M)
// * SPACE COMPLEXITY O(1)
int findNthRoot(int n, int m) {
  int ans = -1;
  long long l = 1, r = m;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int val = checkRoot(m, mid, n);
    if (val == 0)
      return mid;
    else if (val == 1)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}

int main() {
  // * testcase 1
  // int n = 3, m = 27;

  // * testcase 2
  int n = 4, m = 69;

  // * testcase 3
  // int n = 9, m = 1953125;

  // * testcase 4
  // int n = 5, m = 32768;

  // int nthRoot = bruteForce(n, m);
  int nthRoot = findNthRoot(n, m);
  std::cout << n << " Root of " << m << " is " << nthRoot << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 06-nth-root.cpp -o output && ./output