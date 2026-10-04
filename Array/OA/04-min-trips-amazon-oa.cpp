/*
 * Deliver Packages
 * Given an array of size “N”
 * 
 * In a single trip, the delivery agent can chose package following either of two rules:
 *  - Choose two packages with the same weight
 *  - Choose three packages with the same weight
 * 
 * Determine the min number of trips required to deliver packages. if it is not possible to deliver all
 * of them, return -1
 * 
 * Example 1    :
 * Input        : packageWeight = {2, 4, 6, 6, 4, 2, 4}
 * Output       : 3
 *  
 * Example 2    :
 * Input        : packageWeight = {1, 8, 5, 8, 5, 1}
 * Output       : 3
 *  
 * Example 3    :
 * Input        : packageWeight = {1, 1, 1, 1, 1, 1, 1, 1}
 * Output       : 3
 * 
 * Example 4    :
 * Input        : packageWeight = {1, 2}
 * Output       : -1
 * 
 * https://docs.google.com/document/d/1esfWAWutnC-WEOJT0N9vC3Z5EFkUteCrHCtE8rqetEM/edit?tab=t.0
*/

// ! OA
// ! Amazon

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
ll getMinimumTrips(vector<ll> &packageWeight) {
  unordered_map<ll, ll> packageFreq;
  for (auto &p: packageWeight) {
    packageFreq[p]++;
  }

  ll trips = 0;
  for (auto &[p, freq]: packageFreq) {
    if (freq == 1) {
      return -1;
    }
    else {
      trips += ((freq / 3) + (freq % 3 != 0));
    }
  }
  return trips;
}

int main(void) {
  // * testcase 1
  // vector<ll> packageWeight = {2, 4, 6, 6, 4, 2, 4};

  // * testcase 2
  // vector<ll> packageWeight = {1, 8, 5, 8, 5, 1};
  
  // * testcase 3
  vector<ll> packageWeight = {1, 1, 1, 1, 1, 1, 1, 1};
  
  // * testcase 4
  // vector<ll> packageWeight = {1, 2};

  cout << "Package Weights: ";
  printArr(packageWeight);

  int minTrips = getMinimumTrips(packageWeight);
  cout << "Minimum trips: " << minTrips << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 rough.cpp -o output && ./output
