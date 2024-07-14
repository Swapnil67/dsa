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

#include<iostream>
#include<queue>

// * ------------------------- Utility Functions -------------------------

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
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
      long double diff = gasStations[i+1] - gasStations[i];
      long double sectionLen = diff / (long double)(howMany[i] + 1);
      if(sectionLen > maxSection) {
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

// * ------------------------- APPROACH : Better APPROACH -------------------------`
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

int main() {
  // * testcase 1
  int extra = 5;
  std::vector<int> gasStations = {1, 13, 17, 23};

  // * testcase 2
  // std::vector<int> gasStations = {1, 2, 3, 4, 5, 6, 7};
  // int extra = 6;

  printArr(gasStations);
  long double maxDistance = bruteForce(gasStations, extra);
  // long double maxDistance = betterApproach(gasStations, extra);
  std::cout << "Maximum distance " << maxDistance << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 08-minimize-max-distance-to-gas-station.cpp -o 08-minimize-max-distance-to-gas-station && ./08-minimize-max-distance-to-gas-station