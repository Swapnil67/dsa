#include <queue>
#include <math.h>
#include <vector>
#include <climits>
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

typedef long long ll;
typedef pair<int, int> pii;


// * 16 - Range Sum of Sorted Subarray Sums
// int rangeSum(vector<int>& nums, int n, int left, int right) {
// TODO
// }

// * 17 - design-twitter
// TODO: Solve this on leetcode

// * 18 - Total Cost to Hire K Workers
// long long totalCost(vector<int> &costs, int k, int candidates) {
// TODO
// }

// * 19 - 
// TODO

// * 20 - Minimum Cost to Connect Sticks
// int connectSticks(vector<int> &sticks) {
// TODO
// }

// * 21 - Campus Bikes
// int connectSticks(vector<int> &sticks) {
// TODO
// }

// * ------------------------------------------------------------------------------------

// * 01 - K Closest Points to Origin
// vector<vector<int>> kClosest(vector<vector<int>> points, int k) {
// TODO
// }

// * 02 - Kth Largest Element in an Array
// int findKthLargest(vector<int> &nums, int k) {
// TODO
// }

// * 03 - Task Scheduler
// int leastInterval(vector<char>& tasks, int n) {
// TODO
// }

// * 04 - Least Number of Unique Integers after K Removals
// int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
// TODO
// }

// * 05 - Furthest Building You Can Reach
// int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
// TODO
// }

// * 06 - Maximum Subsequence Score
// long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
// TODO
// }

// * 07 - Single-Threaded CPU
// vector<int> cpuTasks(vector<vector<int>> &tasks) {
// TODO
// }

// * 08 - Seat Reservation Manager
// * Do this on Leetcode

// * 09 - Process Tasks Using Servers
// vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
// TODO
// }

// * 10 - Find the Kth Largest Integer in the Array
// string kthLargestNumber(vector<string>& nums, int k) {
// TODO
// }

// * 11 - Top K Frequent Elements
// vector<int> topKFrequent(vector<int> &nums, int k) {
// TODO
// }

// * 12 - Find K Closest Elements
// vector<int> findClosestElements(vector<int> &arr, int k, int x) {
// TODO
// }

// * 13 - Reorganize String
// string reorganizeString(string &s) {  
// TODO
// } 

// * 14 - Longest Happy String
// string longestDiverseString(int a, int b, int c) {
// TODO
// }

// * 15 - Car Pooling
// bool carPooling(vector<vector<int>> &trips, int capacity) {
// TODO
// }

int main(void) {
  return 0; 
}

// * Run the code
// * g++ -ggdb --std=c++20 practice.cpp -o output && ./output