/*
 * Leetcode - 1094
 * Car Pooling
 * 
 * There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
 * 
 * You are given the integer capacity and an array trips where trips[i] = [numPassengersi, from, to] indicates that
 * the ith trip has numPassengers passengers and the locations to pick them up and drop them off are from and to respectively. 
 * The locations are given as the number of kilometers due east from the car's initial location.

 * If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

 * Example 1
 * input  : trips = [[2,1,5],[3,3,7]], capacity = 4
 * output : false

 * Example 2
 * input  : trips = [[2,1,5],[3,3,7]], capacity = 5
 * output : true
 * 
 * https://leetcode.com/problems/car-pooling/
*/

// ! Google, Meta, Amazon, Microsoft, Bloomberg, Flipkart

// * Same as Meeting Room III

#include <map>
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

// * ------------------------- Optimal Approach -------------------------`
// * using min_heap
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
bool carPooling(vector<vector<int>> &trips, int capacity) {
  // * Sort the trips by 'start' location
  sort(trips.begin(), trips.end(), [](const vector<int> &a, const vector<int> &b)
       { return a[1] < b[1]; });

  // * Min Heap of (destination, passengers)  
  typedef pair<int, int> P;
  priority_queue<P, vector<P>, greater<P>> min_heap;

  int passengers = 0;
  for (auto& trip : trips) {
    int cur_passengers = trip[0], start = trip[1], end = trip[2];

    // cout << trips[i][1] << " " << trips[i][2] << endl;

    // * if prev_trip destination is reached then drop the passengers before adding new ones
    while (!min_heap.empty() && start >= min_heap.top().first) {
      passengers -= min_heap.top().second;
      min_heap.pop();
    }

    passengers += cur_passengers;
    if (passengers > capacity)
      return false;

    min_heap.push({end, cur_passengers});
  }

  // cout << passengers << endl;
  return true;
}


// * ------------------------- Optimal Approach -------------------------`
// * using map
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
bool carPooling2(vector<vector<int>> &trips, int capacity) {
  map<int, int> mp;
  for (auto &trip: trips) {
    mp[trip[1]] += trip[0];
    mp[trip[2]] -= trip[0];
  }

  for (auto &it: mp) {
    // cout << it.first << " " << it.second << endl;
    capacity -= it.second;
    // cout << "capacity: " << capacity << endl;
    if (capacity < 0)
      return false;
  }
  return true;
}


// * ------------------------- Optimal Approach -------------------------`
// * using array
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool carPooling3(vector<vector<int>> &trips, int capacity) {
  vector<int> stops(1001, 0);
  for (auto &t : trips) {
    stops[t[1]] += t[0];
    stops[t[2]] -= t[0];
  }

  for (int i = 0; capacity >= 0 && i < 1001; ++i) {
      capacity -= stops[i];
  }
  return capacity >= 0;
}

int main(void) {
  // * testcase 1
  // int capacity = 4;
  // vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};

  // * testcase 2
  // int capacity = 4;
  // vector<vector<int>> trips = {{4, 1, 2}, {3, 2, 4}};

  // * testcase 2
  int capacity = 24;
  vector<vector<int>> trips = {{10, 5, 7}, {10, 3, 4}, {7, 1, 8}, {6, 3, 4}};

  cout << "Max seats: " << capacity << endl;
  cout << "Trips: " << endl;
  for (auto &trip : trips)
    printArr(trip);

  // bool ans = carPooling(trips, capacity);
  // bool ans = carPooling2(trips, capacity);
  bool ans = carPooling3(trips, capacity);
  cout << "Answer " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 15-car-pooling.cpp -o output && ./output