/**
 * * Leetcode 779
 * * K-th Symbol in Grammar
 * * We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, 
 * * we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
 * * For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
 * * Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

 * * Example 1
 * * Input  : n = 1, k = 1
 * * Output : 0
 * 
 * * Example 2
 * * Input  : n = 2, k = 1
 * * Output : 0
 * 
 * * Example 3
 * * Input  : n = 2, k = 2
 * * Output : 1

 * * https://leetcode.com/problems/k-th-symbol-in-grammar/description/
 * * https://www.naukri.com/code360/problems/what-will-be-the-k-th-bit_1232657
*/

/* 
*       0
*      0 1
*    0 1 1 0
* 0 1 1 0 1 0 0 1
*/

#include <vector>
#include <math.h>
#include <iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH: Optimal APPROACH -------------------------`
// * Binary Search
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int kthGrammar(int n, int k) {
  int l = 1, r = std::pow(2, n - 1);
  int cur = 0;
  while(l < r) {
    int mid = (l + r) / 2;
    if (k <= mid) {
      r = mid;
    } else {
      l = mid + 1;
      // * Since the right part changes therefore we take compliment
      cur = 1 - cur;
    }
  }
  return cur;
}

int main() {
  int n = 4, k = 2;
  std::cout << "n: " << n << " k: " << k << std::endl;
  int ans = kthGrammar(n, k);
  std::cout << "Answer " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 08-kth-symbol-in-grammer.cpp -o output && ./output