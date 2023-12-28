#include <iostream>
#include <cmath>
using namespace std;

long long totalHrForPile(vector<int>& piles, int hr, int maxHr) {
  float totalHrs = 0;
  for(int i=0; i<piles.size(); i++) {
    totalHrs += (piles[i]/hr + (piles[i]%hr != 0));
    // cout<<piles[i]/hr<<" + "<<(piles[i]%hr != 0)<<" = "<<(piles[i]/hr + (piles[i]%hr != 0))<<" ";
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
  // vector<int> piles = {3,6,7,11};
  // int h = 8;
  // vector<int> piles = {30,11,23,4,20};
  // int h = 5;
  vector<int> piles = {30,11,23,4,20};
  int h = 6;
  // vector<int> piles = {1000000000};
  // int h = 2;
  int maxBananasPerHr = findMax(piles);
  // cout<<"maxBananasPerHr "<<maxBananasPerHr<<endl;
  // int minHr = bruteForce(piles, maxBananasPerHr, h);
  int minHr = optimalApproach(piles, maxBananasPerHr, h);
  cout << minHr << endl;
}