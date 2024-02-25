/*
* Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
* The guards have gone and will come back in h hours.
* Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas
* from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more
* bananas during this hour.
* Return the minimum integer k such that she can eat all the bananas within h hours.

* Example 1:
* Input: piles = [3,6,7,11], h = 8
* Output: 4

* Example 2:
* Input: piles = [30,11,23,4,20], h = 5
* Output: 30

* https://leetcode.com/problems/koko-eating-bananas/description/
* https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064
*/


#include <iostream>
#include <cmath>
using namespace std;

long long totalHrForPile(vector<int>& piles, int hr, int maxHr) {
  float totalHrs = 0;
  for(int i=0; i<piles.size(); i++) {
    // * (piles[i]/hr + (piles[i]%hr != 0)); Ceiling an number without using ceil function
    totalHrs += (piles[i]/hr + (piles[i]%hr != 0)); // * OR
    totalHrs += ((float)piles[i] / (float)k);
    // cout<<piles[i]/hr<<" + "<<(piles[i]%hr != 0)<<" = "<<(piles[i]/hr + (piles[i]%hr != 0))<<" "<<endl;
    if(totalHrs > maxHr) break;
  }
  // cout<<endl;
  return totalHrs;
}

int findMax(vector<int> &arr) {
  int maxi = INT_MIN;
  for(int i=0; i<arr.size(); i++) {
    maxi = max(maxi, arr[i]);
  }
  return maxi;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// * TIME COMPLEXITY O(N) * O(maxBananasPerHr) 
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &piles, int maxBananasPerHr, int maxHrs) {
  for (int i = 1; i <= maxBananasPerHr; i++) {

    // * O(N) for this loop
    long long isMinHr = totalHrForPile(piles, i, maxHrs);
    // cout << "hr: " << i << endl;
    // cout << "isMinHr: " << isMinHr << endl;
    if (isMinHr <= maxHrs) {
      return i;
    }
  }
  return maxBananasPerHr;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------

// * TIME COMPLEXITY O(N) * log(maxBananasPerHr) 
// * SPACE COMPLEXITY O(1)
int optimalApproach(vector<int> &piles, int maxBananasPerHr, int maxHrs) {
  int low = 1, high = maxBananasPerHr, ans = maxBananasPerHr;
  while(low <= high) {
    int mid = low + (high-low)/2;

    // * O(N) for this loop
    long long totalHrsToCompletePile = totalHrForPile(piles, mid, maxHrs);

    cout<<"mid: "<<mid<<endl;
    cout<<"totalHrsToCompletePile: "<<totalHrsToCompletePile<<endl;

    if(totalHrsToCompletePile <= maxHrs) {
      ans = mid;
      high = mid - 1;
    }
    else  {
      low = mid + 1;
    }
  }

  return ans;
}

int main() {
  vector<int> piles = {3,6,7,11};
  int h = 8;
  // vector<int> piles = {30,11,23,4,20};
  // int h = 5;
  // vector<int> piles = {30,11,23,4,20};
  // int h = 6;
  // vector<int> piles = {1000000000};
  // int h = 2;
  int maxBananasPerHr = findMax(piles);
  // cout<<"maxBananasPerHr "<<maxBananasPerHr<<endl;
  int minHr = bruteForce(piles, maxBananasPerHr, h);
  // int minHr = optimalApproach(piles, maxBananasPerHr, h);
  cout << minHr << endl;
}