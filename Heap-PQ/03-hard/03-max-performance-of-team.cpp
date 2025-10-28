/*
 * Leetcode - 1383
 * Maximum Performance of a Team
 * 
 * You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
 * There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer
 * respectively.
 *
 * Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
 *
 * The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.
 *
 * Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

 * Example 1
 * input       : n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
 * output      : 60
 * Explanation : We have the maximum performance of the team by selecting engineer 2 
 *               (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). 
 *               That is, performance = (10 + 5) * min(4, 7) = 60.

 * Example 2
 * input       : n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
 * output      : 68
 * Explanation : This is the same example as the first but k = 3. We can select engineer 1, 
 *               engineer 2 and engineer 5 to get the maximum performance of the team. 
 *               That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

 * https://leetcode.com/problems/maximum-performance-of-a-team/description/
 * https://www.naukri.com/code360/problems/maximum-performance-of-a-team_1402944
*/

// ! Meta, uber

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

int solve(int i, int cur_sum, int cur_min,
          std::vector<int> &speed,
          std::vector<int> &efficiency, int k)
{
  if (k == 0) {
    return (cur_sum * cur_min);
  }

  if (i > speed.size())
    return INT_MIN;

  int take = solve(i + 1, cur_sum + speed[i], std::min(cur_min, efficiency[i]), speed, efficiency, k - 1);
  return std::max(take, solve(i + 1, cur_sum, cur_min, speed, efficiency, k));
}

// * ------------------------- Approach 1: Brute Force -------------------------`
// * Recursion & Backtracking
// * TIME COMPLEXITY O(2^n * nlogn)
// * SPACE COMPLEXITY O(n)
int bruteForce(int n,
                   std::vector<int> &speed,
                   std::vector<int> &efficiency, int k)
{
  return solve(0, 0, INT_MAX, speed, efficiency, k);
}


// * ------------------------- Approach 2: Optimal Approach -------------------------`
// * Recursion & Backtracking
// * TIME COMPLEXITY O(2^n * nlogn)
// * SPACE COMPLEXITY O(n)
int maxPerformance(int n,
                   std::vector<int> &speed,
                   std::vector<int> &efficiency, int k)
{
  const int MOD = 1'000'000'007;
  std::vector<std::pair<int, int>> engineers;
  for (int i = 0; i < n; ++i) {
    engineers.emplace_back(efficiency[i], speed[i]);
  }
  std::sort(engineers.rbegin(), engineers.rend()); // * DESC order

  // * For debugging
  // for (auto &vec : engineers)
  //   std::cout << vec.first << " " << vec.second << std::endl;

  std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
  long long speed_sum = 0, ans = 0;

  for (const auto &[eff, spd] : engineers) {
    if (min_heap.size() == k) {
      speed_sum -= min_heap.top();
      min_heap.pop();
    }

    speed_sum += spd;
    min_heap.push(spd);
    ans = std::max(ans, speed_sum * eff);
  }

  return ans % MOD;
}

int main(void) {
  // * testcase 1
  // int n = 6, k = 2;
  // std::vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};

  // * testcase 2
  int n = 6, k = 3;
  std::vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};

  // * testcase 3
  // int n = 6, k = 4;
  // std::vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};

  std::cout << "n: " << n << ", k: " << k << std::endl;
  std::cout << "Speed: ";
  printArr(speed);
  std::cout << "Efficiency: ";
  printArr(efficiency);

  // int ans = bruteForce(n, speed, efficiency, k);
  int ans = maxPerformance(n, speed, efficiency, k);
  std::cout << "Maximum Performance of a Team: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-max-performance-of-team.cpp -o output && ./output