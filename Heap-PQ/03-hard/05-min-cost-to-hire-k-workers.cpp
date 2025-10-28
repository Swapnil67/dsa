/*
 * Leetcode - 857
 * Minimum Cost to Hire K Workers
 * 
 * There are n workers. You are given two integer arrays `quality` and `wage` where quality[i] is the quality of the ith worker
 * and wage[i] is the minimum wage expectation for the ith worker.
 * 
 * We want to hire exactly k workers to form a paid group. To hire a group of k workers, 
 * we must pay them according to the following rules:
 * 
 * 1. Every worker in the paid group must be paid at least their minimum wage expectation.
 * 2. In the group, each worker's pay must be directly proportional to their quality. 
 *   This means if a worker’s quality is double that of another worker in the group, 
 *   then they must be paid twice as much as the other worker.

 * Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions.
 * Answers within 10-5 of the actual answer will be accepted.

 * Example 1
 * input       : quality = [10,20,5], wage = [70,50,30], k = 2
 * output      : 105.0000
 * Explanation : We pay 70 to 0th worker and 35 to 2nd worker.

 * Example 2
 * input       : quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
 * output      : 30.66667
 * Explanation : We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
 * 
 * https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
*/

// ! Google, Apple

#include <queue>
#include <vector>
#include <cfloat>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// *
/* 
 * -- Intuition --
 *
 * Here `wage` is directly proportional to their `quality`
 * wage[manager]      quality[manager]
 * -------------  =   -----------------  
 * wage[worker]       quality[worker]
 * 
 * We'll fix the manager's wage & we need to find the workers wage
 * 
 * wage[worker] = wage[manager] * quality[worker] 
 *               ---------------------------------
 *                      quality[manager]
 * 
*/


// ! TLE
// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * k = no of workers
// * TIME COMPLEXITY O(n * (n + klogk))
// * SPACE COMPLEXITY O(k)
double bruteForce(std::vector<int>& quality, std::vector<int>& wage, int k) {
  int n = quality.size();
  double min_amount = DBL_MAX;

  for (int i = 0; i < n; ++i) { // * O(n)
    double manager_wage = wage[i] * 1.0;
    double manager_quality = quality[i] * 1.0;
    double manager_ratio = manager_wage / manager_quality;

    std::vector<double> group;
    std::cout << "Manager: " << manager_wage << std::endl;

    for (int j = 0; j < n; ++j) { // * O(n)
      double min_worker_wage = wage[j] * 1.0; // * min wage required by worker
      double worker_quality = quality[j] * 1.0; 

      // * wage that we need to offer based on quality of worker
      double calculated_worker_wage = manager_ratio * worker_quality;
      std::cout << "(" << manager_wage << " / " << manager_quality << ")" << " * " << worker_quality << " = " << calculated_worker_wage << std::endl;
      if (calculated_worker_wage >= min_worker_wage) {
        group.push_back(calculated_worker_wage);
      }
    }

    // * if we cannot form group of k-workers
    if (group.size() < k)
      continue;

    // * We only need 'k' workers
    std::priority_queue<double> max_heap;
    double sum_wage = 0;
    for (double &wage : group) { // * O(klogk)
      sum_wage += wage;
      max_heap.push(wage);

      if (max_heap.size() > k) {
        sum_wage -= max_heap.top();
        max_heap.pop();
      }
    }

    min_amount = std::min(min_amount, sum_wage); // * Find the min amount
  }

  return min_amount;
}


// *
/* 
 * -- Intuition --
 *
 * manager_ratio = (wage[manager] / quality[manager])
 * 
 * We know this much from previous
 * calculated_worker_wage >= min_worker_wage
 * manager_ratio * worker_quality >= min_worker_wage
 * 
 * We can also say the following
 * manager_ratio >= min_worker_wage / worker_quality
 * manager_ratio >= worker_ratio
 * 
*/

