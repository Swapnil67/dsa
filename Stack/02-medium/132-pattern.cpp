#include <iostream>
#include <vector>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

bool bruteForce(std::vector<int> nums) {
  int n = nums.size();
  for(int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      if (nums[i] < nums[j]) {
        for(int k = j + 1; k < n; ++k) {
          if (nums[i] < nums[k] && nums[k] < nums[j]) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  // std::vector<int> nums = {1, 2, 3, 4};
  // std::vector<int> nums = {3, 1, 4, 2};
  std::vector<int> nums = {-1, 3, 2, 0};
  printArr(nums);

  bool ans = bruteForce(nums);
  std::cout << "132 Pattern: " << ans << std::endl;
  return 0;  
}

// * run the code
// * $CXX --std=c++17 132-pattern.cpp -o output && ./output