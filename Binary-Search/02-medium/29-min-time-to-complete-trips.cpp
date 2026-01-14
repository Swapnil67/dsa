/*
 * Leetcode - 2187
 * Minimum Time to Complete Trips
 * 
 * You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
 * 
 * Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 
 * Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.
 *
 * You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
 * Return the minimum time required for all buses to complete at least totalTrips trips.
 *
 * Example 1   :
 * Input       : time = [1,2,3], totalTrips = 5
 * Output      : 3

 * Example 2   :
 * Input       : time = [2], totalTrips = 1
 * Output      : 2

 * Example 3   :
 * Input       : time = [5, 10, 10], totalTrips = 9
 * Output      : 25

 * Example 4   :
 * Input       : time = [10000], totalTrips = 10000
 * Output      : 10000
 
 * https://leetcode.com/problems/minimum-time-to-complete-trips/description/
 */

// ! Google, Meta, Meesho

#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

typedef long long ll;

bool is_valid(std::vector<int> time, ll total_time, int total_trips) {
  int trips = 0;
  for (auto &trip_time: time) {
    trips += (total_time / trip_time);
    if (trips >= total_trips)
      break;
  }
  // std::cout << "Total Time: " << total_time << ", Trips: " << trips << " => " << (trips >= total_trips) << std::endl;
  return trips >= total_trips;
}

// * ------------------------- APPROACH : Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
ll minimumTime(std::vector<int> time, int totalTrips) {
  ll l = 0, r = (ll)(totalTrips) * (*std::min_element(begin(time), end(time)));
  ll ans = 0;
  while (l <= r){
    ll m = l + (r - l) / 2;
    if (is_valid(time, m, totalTrips)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // int totalTrips = 5;
  // std::vector<int> time = {1,2,3};
  
  // * testcase 2
  int totalTrips = 9;
  std::vector<int> time = {5, 10, 10};
  
  // * testcase 3
  // int totalTrips = 1;
  // std::vector<int> time = {4};
  
  // * testcase 4
  // int totalTrips = 10000000;
  // std::vector<int> time = {10000};

  std::cout << "totalTrips: " << totalTrips << std::endl;
  std::cout << "Time: ";
  printArr(time);

  ll ans = minimumTime(time, totalTrips);
  std::cout << "Minimum Time to Complete Trips: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 29-min-time-to-complete-trips.cpp -o output && ./output