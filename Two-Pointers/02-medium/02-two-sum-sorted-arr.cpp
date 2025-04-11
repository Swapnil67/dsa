#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
bool findTwoSum(std::vector<int> arr, int target) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum == target) {
      return true;
    }
    if (sum > target)
      r -= 1;
    else
      l += 1;
  }
  return false;
}

int main() {
  int target = 9;
  std::vector<int> arr = {2, 7, 11, 15};
  printArr(arr);
  // * Note that this does not returs the index
  bool ans = findTwoSum(arr, target);
  std::cout << "Sum found " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++17 02-two-sum-sorted-arr.cpp -o output && ./output