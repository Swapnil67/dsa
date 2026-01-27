/*
 * Leetcode - 1642
 * Furthest Building You Can Reach
 * 
 * You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
 * You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
 * 
 * While moving from building i to building i+1 (0-indexed),
 * 
 * - If the current building's height is greater than or equal to the next building's height, 
 *   you do not need a ladder or bricks.
 * 
 * - If the current building's height is less than the next building's height, you can either use one ladder
 *   or (h[i+1] - h[i]) bricks.
 * 
 * Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.
 * 
 * Example 1
 * input  : heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
 * output : 4
 * 
 * Example 2
 * input  : heights = [1, 5, 1, 2, 3, 4, 10000], bricks = 4, ladders = 1
 * output : 5
 * 
 * https://leetcode.com/problems/furthest-building-you-can-reach/description/
 * https://www.naukri.com/code360/problems/furthest-building-you-can-reach_1382372
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * This will fail
// * for testcase 3
int greedyApproach(std::vector<int> &heights, int bricks, int ladders) {
  int n = heights.size();
  int i = 0;
  while (i < n) {
    // * If next building is smaller
    if (heights[i + 1] < heights[i]) {
      i++;
    } else {
      int extra_height = heights[i + 1] - heights[i];
      if (bricks >= extra_height) {
        bricks -= extra_height;
        i++;
      } else if(ladders > 0) {
        ladders -= 1;
        i++;
      } else {
        break;
      }
    }
  }

  return i;
}

int helper(std::vector<int> &heights, int idx, int bricks, int ladders) {
  // * On the last building
  if (idx >= heights.size() - 1)
    return 0;

  // * If next building is smaller in height than current building
  if (heights[idx + 1] <= heights[idx]) {
    return 1 + helper(heights, idx + 1, bricks, ladders);
  }

  // * If next building is greater in height than current building
  // * We have two options 
  // * 1. To use bricks
  // * 2. To use Ladder

  int by_bricks = 0;
  int by_ladder = 0;

  // * use bricks
  int extra_bricks = heights[idx + 1] - heights[idx];
  if (bricks >= extra_bricks) {
    by_bricks = 1 + helper(heights, idx + 1, bricks - extra_bricks, ladders);
  }

  // * use ladder
  if(ladders > 0) {
    by_ladder = 1 + helper(heights, idx + 1, bricks, ladders - 1);
  }

  return std::max(by_bricks, by_ladder);
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Recursion + Backtracking
// ! TLE
int bruteForce(std::vector<int> &heights, int bricks, int ladders) {
  int n = heights.size();
  return helper(heights, 0, bricks, ladders);
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using max_heap
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
  int n = heights.size();

  // * max_heap for extra bricks used
  std::priority_queue<int> max_heap;

  int i = 0;  
  while (i < n) {
    if (heights[i + 1] <= heights[i]) {
      i++;
    } else {
      int extra_bricks = heights[i + 1] - heights[i];
      // std::cout << "extra_bricks = " << extra_bricks << ",\t b =  " << bricks << ",\t l = " << ladders << std::endl;
      if (bricks >= extra_bricks) {
        bricks -= extra_bricks;
        max_heap.push(extra_bricks); // * save bricks used in max_heap
      } 
      else if (ladders > 0) {
        // * Check if we used more bricks previously
        if (!max_heap.empty() && max_heap.top() >= extra_bricks) {
          bricks += max_heap.top();
          max_heap.pop();
          bricks -= extra_bricks;
          max_heap.push(extra_bricks); // * save bricks used in max_heap
        }
        ladders -= 1;
      } 
      else {
        break;
      }
      i++;
    }
  }

  return i;
}

int main(void) {
  // * testcase 1
  // int bricks = 5, ladders = 1;
  // std::vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
  
  // * testcase 2
  // int bricks = 10, ladders = 2;
  // std::vector<int> heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
  
  // * testcase 3
  int bricks = 4, ladders = 1;
  std::vector<int> heights = {1, 5, 1, 2, 3, 4, 10000};

  std::cout << "bricks: " << bricks << ", ladders: " << ladders << std::endl;
  std::cout << "Buildings heights: ";
  printArr(heights);

  // int ans = bruteForce(heights, bricks, ladders);
  int ans = furthestBuilding(heights, bricks, ladders);
  std::cout << "Furthest Building You Can Reach: " << ans << " height." << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-furthest-building-you-can-reach.cpp -o output && ./output