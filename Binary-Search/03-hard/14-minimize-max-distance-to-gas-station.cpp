/*
* Leetcode - 134
* Minimize Max Distance to Gas Station 
*
* You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’
* gas stations on the X-axis. You are also given an integer ‘k’.
* You have to place 'k' new gas stations on the X-axis.
* You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.

* Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.

* Example 1:
* Input: books = ‘n' = 7 , ‘k’ = 6, ‘arr’ = {1,2,3,4,5,6,7}
* Output: 0.5
* Explanation: We can place 6 gas stations at 1.5, 2.5, 3.5, 4.5, 5.5, 6.5. 

* https://leetcode.com/problems/minimize-max-distance-to-gas-station/description/
* https://www.naukri.com/code360/problems/minimise-max-distance_7541449
* https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
*/

// ! BS on Answers

#include <queue>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Find the section length of consecutive gas stations
// * TIME COMPLEXITY O(k x n) * O(N) 
// * SPACE COMPLEXITY O(n)
long double bruteForce(vector<int> gasStations, int k) {
  int n = gasStations.size();
  // * O(k x n)
  vector<int> howMany(n - 1, 0);
  for (int gS = 1; gS <= k; gS++) {
    int maxIdx = -1;
    long double maxSection = -1;
    for (int i = 0; i < n - 1; i++) {
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
  for (int i = 0; i < n - 1; i++) {
    long double diff = gasStations[i + 1] - gasStations[i];
    long double sectionLen = diff / (long double)(howMany[i] + 1);
    maxLen = max(maxLen, sectionLen);
  }

  return maxLen;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Max Heap
// * TIME COMPLEXITY O(nlogn) + O(klogn)
// * SPACE COMPLEXITY O(n)
long double betterApproach(vector<int> gasStations, int extra) {
  int n = gasStations.size();

  typedef long double ld;

  // * O(n) * O(logn)
  // * Keep all the consecutive diff in priority queue (pq)
  priority_queue<pair<ld, int>> pq;
  for (int i = 0; i < n - 1; i++) {
    pq.push({(ld)(gasStations[i + 1] - gasStations[i]), i});
  }

  // * O(extra) * O(logN)
  vector<int> howMany(n - 1, 0);
  for (int i = 1; i <= extra; i++) {
    auto pq_pair = pq.top();
    pq.pop();
    int secIdx = pq_pair.second;
    howMany[secIdx]++;
    ld diff = gasStations[secIdx + 1] - gasStations[secIdx];
    ld newSection = diff / (ld)(howMany[secIdx] + 1);
    pq.push({newSection, secIdx});
  }

  return pq.top().first;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Binary Search

// * Helper function: Calculates how many new stations are required 
// * to ensure no two adjacent stations are further apart than 'distance'.
int countGasStations(const vector<int> &gasStations, long double distance) {
    int n = gasStations.size();
    int cnt = 0;
    
    // * Iterate through every existing adjacent pair of gas stations
    for (int i = 1; i < n; i++) {
        // * Calculate how many times 'distance' fits into the current gap.
        // * Integer division automatically truncates the decimal part.
        int gsPossible = (gasStations[i] - gasStations[i - 1]) / distance;
        
        // * If the gap divides perfectly by 'distance', the last placed station 
        // * would land exactly on top of the existing station at gasStations[i].
        // * We subtract 1 to prevent overcounting this overlapping station.
        if ((gasStations[i] - gasStations[i - 1]) == gsPossible * distance) {
            gsPossible--;
        }
        
        // * Add the required stations for this gap to the total count
        cnt += gsPossible;
    }
    return cnt;
}

// * TIME COMPLEXITY O(nlog(maxDist))
// * SPACE COMPLEXITY O(n)
long double gasStation(vector<int> gasStations, int k) {
  int n = gasStations.size();
  long double l = 0; // * lower bound (minimum possible distance)
  // * 'r' represents the upper bound (maximum possible distance).
  // * BUG FIX: Initialized 'r' to 0.0 to avoid undefined behavior from garbage values.
  long double r = 0.0;

  // * Find the largest existing gap between any two stations to set our upper bound 'r'
  for (int i = 1; i < n; i++) {
    r = max(r, (long double)(gasStations[i] - gasStations[i - 1]));
  }

  // * Define the precision limit (stop searching when the search window is smaller than 10^-6)
  long double diff = 1e-6;

  // * Perform binary search on the answer
  while ((r - l) > diff) {
    // * Calculate the midpoint distance to test
    long double m = l + (r - l) / 2.0;

    // * Count how many stations are needed if the max distance allowed is 'm'
    int cnt = countGasStations(gasStations, m);

    if (cnt > k) { // * If we need MORE than 'k' stations, 'm' is too small.
      // * We must look for a larger maximum distance, so move the lower bound up.
      l = m;
    }
    else { // * If we need 'k' or fewer stations, 'm' is achievable.
      // * Since we want to MINIMIZE the distance, we save this as a valid upper bound
      // * and try to find an even smaller max distance.
      r = m;
    }
  }

  // * 'r' (or 'l') will hold the minimized maximum distance within the 1e-6 precision limits
  return r;
}

int main() {
  // * testcase 1
  int extra = 2;
  vector<int> gasStations = {1, 13, 25};

  // * testcase 2
  // int extra = 5;
  // vector<int> gasStations = {1, 13, 17, 23};

  // * testcase 3
  // int extra = 6;
  // vector<int> gasStations = {1, 2, 3, 4, 5, 6, 7};

  cout << "Gas Stations" << endl;
  printArr(gasStations);

  // long double maxDistance = bruteForce(gasStations, extra);
  // long double maxDistance = betterApproach(gasStations, extra);
  long double maxDistance = gasStation(gasStations, extra);

  cout << "Maximum distance " << maxDistance << endl;
  return 0;
}

// * Run the code¡
// * g++ --std=c++20 14-minimize-max-distance-to-gas-station.cpp -o output && ./output
