/*
* Minimize Max Distance to Gas Station 
* You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’
* gas stations on the X-axis. You are also given an integer ‘k’.
* You have to place 'k' new gas stations on the X-axis.
* You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.

* Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.

* Example 1:
* Input: books = ‘n' = 7 , ‘k’=6, ‘arr’ = {1,2,3,4,5,6,7}
* Output: 0.5
* Explanation: We can place 6 gas stations at 1.5, 2.5, 3.5, 4.5, 5.5, 6.5. 

* https://www.naukri.com/code360/problems/minimise-max-distance_7541449
*/

#include<queue>
#include<iostream>

// * ------------------------- Utility Functions -------------------------

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Find the section length of consecutive gas stations
// * TIME COMPLEXITY O(extra x n) * O(N) 
// * SPACE COMPLEXITY O(1)
long double bruteForce(std::vector<int> gasStations, int extra) {
  int n = gasStations.size();
  // * O(extra x n) 
  std::vector<int> howMany(n-1, 0);
  for (int gS = 1; gS <= extra; gS++) {
    int maxIdx = -1;
    long double maxSection = -1;
    for (int i = 0; i < n-1; i++) {
      long double diff = gasStations[i + 1] - gasStations[i];
      long double sectionLen = diff / (long double)(howMany[i] + 1);
      if (sectionLen > maxSection) {
        maxSection = sectionLen;
        maxIdx = i;
      }
    }
    howMany[maxIdx]++;
  }

  // printArr(howMany);

  long double maxLen = -1;
  for (int i = 0; i < n; i++) {
    long double diff = gasStations[i + 1] - gasStations[i];
    long double sectionLen = diff / (long double)(howMany[i] + 1);
    maxLen = std::max(maxLen, sectionLen);
  }

  return maxLen;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * TIME COMPLEXITY O(n) * O(logn) + O(extra) * O(logN)
// * Priority Queue operations takes O(logn)
// * SPACE COMPLEXITY O(n-1)
long double betterApproach(std::vector<int> gasStations, int extra) {
  int n = gasStations.size();
  std::vector<int> howMany(n-1, 0);

  // * O(n) * O(logn)
  // * Keep all the consecutive diff in priority queue (pq)
  std::priority_queue<std::pair<long double, int>> pq;
  for (int i = 0; i < n; i++) {
    int diff = gasStations[i + 1] - gasStations[i];
    pq.push({diff, i});
  }

  // * O(extra) * O(logN)
  for (int i = 1; i <= extra; i++) {
    auto pq_pair = pq.top();
    pq.pop();
    int secIdx = pq_pair.second;
    howMany[secIdx]++;
    long double diff = gasStations[secIdx + 1] - gasStations[secIdx];
    long double newSection = diff / (long double)(howMany[secIdx] + 1);
    pq.push({ newSection, secIdx });
  }

  return pq.top().first;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Binary Search

long double countGasStations(std::vector<int> gasStations, long double distance, int extra) {
  int n = gasStations.size(), cnt = 0;
  for (int i = 1; i < n; i++) {
    int gsPossible = (gasStations[i] - gasStations[i-1]) / distance;
    if ((gasStations[i] - gasStations[i - 1]) == gsPossible * distance) {
      gsPossible--;
    }
    // std::cout << "gsPossible " << gsPossible << std::endl;
    cnt += gsPossible;
  }
  return cnt;
}

long double gasStation(std::vector<int> gasStations, int extra) {
  int n = gasStations.size();
  long double l = 0;
  long double r;
  // * Get the max section diff from given gs
  for (long double i = 1; i < n; i++) {
    r = std::max(r, (long double)(gasStations[i] - gasStations[i - 1]));
  }

  std::cout << "l = " << l << " & r = " << r << std::endl;

  long double diff = 1e-6;
  while (r - l > diff) {
    long double m = l + (r - l) / (2.0);
    long double cnt = countGasStations(gasStations, m, extra);
    // std::cout << "distance: " << m << " & gas stations placed " << cnt << std::endl;
    if(cnt > extra) {
      l = m;
    }
    else {
      r = m;
    }
  }

  // * For understanding purpose
  // long double cnt = countGasStations(gasStations, 3, extra);
  // std::cout << "distance: " << 3 << " & gas stations placed " << cnt << std::endl;

  return r;
}

int main() {
  // * testcase 1
  int extra = 5;
  std::vector<int> gasStations = {1, 13, 17, 23};

  // * testcase 2
  // int extra = 6;
  // std::vector<int> gasStations = {1, 2, 3, 4, 5, 6, 7};

  printArr(gasStations);
  // long double maxDistance = bruteForce(gasStations, extra);
  // long double maxDistance = betterApproach(gasStations, extra);
  long double maxDistance = gasStation(gasStations, extra);
  std::cout << "Maximum distance " << maxDistance << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 08-minimize-max-distance-to-gas-station.cpp -o 08-minimize-max-distance-to-gas-station && ./08-minimize-max-distance-to-gas-station