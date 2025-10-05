/*
 * Leetcode - 2106
 * Maximum Fruits Harvested After at Most K Steps
 * 
 * Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where 
 * fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. 
 * fruits is already sorted by positioni in ascending order, and each positioni is unique.

 * You are also given an integer startPos and an integer k. Initially, you are at the position startPos. 
 * From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and 
 * you can walk at most k steps in total. 
 * For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.

 * respectively.
 *
 * Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
 *
 * The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.
 *
 * Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

 * Example 1
 * input       : fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
 * output      : 9
 * Explanation : The optimal way is to:
 *               - Move right to position 6 and harvest 3 fruits
 *               - Move right to position 8 and harvest 6 fruits
 *               You moved 3 steps and harvested 3 + 6 = 9 fruits in total.

 * Example 1
 * input       : fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
 * output      : 14
 * Explanation : The optimal way is to:
 *               - Harvest the 7 fruits at the starting position 5
 *               - Move left to position 4 and harvest 1 fruit
 *               - Move right to position 6 and harvest 2 fruits
 *               - Move right to position 7 and harvest 4 fruits
 *               You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.

 * https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH: Optimal APPROACH -------------------------`
// * Move equal distance to left & right 
// * case 1: move 'd' distance to left
// * left_pos = start_pos - d
// * right_pos = start_pos - (k - (2 * d))

// * case 2: move 'd' distance to right
// * right_pos = start_pos - (k - (2 * d))
// * right_pos = start_pos + d

// * TIME COMPLEXITY O(klog(n))
// * SPACE COMPLEXITY O(n)
int maxTotalFruits(std::vector<std::vector<int>> &fruits, int start_pos, int k) {
  int n = fruits.size();

  std::vector<int> positions(n);
  std::vector<int> fruits_prefix_sum(n);
  for (int i = 0; i < n; ++i) { // * O(n)
    fruits_prefix_sum[i] = (i > 0 ? fruits_prefix_sum[i - 1] : 0) + fruits[i][1];
    positions[i] = fruits[i][0];
  }

  int max_fruits = 0;
  for (int d = 0; d < k / 2; ++d) { // * O(klogn)
    // * case 1 - moved 'd' steps to left
    int remain = k - 2 * d;
    int i = start_pos - d;
    int j = start_pos + remain;

    int left_pos = std::lower_bound(begin(positions), end(positions), i) - std::begin(positions);
    int right_pos = std::upper_bound(begin(positions), end(positions), j) - std::begin(positions) - 1;

    if (left_pos <= right_pos) {
      int total = fruits_prefix_sum[right_pos] - (left_pos > 0 ? fruits_prefix_sum[left_pos - 1] : 0);
      max_fruits = std::max(max_fruits, total);
    }
    
    // * Case 2 - moved 'd' steps to right
    remain = k - 2 * d;
    i = start_pos - remain;
    j = start_pos + d;

    left_pos = std::lower_bound(begin(positions), end(positions), i) - std::begin(positions);
    right_pos = std::upper_bound(begin(positions), end(positions), j) - std::begin(positions) - 1;

    if (left_pos <= right_pos) {
      int total = fruits_prefix_sum[right_pos] - (left_pos > 0 ? fruits_prefix_sum[left_pos - 1] : 0);
      max_fruits = std::max(max_fruits, total);
    }
  }

  return max_fruits;
}

int main(void) {
  // * testcase 1
  // int start_pos = 5, k = 4;
  // std::vector<std::vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};

  // * testcase 2
  int start_pos = 5, k = 4;
  std::vector<std::vector<int>> fruits = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};

  std::cout << "start_pos: " << start_pos << ", k: " << k << std::endl;
  std::cout << "Fruits: " << std::endl;
  for (auto &vec : fruits)
    printArr(vec);

  int ans = maxTotalFruits(fruits, start_pos, k);
  std::cout << "Maximum Fruits Harvested After at Most K Steps: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-max-fruits-harvested-after-at-most-k-steps.cpp -o output && ./output