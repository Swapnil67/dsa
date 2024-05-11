/**
 * * Longest Subarray With Sum K
 * * You are given an array 'a' of size 'n' and an integer 'k'.
 * * Find the length of the longest subarray of 'a' whose sum is equal to 'k'.

 * * Example 1
 * * Input  : 'n’ = 7 ‘k’ = 3, ‘a’ = [1, 2, 3, 1, 1, 1, 1]
 * * Output : 3

 * * https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
 * * https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505
*/

#include<map>
#include<iostream>

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int k) {
  int n = arr.size(), maxLen = INT_MIN;
  for(int i=0; i<n; i++) {
    int sum = 0;
    for(int j=i; j<n; j++) {
      sum += arr[j];
      // std::cout<<"Sum "<<sum<<std::endl;
      if(sum == k) {
        std::cout<<"i "<<arr[i]<<" j "<<arr[j]<<std::endl;
        maxLen = std::max(maxLen, j-i+1);
      }
    }
  }
  return maxLen;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Map Data Structure
// * TIME COMPLEXITY O(NlogN) [Ordered Map]
// * TIME COMPLEXITY O(N) [Best Case UnOrderd Map] or O(N^2) [Worst Case UnOrdered Map]
// * SPACE COMPLEXITY O(N)
int betterApproach(std::vector<int>arr, long long k) {
  long long sum = 0;
  int n = arr.size(), maxLen = 0;
  std::map<long long, int> preSumMap;
  for(int i=0; i<n; i++) {
    sum = sum+arr[i];
    if(sum == k) {
      maxLen = std::max(maxLen, i+1);
    }

    // * Does sumMap contains prefix sum
    int rem = sum - k;
    if (preSumMap.find(rem) != preSumMap.end()) {
      int len = i-preSumMap[rem];
      maxLen = std::max(maxLen, len);
    }

    // * Only save if it does not exists
    if(preSumMap.find(sum) == preSumMap.end()) {
      preSumMap[sum] = i;
    }
  }

  return maxLen;
}


// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Two Pointer
// TODO
int optimalApproach(std::vector<int>arr, long long k) {
  int l=0, r=0, len=0;
  long long sum = 0;
  while(l <= r) {
    sum = sum + arr[l];

    if(sum > k) {
      while(sum < k) {
        sum = sum - arr[r];
        r++;
      }
    }

    if(sum == k) {
      len = max(len, l-r);
    }
    l++;
  }
  return len;
}


int main() {
  int k = 3;
  std::vector<int> arr = { 1,2,3,1,1,1,1 };
  // int longestSubArrLength = bruteForce(arr, k);
  int longestSubArrLength = betterApproach(arr, k);
  std::cout<<"Sub array with max length "<<longestSubArrLength<<std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 12-longest-subarray-with-sum-k.cpp -o 12-longest-subarray-with-sum-k && ./12-longest-subarray-with-sum-k