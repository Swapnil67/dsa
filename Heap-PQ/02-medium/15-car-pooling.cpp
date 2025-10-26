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

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}


// * ------------------------- Optimal Approach -------------------------`
// * using min_heap
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
bool carPooling(std::vector<std::vector<int>> &trips, int capacity) {
  // * Sort the trips by 'start' location
  std::sort(trips.begin(), trips.end(), [](const std::vector<int> &a, const std::vector<int> &b)
       { return a[1] < b[1]; });

  // * Heap of (destination, passengers)  
  typedef std::pair<int, int> P;
  std::priority_queue<P, std::vector<P>, std::greater<P>> min_heap;

  int passengers = 0;
  for (auto& trip : trips) {
    int cur_passengers = trip[0], start = trip[1], end = trip[2];

    // std::cout << trips[i][1] << " " << trips[i][2] << std::endl;

    // * if prev_trip destination is reached then drop the passengers before adding new ones
    while (!min_heap.empty() && min_heap.top().first <= start) {
      passengers -= min_heap.top().second;
      min_heap.pop();
    }

    passengers += cur_passengers;
    if (passengers > capacity)
      return false;

    min_heap.push({end, cur_passengers});
  }

  // std::cout << passengers << std::endl;
  return true;
}

int main(void) {
  // * testcase 1
  // int capacity = 4;
  // std::vector<std::vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};

  // * testcase 2
  // int capacity = 4;
  // std::vector<std::vector<int>> trips = {{4, 1, 2}, {3, 2, 4}};

  // * testcase 2
  int capacity = 24;
  std::vector<std::vector<int>> trips = {{10, 5, 7}, {10, 3, 4}, {7, 1, 8}, {6, 3, 4}};

  std::cout << "Max seats: " << capacity << std::endl;
  std::cout << "Trips: " << std::endl;
  for (auto &trip : trips)
    printArr(trip);

  bool ans = carPooling(trips, capacity);
  std::cout << "Answer " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 15-car-pooling.cpp -o output && ./output