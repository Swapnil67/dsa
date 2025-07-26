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
  for (int i = 0; i < n; ++i) {
    double km = (double)(dist[i]);
    if(i + 1 < n) { 
      currentHrs += std::ceil((double)km / (double)speed);
    } else {
      currentHrs += ((double)km / (double)speed);
    }
    // std::cout << std::ceil((double)km / (double)speed) << std::endl;
  }
  std::cout << speed << " -> " << currentHrs << std::endl;
  return currentHrs <= maxHours;
}

int minSpeedOnTime(std::vector<int>& dist, double hour) {
  int l = 1, r = *std::max_element(dist.begin(), dist.end());
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
