/**
 * * Leetcode - 485
 * * Max Consecutive Ones
 * * Given a binary array nums, return the maximum number of consecutive 1's in the array.

 * * Example 1
 * * Input  : 'arr' = [1,1,0,1,1,1]
 * * Output : 3

 * * Example 2
 * * Input  : 'arr' = [1,0,1,1,0,1]
 * * Output : 2

 * * https://leetcode.com/problems/max-consecutive-ones/description/
 * * https://www.naukri.com/code360/problems/maximum-consecutive-ones_3843993
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxConsecutiveOnes(std::vector<int> arr) {
  int n = arr.size(), c = 0, max_ones = 0;
  for (int i = 0; i < n; i++) {
    if(arr[i] == 1) {
      c++;
      max_ones = std::max(c, max_ones);
    } else {
      c = 0;
    }
  }
  return max_ones;
}

int main() {
  std::vector<int> arr = {1, 1, 0, 1, 1, 1};
  // std::vector<int> arr = {1, 0, 1, 1, 0, 1};
  // int max_ones = bruteForce(arr);
  int max_ones = maxConsecutiveOnes(arr);
  std::cout << "Max Consecutive Ones: " << max_ones << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 10-max-consecutive-ones.cpp -o 10-max-consecutive-ones && ./10-max-consecutive-ones