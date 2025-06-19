#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH: Optimal APPROACH -------------------------`

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
// * Shuffling the array using two pointers
std::vector<int> rearrangeArray(std::vector<int> &nums) {
  // * sort the nums
  std::sort(nums.begin(), nums.end());
  std::vector<int> ans;

  int n = nums.size();
  int l = 0, r = n - 1;
  while (ans.size() != n) {
    ans.push_back(nums[l]);
    l++;

    if (l <= r) {
      ans.push_back(nums[r]);
      r--;
    }
  }

  return ans;
}

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
// * Shuffling the array using deque
std::vector<int> rearrangeArray2(std::vector<int> &nums) {
  // * sort the nums
  std::sort(nums.begin(), nums.end());

  // * create a deque with nums
  std::deque q(nums.begin(), nums.end());

  std::vector<int> ans;
  while (q.size() > 0) {
    if(q.size() > 0) {
      ans.push_back(q.back());
      q.pop_back();
    }
    if(q.size() > 0) {
      ans.push_back(q.front());
      q.pop_front();
    }
  }

  return ans;
}

int main() {
  std::vector<int> nums = {1,2,3,4,5};
  printArr(nums);

  std::vector<int> ans = rearrangeArray(nums);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 20-avg-of-neighbours.cpp -o output && ./output

