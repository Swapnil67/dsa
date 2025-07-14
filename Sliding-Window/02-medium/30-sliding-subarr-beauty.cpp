/**
 * * First Negative In Every Window
 * * You have been given an array of integers 'ARR' of size 'N'. You are also provided with a positive integer 'K'.
 * * Your task is to find the first negative element in every window (contiguous subarray) of length 'K'. 
 * * If there is no negative element in a window, then print 0 for that window.
 * 
 * * Example 1
 * * Input  : nums = [5, -3, 2, 3, -4] and k = 2
 * * Output : [-3 -3 0 -4]
 * 
 * * Example 2
 * * Input  : nums = [8 1 -2 2 -3 6 8 -1] and k = 3
 * * Output : [-2 -2 -2 -3 -3 -1 ]
 * 
 * * https://www.naukri.com/code360/problems/first-negative-in-every-window_759333
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

std::vector<int> bruteForce(std::vector<int> &nums, int k, int x) {
  std::vector<int> ans;
  int n = nums.size();

  // * O(N * K)
  for(int i = 0; i <= n - k; ++i) {
    std::vector<int> temp;
    for (int j = i; j < (i + k); ++j) {
      temp.push_back(nums[j]);
    }

    if (temp.size() >= x) {
      // * O(KlogK)
      std::sort(temp.begin(), temp.end());
      int val = temp[x - 1] < 0 ? temp[x - 1] : 0;
      ans.push_back(val);
    } else {
      ans.push_back(0);
    }
  }

  return ans;
}



std::vector<int> getSubarrayBeauty(std::vector<int> &nums, int k, int x) {
  int n = nums.size();
  std::vector<int> ans;

  if (n == 0)
    return ans;

  // * map[number, count]
  std::unordered_map<int, int> mp;

  int i = 0, j = 0;
  while (j < n) {
    mp[nums[j]]++;
    
    if ((j - i + 1) > k) {
      mp[nums[i]]--;
      i++;
    }

    if ((j - i + 1) == k) {
      int f = 0, val = 0;
      for (int i = -50; i <= -1; ++i) {
        f += mp[i];
        if (f >= x) {
          val = i;
          break;
        }
      }
      ans.push_back(val);
    }

    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 3, x = 2;
  // std::vector<int> nums = {1, -1, -3, -2, 3};

  // * testcase 2
  // int k = 2, x = 2;
  // std::vector<int> nums = {-1, -2, -3, -4, -5};

  // * testcase 3
  // int k = 2, x = 1;
  // std::vector<int> nums = {-3, 1, 2, -3, 0, -3};

  // * testcase 3
  int k = 9, x = 4;
  std::vector<int> nums = {-14, 9, 13, -26, 47, -39, -49, -14, 29};

  std::cout << "k = " << k << ", x = " << x << std::endl;
  std::cout << "Input Array" << std::endl;
  printArr(nums);
  
  // std::vector<int> ans = bruteForce(nums, k, x);
  std::vector<int> ans = getSubarrayBeauty(nums, k, x);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 30-sliding-subarr-beauty.cpp -o output && ./output 