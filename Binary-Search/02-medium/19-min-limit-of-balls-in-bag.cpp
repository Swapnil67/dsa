/**
 * * Leetcode - 1760
 * * Minimum Limit of Balls in a Bag

 * * You are given an integer array nums where the ith bag contains nums[i] balls. 
 * * You are also given an integer maxOperations.
 * 
 * * You can perform the following operation "at most maxOperations" times:
 * * Take any bag of balls and divide it into two new bags with a positive number of balls. 
 * * For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
 * 
 * * Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.
 * * Return the minimum possible penalty after performing the operations.
 * 
 * * Example 1:
 * * Input       : nums = [9], maxOperations = 2
 * * Output      : 3
 * * Explanation : 
 * * - Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
 * * - Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
 * * The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
 * 
 * * Example 2:
 * * Input       : nums = [2,4,8,2], maxOperations = 4
 * * Output      : 2
 * * Explanation : 
 * * - Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
 * * - Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
 * * - Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
 * * - Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
 * 
 * * The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.
 * 
 * * https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/
*/

// ! Binary Search on Answers

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

/*
* We can try solving this question by using max priority heap but it will fail for some case
* eq: nums: {9}, maxOperations = 2; will fail with max heap approach
* [2, 3, 4] => max heap after 2 operations. This gives the answer as '4' but correct answer is '3'.
*/


// * Find how many operations does it takes of we divide nums[i] by the balls
// * Find the total operations for all the bags of balls
bool isValidPenalty(std::vector<int> nums, int maxOperations, int maxBalls) {
  int n = nums.size();
  long long totalOps = 0;
  for (int &balls : nums) {
    totalOps += (balls / maxBalls);

    // * Since it can fit in one bag so no need to perform operation
    if (balls % maxBalls == 0)
      totalOps--;
  }

  std::cout << maxBalls << " => " << totalOps << std::endl;
  return totalOps <= maxOperations;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * TIME COMPLEXITY O(maxPenalty * logn)
// * SPACE COMPLEXITY O(1)
int burteForce(std::vector<int> &nums, int operations) {
  int n = nums.size();
  int maxPenalty = *std::max_element(nums.begin(), nums.end());
  int ans = 0;
  for (int i = 1; i < maxPenalty; ++i) {
    int currentPenalty = i;
    if (isValidPenalty(nums, operations, currentPenalty)) {
      ans = currentPenalty;
      break;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(maxPenalty) * log(n))
// * SPACE COMPLEXITY O(1)
int minimumSize(std::vector<int> &nums, int operations) {
  int n = nums.size();
  int maxPenalty = *std::max_element(nums.begin(), nums.end());
  int ans = 0;
  int l = 0, r = maxPenalty;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (isValidPenalty(nums, operations, m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main(void) {
  // int maxOperations = 2;
  // std::vector<int> nums = {9};
  
  int maxOperations = 4;
  std::vector<int> nums = {2, 4, 8, 2};

  std::cout << "Balls" << std::endl;
  printArr(nums);
  std::cout << "Operations " << maxOperations << std::endl;

  // int ans = burteForce(nums, maxOperations);
  int ans = minimumSize(nums, maxOperations);
  std::cout << "Min balls in bag: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 19-min-limit-of-balls-in-bag.cpp -o output && ./output

// * DRY RUN

// * l = 1, r = 8
// * m = 4
// * [2 4 8 2]
// * [0 0 1 0] = 1 operation (therefore r = m - 1)

// * l = 1, r = 3
// * m = 2
// * [2 4 8 2]
// * [0 1 2 0] = 3 operation (therefore r = m - 1)

// * l = 1, r = 2
// * m = 1
// * [2 4 8 2]
// * [2 4 8 2] = 16 operation (therefore r = m - 1)

// * l = 2, r = 2
// * m = 2
// * [2 4 8 2]
// * [0 1 2 0] = 3 operation (therefore r = m - 1)

// * l = 2, r = 1
// * Break the loop