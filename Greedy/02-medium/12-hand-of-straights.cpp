/*
 * Leetcode - 846
 * Hand of Straights
 * 
 * Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of
 * size groupSize, and consists of groupSize consecutive cards.
 * 
 * Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
 * return true if she can rearrange the cards, or false otherwise.
 * 
 * Example 1
 * input            : hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
 * output           : true
 * Explanation      : Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

 * Example 2
 * input            : hand = [1,2,3,4,5], groupSize = 4
 * output           : false
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 * https://neetcode.io/problems/hand-of-straights/
*/

// ! Amazon, Microsoft, Google, Meta, Bloomberg, Visa

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

// * ------------------------- Approach: Optimal Approach -------------------------
// * Map + Heap
// * A good strategy is to always start building a group from the smallest card value that is still available.
// * we keep a min-heap of the available card values so we can always get the current smallest value quickly
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
bool isNStraightHand(vector<int>& hand, int groupSize) {
  int n = hand.size();
  if (n % groupSize != 0)
    return false;

  // * Count the frequency of each card
  unordered_map<int, int> freq_mp;
  for (auto &h : hand)
    freq_mp[h]++;

  // * Add all the unique cards to min heap
  priority_queue<int, vector<int>, greater<>> pq; // * min heap
  for (auto &[k, v] : freq_mp)
    pq.push(k);

  // * For Debugging
  // for (auto &[k,v]: freq_mp)
  //   cout << k << " " << v << endl;

  // * Form groups
  while (!pq.empty()) {
    int first = pq.top();
    for (int i = first; i < first + groupSize; ++i) {
      if (freq_mp[i] <= 0)
        return false;

      freq_mp[i]--;
      if (freq_mp[i] == 0) {
        if (pq.top() != i)
          return false;
        pq.pop();
      }
    }
  }

  // * For Debugging
  // for (auto &[k, v] : freq_mp)
  //   cout << k << " " << v << endl;

  return true;
}


// * ------------------------- Approach: Optimal Approach -------------------------
// * Map + Sorting
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
bool isNStraightHand2(vector<int>& hand, int groupSize) {
  int n = hand.size();
  if (n % groupSize != 0)
    return false;

  // * Count the frequency of each card
  unordered_map<int, int> freq_mp;
  for (auto &h : hand)
    freq_mp[h]++;

  // * Sort the cards
  sort(begin(hand), end(hand));

  // * Form groups
  for (auto &h: hand) {
    if (freq_mp[h] > 0) {
      for (int i = h; i < h + groupSize; ++i) {
        if (freq_mp[i] == 0)
          return false;
        freq_mp[i]--;
      }
    }
  }

  return true;
}

int main(void) {
  // * testcase 1
  // vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  // int groupSize = 3;
  
  // * testcase 2
  vector<int> hand = {1, 2, 3, 4, 5};
  int groupSize = 4;

  cout << "hand: ";
  printArr(hand);

  bool ans = isNStraightHand(hand, groupSize);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 12-hand-of-straights.cpp -o output && ./output

