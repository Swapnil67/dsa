#include<iostream>
#include<map>
using namespace std;

// * INPUT: arr = [1,2,3,1,1,2,1,4,2,3,1,1,1], k = 3
// * OUTPUT: max_len = 3
// * INPUT: arr = [1,2,1,3], k = 2
// * OUTPUT: max_len = 1

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// * Time Complexity: O(N^2)
// * Space Complexity: O(1)
int bruteForceApproach(int arr[], int n, int k) {
  int sum = 0, max_len = -1, count = 0;
  for(int i=0; i<n; i++) {
    sum = 0;
    count = 0;
    for(int j=i; j<n; j++) {
      sum += arr[j];
      count++;
      if(sum == k) {
        max_len = max(j-i+1, max_len);
      }
    }
  }
  return max_len;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`

int betterApproach(int arr[], int n, long long k) {
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;
  for(int i=0; i<n; i++) {
    sum += arr[i];
    if(sum == k) {
      maxLen = max(maxLen, i+1);
    }

    // * Remaining 
    int rem = sum - k;

    // * Check if Remaining exists in our map
    if(preSumMap.find(rem) != preSumMap.end()) {
      // * If yes then compare its length with previous max length
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }
    preSumMap[sum] = i;
  }
  return 0;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------`

// * Time Complexity: O(2N)
// * Space Complexity: O(1)
int optimalApproach(int arr[], int n, long long k) {
  long long sum = arr[0];
  int right = 0, left = 0, maxLen = 0;
  while(right < n) {
    // * Subtract the subarray from the sum
    while(left <= right && sum > k) {
      sum = sum - arr[left];
      left++;
    }
    if(sum == k) {
      maxLen = max(maxLen, right-left+1);
    }
    right++;
    sum = sum + arr[right];
  }
  return maxLen;
}

int main() {
  // int n = 13;
  // int arr[13] = { 1,2,3,1,1,2,1,4,2,3,1,1,1 };
  // long long k = 3;

  // int n = 4;
  // int arr[4] = { 1,2,1,3 };
  // long long k = 2;

  // int n = 5;
  // int arr[5] = { 8,15,17,0,11 };
  // long long k = 17;
  
  int n = 37;
  int arr[37] = { 0, 2, 5, 3, 3, 4, 4, 3, 0, 5, 5, 4, 4, 4, 3, 2, 0, 2, 3, 1, 3, 0, 4, 3, 1, 4, 5, 2, 4, 3, 1, 4, 5, 0, 3, 4, 0 };
  long long k = 52;

  // int max_len = bruteForceApproach(arr, n, k);
  // int max_len = betterApproach(arr, n, k);
  int max_len = optimalApproach(arr, n, k);
  cout<<"Longest Subarray length: "<<max_len;
  return 0;
}