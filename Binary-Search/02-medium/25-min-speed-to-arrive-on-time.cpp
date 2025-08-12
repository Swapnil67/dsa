/*
 * Leetcode - 1870
 * Minimum Speed to Arrive on Time 
 * 
 * You are given a floating-point number hour, representing the amount of time you have to reach the office. 
 * To commute to the office, you must take n trains in sequential order. 
 * You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) 
 * of the ith train ride.
 * 
 * Each train can only depart at an integer hour, so you may need to wait in between each train ride.
 * 
 * For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours
 * before you can depart on the 2nd train ride at the 2 hour mark.
 * 
 * Return the minimum positive integer speed (in kilometers per hour) that all the trains must 
 * travel at for you to reach the office on time, or -1 if it is impossible to be on time.
 * 
 * Tests are generated such that the answer will not exceed 107 and hour will have at most two digits 
 * after the decimal point.
 * 
 * Example 1:
 * Input  :  dist = [1,3,2], hour = 6
 * Output :  1
 * 
 * Example 2:
 * Input  :  dist = [1,3,2], hour = 2.7
 * Output :  3
 * 
 * Example 3:
 * Input  :  dist = [1,3,2], hour = 1.9
 * Output :  -1
 * 
 * https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/
 */

#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  std::cout << "[";
  for (auto &x : arr) {
    std::cout << x << ", ";
  }
  std::cout << "]" << std::endl;
}

bool isValidSpeed(std::vector<int> &dist, int &speed, double &maxHours) {
  int n = dist.size();
  double currentHrs = 0;

  for (int i = 0; i < n - 1; ++i) {
    double km = (double)(dist[i]);
    double hr = std::ceil((double)km / (double)speed);
    // std::cout << dist[i] << " => " << hr << std::endl;
    currentHrs += hr;
  }
  double hr = ((double)(dist[n - 1]) / (double)speed);
  currentHrs += hr;
  // std::cout << dist[n - 1] << " => " << hr << std::endl;

  // std::cout << speed << " -> " << currentHrs << std::endl;
  // std::cout << "------------------------------" << std::endl;

  return currentHrs <= maxHours;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(log(1e9-7)) * O(n)
// * SPACE COMPLEXITY O(1)
int minSpeedOnTime(std::vector<int>& dist, double hour) {
  int l = 0, r = 1e9 - 7;
  int ans = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(isValidSpeed(dist, m, hour)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}


int main(void) {
  // double hour = 6;
  // std::vector<int> dist = {1, 3, 2};

  double hour = 2.7;
  std::vector<int> dist = {1, 3, 2};
  
  std::cout << "Total Hours " << hour << std::endl;
  std::cout << "Distance in km" << std::endl;
  printArr(dist);

  int speed = minSpeedOnTime(dist, hour);
  std::cout << "Minimum Speed to Arrive on Time: " << speed << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 25-min-speed-to-arrive-on-time.cpp -o output && ./output
