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
