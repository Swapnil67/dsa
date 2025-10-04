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


void solve(
    int idx, int k,
    int cur_sum, int min_efficiency,
    int &ans,
    std::vector<int> &speed,
    std::vector<int> &efficiency)
{
  ans = std::max(ans, (cur_sum * min_efficiency));
  // std::cout << cur_sum << ", " << min_efficiency << " -> " << ans << std::endl;
  if (k == 0 || idx >= speed.size()) {
    return;
  }

  solve(idx + 1, k - 1, cur_sum + speed[idx], std::min(min_efficiency, efficiency[idx]), ans, speed, efficiency);
  solve(idx + 1, k, cur_sum, min_efficiency, ans, speed, efficiency);
}

// * ------------------------- Brute Force Approach -------------------------`
// * Recursion & Backtracking
// * TIME COMPLEXITY O(2^n * nlogn)
// * SPACE COMPLEXITY O(n)
int bruteForce(int n,
                   std::vector<int> &speed,
                   std::vector<int> &efficiency, int k)
{
  int ans = INT_MIN;
  solve(0, k, 0, INT_MAX, ans, speed, efficiency);
  return ans;
}

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
  // int n = 6, k = 3;
  // std::vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};

  // * testcase 3
  int n = 6, k = 4;
  std::vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};

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