/**
 * * Can Place Flowers
 * * You have a long flowerbed in which some of the plots are planted, and some are not.
 * * However, flowers cannot be planted in adjacent plots.
 * 
 * * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty,
 * * and an integer n, return true if n new flowers can be planted in the flowerbed without violating the 
 * * no-adjacent-flowers rule and false otherwise.

 * * Example 1
 * * Input  : flowerbed = [1,0,0,0,1], n = 1
 * * Output : true

 * * Example 2
 * * Input  : flowerbed = [1,0,0,0,1], n = 2
 * * Output : false

 * * https://leetcode.com/problems/can-place-flowers/description/
*/

#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool canPlaceFlowers(std::vector<int> flowerbed, int flowers) {
  int n = flowerbed.size();
  for (int i = 0; i < n; i++) {
    bool left = i == 0 || flowerbed[i - 1] == 0;
    bool right = i == (n - 1) || flowerbed[i + 1] == 0;

    if(left && right && flowerbed[i] == 0) {
      flowerbed[i] = 1;
      flowers--;
    }
  }

  return flowers <= 0;
}

int main() {
  // * testcase 1
  // int newPlots = 1;
  // std::vector<int> flowerbed = {0};
  // * testcase 2
  int newPlots = 1;
  std::vector<int> flowerbed = {0, 1, 0, 1, 0, 1, 0, 0};
  // * testcase 3
  // int newPlots = 2;
  // std::vector<int> flowerbed = {1, 0, 0, 0, 1};
  // * testcase 4
  // int newPlots = 1;
  // std::vector<int> flowerbed = {0, 1, 0};
  // * testcase 5
  // int newPlots = 1;
  // std::vector<int> flowerbed = {0, 0, 1, 0, 1};

  printArr(flowerbed);
  bool ans = canPlaceFlowers(flowerbed, newPlots);
  std::cout << "Can place flowers " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 15-can-place-flowers.cpp -o 15-can-place-flowers && ./15-can-place-flowers
