/*
 * Leetcode - 1552
 * Magnetic Force Between Two Balls
 * 
 * 
 * In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in
 * his new invented basket. Rick has n empty baskets, the ith basket is at position[i], 
 * Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between 
 * any two balls is maximum.
 * 
 * Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
 * 
 * Given the integer array position and the integer m. Return the required force.
 * 
 * 
 * 
 * https://leetcode.com/problems/magnetic-force-between-two-balls/description/
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int maxDistance(std::vector<int> &position, int m) {

}

int main(void) {
  // * testcase 1
  int m = 3;
  std::vector<int> positions = {1, 2, 3, 4, 7};
  
  // * testcase 2
  // int m = 2;
  // std::vector<int> positions = {5, 4, 3, 2, 1, 1000000000};

  std::cout << "m: " << m << std::endl;
  std::cout << "Positions: ";
  printArr(positions);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 30-magnetic-force-bw-two-balls.cpp -o output && ./output
