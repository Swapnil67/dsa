/**
 * * Leetcode - 2379
 * * Minimum Recolors to Get K Consecutive Black Blocks
 * * You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith 
 * * block. The characters 'W' and 'B' denote the colors white and black, respectively.
 * * You are also given an integer k, which is the desired number of consecutive black blocks.
 * * In one operation, you can recolor a white block such that it becomes a black block.
 * * Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

 * * Example 1
 * * Input  : blocks = "WBBWWBBWBW", k = 7
 * * Output : 3
 * * Explanation : One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
 * * so that blocks = "BBBBBBBWBW". It can be shown that there is no way to achieve 7 consecutive black blocks in
 * * less than 3 operations. Therefore, we return 3.
 * 
 * * Example 2
 * * Input  : blocks = "WBWBBBW", k = 2
 * * Output : 0
 * * Explanation : No changes need to be made, since 2 consecutive black blocks already exist.
 * * Therefore, we return 0.

 * * https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/
*/

#include <vector>
#include <climits>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`
// * Sliding window Approach
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int minimumRecolors(std::string blocks, int k) {
  int n = blocks.size();
  int i = 0, j = 0;
  int cur_ops = 0, min_ops = INT_MAX;
  while (j < n) {
    // * check if window exceeded
    if (j - i + 1 > k) {
      if(blocks[i] == 'W') {
        cur_ops -= 1;
      }
      i += 1;
    }

    // * found 'W' block
    if (blocks[j] == 'W') {
      cur_ops += 1;
    }

    // * Window matched
    if (j - i + 1 == k) {
      min_ops = std::min(min_ops, cur_ops);
    }
  
    // * Increase the window
    j += 1;
  }

  return min_ops == INT_MAX ? 0 : min_ops;
}

int main() {
  // int k = 7;
  // std::string blocks = "WBBWWBBWBW";
  int k = 2;
  std::string blocks = "WBWBBBW";
  int ans = minimumRecolors(blocks, k);
  std::cout << "Minimum recolors for " << k << " Consecutive Black Blocks" << " is " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 03-min-recolor-to-blocks.cpp -o output && ./output