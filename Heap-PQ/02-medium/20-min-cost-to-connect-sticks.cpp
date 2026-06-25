/*
 * Leetcode - PAID
 * Minimum Cost to Connect Sticks
 * 
 * You have some number of sticks with positive integer lengths. These lengths are given as an array sticks,
 * where sticks[i] is the length of the iᵗʰ stick.
 * 
 * You can connect any two sticks of lengths x and y into one stick by paying a cost of x + y. 
 * You must connect all the sticks until there is only one stick remaining.
 * 
 * Return the minimum cost of connecting all the given sticks into one stick in this way.

 * Example 1
 * input  : sticks = [2,4,3]
 * output : 14

 * Example 2
 * input  : sticks = [1,8,3,5]
 * output : 30
 * 
 * https://neetcode.io/problems/minimum-cost-to-connect-sticks/question
*/

// ! Amazon, Google, IBM, JP, Twitter

#include <queue>
#include <vector>
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

// * ------------------------- APPROACH 2A: Optimal Approach -------------------------`
// * Using Greedy + min_heap
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
int connectSticks(vector<int> &sticks) {
  int n = sticks.size();
  if (n <= 1)
    return 0;

  // * Populate the min_heap with stick cost
  priority_queue<int, vector<int>, greater<>> min_heap(begin(sticks), end(sticks));

  int total = 0;
  // * combine two of the smallest sticks until we are left with just one.
  while (min_heap.size() > 1) {
    int stick1 = min_heap.top();
    min_heap.pop();

    int stick2 = min_heap.top();
    min_heap.pop();

    int cost = stick1 + stick2;
    total += cost;
    min_heap.push(cost);
  }

  return total;
}

int main() {
  // * testcase 1
  vector<int> sticks = {2, 4, 3};

  // * testcase 2
  // vector<int> sticks = {1, 8, 3, 5};

  cout << "Nums: ";
  printArr(sticks);

  int ans = connectSticks(sticks);

  cout << "Kth Largest Element in an Array: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 20-min-cost-to-connect-sticks.cpp -o output && ./output


