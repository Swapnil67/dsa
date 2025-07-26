/**
 * * Leetcode - 2594
 * * Minimum Time to Repair Cars
 * * You are given an integer array ranks representing the ranks of some mechanics. 
 * * ranks[i] is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * (n * n) minutes.
 * 
 * * You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
 * * Return the minimum time taken to repair all the cars.
 * * Note: All the mechanics can repair the cars simultaneously.
 * 
 * * Example 1:
 * * Input       : ranks = [4,2,3,1], cars = 10
 * * Output      : 16
 * * Explanation : 
 * * - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
 * * - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
 * * - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
 * * - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
 * * - It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
 * 
 * * Example 2:
 * * Input       : ranks = [5,1,8], cars = 6
 * * Output      : 16
 * * Explanation : 
 * * - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
 * * - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
 * * - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
 * * - It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
 * 

 * * https://leetcode.com/problems/minimum-time-to-repair-cars/description/
 */

#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool isPossibleToRepairWithinTime(std::vector<int> &ranks,
                                  int &cars, long long &time) {
  long long totalCarsRepaired = 0;
  for (int &r : ranks) {
    // * how many car each mechanic with rank 'r' in given 'time'
    // * time = r * carsSqr  ------- (already given)
    // * carsSqr = time / r
    // * cars = sqrt(time / r)
    totalCarsRepaired += std::sqrt(time / r);
  }

  // std::cout << time << " cars repaired " << totalCarsRepaired << std::endl;
  return totalCarsRepaired >= cars;
}

long long repairCars(std::vector<int> &ranks, int cars) {
  int worstMechanic = *std::max_element(ranks.begin(), ranks.end());

  // * calculate max time taken to repair each car by the worst mechanic
  long long maxTime = 1ll * worstMechanic * (cars * cars);

  // * Time range for binary search
  long long l = 1, r = maxTime;     // * Time window
  long long ans = -1;
  while (l <= r) {
    long long time = l + (r - l) / 2;
    if (isPossibleToRepairWithinTime(ranks, cars, time)) {
      ans = time;
      r = time - 1;
    } else {
      l = time + 1;
    }
  }
  return ans;
}

int main(void) {
  // int cars = 10;
  // std::vector<int> ranks = {4, 2, 3, 1};
  
  int cars = 736185;
  std::vector<int> ranks = {31, 31, 5, 19, 19, 10, 31, 18, 19, 3, 16, 20, 4, 16, 2, 25, 10, 16, 23, 18, 21, 23, 28, 6, 7, 29, 11, 11, 19, 20, 24, 19, 26, 12, 29, 29, 1, 14, 17, 26, 24, 7, 11, 28, 22, 14, 31, 12, 3, 19, 16, 26, 11};

  std::cout << "Mechanics Ranks" << std::endl;
  printArr(ranks);
  std::cout << "Number of cars " << cars << std::endl;
  
  long long ans = repairCars(ranks, cars);
  std::cout << "Max time to wait " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 20-min-time-to-repair-car.cpp -o output && ./output

