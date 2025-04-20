#include<vector>
#include<deque>
#include<iostream>
#include <numeric>
#include <climits>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int bruteForce(std::vector<int> arr, int k, int threshold) {
  int n = arr.size();
  int ans = 0;
  for(int i = 0; i <= n - k; ++i) {
    int cur_sum = 0;
    for (int j = i; j < i + k; ++j) {
      cur_sum += arr[j];
    }
    if (cur_sum / k >= threshold)
      ans += 1;
  }
  return ans;
}

int numOfSubarrays(std::vector<int> &arr, int &k, int &threshold) {
  int n = arr.size();
  int ans = 0, i = 0, j = 0;
  long long cur_sum = 0;
  while (j < n) {
    cur_sum += arr[j];

    if(j - i + 1 > k) {
      cur_sum -= arr[i];
      i += 1;
    }
    
    if(j - i + 1 == k) {
      if ((cur_sum / k) >= threshold)
        ans += 1;
    }

    j += 1;
  }
  return ans;
}

int numOfSubarrays2(std::vector<int> &arr, int &k, int &threshold) {
  int n = arr.size();
  int ans = 0, i = 0, j = 0;
  long long cur_sum = 0;
  long long target_sum = k * threshold;
  for(int i = 0; i < n; ++i) {
    cur_sum += arr[i];
    if (i < k - 1)
      continue;

    if(i > k - 1) {
      cur_sum -= arr[i - k];
    }
    if (cur_sum >= target_sum)
      ans += 1;
  }
  return ans;
}

int main() {
  // * testcase 1
  // int k = 3, threshold = 4;
  // std::vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
  // * testcase 1
  int k = 3, threshold = 5;
  std::vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  std::cout << "k = " << k << " & threshold = " << threshold << std::endl;
  std::cout << "Input Array " << std::endl;
  printArr(arr);
  // int ans = bruteForce(arr, k, threshold);
  int ans = numOfSubarrays2(arr, k, threshold);
  std::cout << "Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output