/*
 * Maximum Subarray Sum
 * Find the sum of the subarray (including empty subarray) having 
 * maximum sum among all subarrays
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 1

 * https://www.naukri.com/code360/problems/subarray-sums-i_1467103
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

#include<map>
#include<vector>
#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size(), cnt = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if(sum == k) cnt++;
    }
  }
  return cnt;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Prefix Sum [Map Data Structure]
// * TIME COMPLEXITY O(NlogN) [Ordered Map]
// * TIME COMPLEXITY O(N) [Best Case Unordered Map] or O(N^2) [Worst Case Unordered Map]
// * SPACE COMPLEXITY O(N)
int findAllSubarraysWithGivenSum(std::vector<int> arr, int k) {
  int n = arr.size();
  std::map<int, int> prefixSum;
  prefixSum[0] = 1; // * If first rem comes zero
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    int rem = sum - k;
    if(prefixSum.count(rem)) {
      // std::cout << rem << " " << hash[rem] << std::endl;
      cnt += prefixSum[rem];
    }
    prefixSum[sum]++;
  }
  return cnt;
}

int main() {
  // * testcase 1
  std::vector<int> arr = {3, 1, 2, 4};
  int k = 6;

  // * testcase 2
  // std::vector<int> arr = {1, 2, 3};
  // int k = 3;

  // * testcase 3
  // std::vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
  // int k = 3; 

  printArr(arr);
  // int cnt = bruteForce(arr, k);
  int cnt = findAllSubarraysWithGivenSum(arr, k);
  std::cout << "Number of subarray's with sum " << k << " are " << cnt << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 13-count-subarray-k-sum.cpp -o 13-count-subarray-k-sum && ./13-count-subarray-k-sum