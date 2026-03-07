/*
  * Leetcode - 875
  * Koko Eating Bananas 
  *
  * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
  * The guards have gone and will come back in 'h' hours.
  * Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas
  * from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more
  * bananas during this hour.
  * Return the minimum integer k such that she can eat all the bananas within h hours.

  * Example 1 :
  * Input     : piles = [3, 6, 7, 11], h = 8
  * Output    : 4

  * Example 2   :
  * Input       : piles = [30,11,23,4,20], h = 5
  * Output      : 30

  * https://leetcode.com/problems/koko-eating-bananas/description/
  * https://www.naukri.com/code360/problems/minimum-rate-to-eat-bananas_7449064
*/

// ! Amazon, Google, Meta, Microsoft, Oracle, Adobe, Apple

#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

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

int findHrsToCompletePile(vector<int> piles, int bananas) {
  int total_hrs = 0;
  for (int i = 0; i < piles.size(); i++) {
    total_hrs += ceil((double)piles[i] / bananas);
    // cout << piles[i] / k << " + " << (piles[i] % k != 0) << " = " << (piles[i] / k + (piles[i] % k != 0)) << " " << endl;
  }
  return total_hrs;
}

bool is_valid(vector<int> &piles, int &bananas, int &h) {
  int total_hrs = 0;
  for (auto &b : piles) {
    total_hrs += ceil((double)b / (double)bananas);
    if (total_hrs > h)
      break;
  }
  return total_hrs <= h;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N) * O(maxBananasPerHr) 
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> piles, int maxHrs) {
  int maxBananas = *max_element(piles.begin(), piles.end());
  int ans = maxBananas;
  for (int i = 1; i <= maxBananas; i++) {
    // * O(N) for this loop
    long long isMinHr = findHrsToCompletePile(piles, i);
    // cout << "isMinHr " << isMinHr << endl;
    if (isMinHr <= maxHrs) {
      return i;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N) * log(maxBananas) 
// * SPACE COMPLEXITY O(1)
int findMinimumBananasToEat(vector<int> piles, int hr) {
  int l = 0, r = *max_element(piles.begin(), piles.end());
  int ans = r;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int can_finish = is_valid(piles, mid, hr);
    // cout << mid << " hours took " << can_finish << endl;
    if (can_finish) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}

int main() {
  cout << "Koko eating bananas" << endl;

  // * testcase 1 (Ans = 4)
  // vector<int> piles = {3, 6, 7, 11};
  // int h = 8;

  // * testcase 2 (Ans = 30)
  // vector<int> piles = {30, 11, 23, 4, 20};
  // int h = 5;

  // * testcase 3 (Ans = 23)
  // vector<int> piles = {30, 11, 23, 4, 20};
  // int h = 6;

  // * testcase 4 (Not Work in Bruteforce)
  vector<int> piles = {1000000000};
  int h = 2;

  cout << "Piles of bananas" << endl;
  printArr(piles);

  // int minimumBananas = bruteForce(piles, h);
  int minimumBananas = findMinimumBananasToEat(piles, h);
  cout << "Koko need to eat " << minimumBananas << " bananas each hour to finish full pile in " << h << " hours." << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-koko-eating-banana.cpp -o output && ./output