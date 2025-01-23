#include <iostream>
#include <vector>
#include <algorithm>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int carFleet(int target, std::vector<int> &position, std::vector<int> &speed) {
  int n = position.size(), fleet = 1;
  std::vector<std::pair<float, float>> cars(n);
  float f_target =  (float)target;

  for (int i = 0; i < n; ++i) {
    cars[i] = {(float)position[i], (float)speed[i]};
  }
  std::sort(cars.begin(), cars.end(), std::greater<std::pair<float, float>>());

  for (int i = 0; i < n; ++i) {
    printf("%f %f\n", cars[i].first, cars[i].second);
  }
  printf("\n");

  std::pair<float, float> back = cars[0], front;
  for(int i = 1; i < n; ++i) {
    front = cars[i];
    float t1 = (f_target - back.first) / back.second;
    float t2 = (f_target - front.first) / front.second;

    printf("t1: %f, t2: %f\n", t1, t2);

    if(t1 < t2) {
      // * Different fleet starts
      back = front;
      fleet++;
    }
  }

  return fleet;
}

int main() {
  // int target = 12;
  // std::vector<int> position = {10, 8, 0, 5, 3}, speed = {2, 4, 1, 1, 3};

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
// * $CXX --std=c++20 08-car-fleet.cpp -o output && ./output