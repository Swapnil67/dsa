/*
 * Leetcode - 853
 * Car Fleet
 * There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
 * 
 * You are given two integer array position and speed, both of length n, 
 * where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.
 * 
 * A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
 * A car fleet is a car or cars driving next to each other.
 * The speed of the car fleet is the minimum speed of any car in the fleet.
 * 
 * If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.
 * Return the number of car fleets that will arrive at the destination.

 * * Example 1
 * * Input  : target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
 * * Output : 3
 * 
 * https://leetcode.com/problems/car-fleet/description/
*/

// ! Monotonic Stack
// ! Microsoft, Google, Amazon, Meta, Bloomberg

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n * logn)
// * SPACE COMPLEXITY O(n)
int carFleetOld(int target, std::vector<int> &position, std::vector<int> &speed) {
  int n = position.size();
  
  // * Pairs of <position, speed>
  std::vector<std::pair<float, float>> cars(n);
  for (int i = 0; i < n; ++i) {
    cars[i] = {(float)position[i], (float)speed[i]};
  }
  // * sort in descending order
  std::sort(cars.begin(), cars.end(), std::greater<std::pair<float, float>>());

  // * For debug information
  // for (auto &it: cars) {
  //   printf("%f %f\n", it.first, it.second);
  // }
  // printf("\n");

  int fleet = 1;
  float f_target = (float)target;
  std::pair<float, float> back = cars[0], front;
  for(int i = 1; i < n; ++i) {
    front = cars[i];

    // * get time taken to reach target
    float t1 = (f_target - back.first) / back.second;
    float t2 = (f_target - front.first) / front.second;

    // printf("t1: %f, t2: %f\n", t1, t2);

    if(t1 < t2) {
      // * Different fleet starts
      back = front;
      fleet++;
    }
  }

  return fleet;
}


// * ------------------------- APPROACH 1: Optimal Approach -------------------------`
// * More easy to understand
// * Monotonic Stack
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
int carFleet(int target, std::vector<int> &position, std::vector<int> &speed) {
  int n = position.size();

  std::vector<std::pair<int, double>> cars;
  for (int i = 0; i < n; i++) {
    double time = (double)(target - position[i]) / speed[i];
    cars.push_back({position[i], time});
  }

  // sort cars by positions descending(target ke pass wali pahle)
  sort(cars.rbegin(), cars.rend());

  std::stack<double> st;
  for (auto &car : cars) {
    double time = car.second;

    // New fleet condition
    if (st.empty() || time > st.top()) {
      st.push(time);
    }
    // else: same fleet --> isme kuch nhi karna
  }
  return st.size();
}

int main() {
  // * testcase 1
  // int target = 12;
  // std::vector<int> position = {10, 8, 0, 5, 3}, speed = {2, 4, 1, 1, 3};

  // * testcase 2
  int target = 10;
  std::vector<int> position = {1, 3, 6}, speed = {2, 3, 1};

  printf("Car positions: \n");
  printArr(position);
  printf("Car speeds: \n");
  printArr(speed);

  int fleets = carFleet(target, position, speed);
  std::cout << "Car Fleets: " << fleets << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-car-fleet.cpp -o output && ./output