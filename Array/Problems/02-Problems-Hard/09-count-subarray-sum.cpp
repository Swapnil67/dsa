/*
 * Count Subarray sum
 * 
 * Example 1:
 * Input: arr = [3,1,2,4], k = 6
 * Output: 2 (subarrays) | [3,1,2], [2,4]

 * Example 2:
 * Input: arr = [1,2,3,-3,1,1,1,4,2,-3], k = 3
 * Output: 8 (subarrays)
*/

#include<map>
#include<vector>
#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

int bruteForce(vector<int> arr, int k) {
  int count = 0;
  int n = arr.size();
  for(int i=0; i<n; i++) {
    int total = 0;
    for(int j=i; j<n; j++) {
      total = total + arr[j];
      if(total == k) {
        count++;
      }
    }
  }
  return count;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`

int prefixSumApproach(vector<int> arr, int k) {
  unordered_map<int, int> mpp;
  mpp[0] = 1;
  int preSum = 0, cnt = 0;
  int n = arr.size();

  for(int i=0; i<n; i++) {
    preSum += arr[i];
    int remove = preSum - k;
    cnt = cnt + mpp[remove];
    mpp[preSum] += 1;
  }
  return cnt;
}

int main() {
  // vector<int> arr = { 3,1,2,4 };
  // int k = 6;
  vector<int> arr = { 1,2,3,-3,1,1,1,4,2,-3 };
  int k = 3;
  // int totalSubarrays = bruteForce(arr, k);
  int totalSubarrays = prefixSumApproach(arr, k);
  cout<<"Total Sub arrays with k = "<<k<<" are "<<totalSubarrays<<endl;
  return 0;
}