// ! TLE
// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * k = no of workers
// * TIME COMPLEXITY O(nlogn) + O(n + klogk))
// * SPACE COMPLEXITY O(k)
double betterApproach(std::vector<int>& quality, std::vector<int>& wage, int k) {
  int n = quality.size();
  double min_amount = DBL_MAX;
  
  // * save all the ratios into array
  std::vector<std::pair<double, int>> ratios;
  for (int i = 0; i < n; ++i) {
    double ratio = ((double)wage[i] / (double)quality[i]);
    ratios.push_back({ratio, quality[i]});
  }
  std::sort(begin(ratios), end(ratios));  // * O(nlogn)
  
  for (int manager = k - 1; manager < n; ++manager) {
    double manager_ratio = ratios[manager].first;
    
    std::vector<double> group;
    for (int worker = 0; worker <= manager; ++worker) {
      // * worker_wage = manger_ration * worker_quality
      double worker_wage = manager_ratio * ratios[worker].second;
      group.push_back(worker_wage);
    }

    // * We only need 'k' workers
    std::priority_queue<double> max_heap;
    double sum_wage = 0;
    for (double &cur_wage : group) { // * O(klogk)
      sum_wage += cur_wage;
      max_heap.push(cur_wage);

      if (max_heap.size() > k) {
        sum_wage -= max_heap.top();
        max_heap.pop();
      }
    }

    min_amount = std::min(min_amount, sum_wage);
  }

  return min_amount;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * k = no of workers
// * TIME COMPLEXITY O(nlogn) + O(nlogk)
// * SPACE COMPLEXITY O(n)
double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
  int n = quality.size();
  
  // * save all the ratios into array
  // * {ratio, quality}
  std::vector<std::pair<double, int>> ratios;
  for (int i = 0; i < n; ++i) {
    double ratio = ((double)wage[i] / (double)quality[i]);
    ratios.push_back({ratio, quality[i]});
  }
  std::sort(begin(ratios), end(ratios));  // * O(nlogn)

  // * For debugging
  // for (auto &p : ratios) {
  //   std::cout << p.first << " " << p.second << std::endl;
  // }

  // * Find first 'k-group' quality to `max_heap`
  int quality_sum = 0;
  std::priority_queue<int> max_heap;
  for (int i = 0; i < k; ++i) { // * O(klogk)
    int cur_quality = ratios[i].second;
    max_heap.push(cur_quality);
    quality_sum += cur_quality;
  }

  // * First k-group manager_ratio
  double first_manager_ratio = ratios[k - 1].first;

  // * First k-group amount
  double min_amount = first_manager_ratio * quality_sum;

  std::cout << first_manager_ratio << " * " << quality_sum << " = " << min_amount << std::endl;
  
  for (int manager = k; manager < n; ++manager) { // * O(nlog)
    double cur_manager_ratio = ratios[manager].first;

    int cur_quality = ratios[manager].second;
    max_heap.push(cur_quality);
    quality_sum += cur_quality;
    
    if (max_heap.size() > k) { // * only need k-workers
      quality_sum -= max_heap.top();
      max_heap.pop();
    }

    double current_amount = cur_manager_ratio * quality_sum;
    min_amount = std::min(min_amount, current_amount);
  }

  return min_amount;
}

int main(void) {
  // * testcase 1
  // int k = 2;
  // std::vector<int> quality = {10, 20, 5}, wage = {70, 50, 30};

  // * testcase 2
  int k = 3;
  std::vector<int> quality = {3, 1, 10, 10, 1}, wage = {4, 8, 2, 2, 7};

  std::cout << "Quality: ";
  printArr(quality);
  std::cout << "Wage: ";
  printArr(wage);

  // double amount = bruteForce(quality, wage, k);
  // double amount = betterApproach(quality, wage, k);
  double amount = mincostToHireWorkers(quality, wage, k);
  std::cout << "Minimum Cost to Hire " << k << " Workers: " << amount << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-min-cost-to-hire-k-workers.cpp -o output && ./output