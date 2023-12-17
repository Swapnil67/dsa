/*
 * Find the sum of the subarray (including empty subarray) having 
 * maximum sum among all subarrays
 * 
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.

 * Example 2:
 * Input: nums = [-3, -5, -6]
 * Output: 0
 * Explanation: The subarray [-3, -5, -6] has the largest sum 0.
*/

#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

int bruteForce(vector<int> arr) {
  int n = arr.size();
  int maxs = INT_MIN;
  for(int i=0; i<n; i++) {
    int sum = 0;
    for(int j=i; j<n; j++) {
      // cout<<sum<<" ";
      sum += arr[j];
      // cout<<arr[i]<<" "<<arr[j]<<endl;
      maxs = max(maxs, sum);
    }
    cout<<endl;
  }
  cout<<maxs<<endl;
  return -1;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------`

// * kadane's Algorithm
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)

/*
 * [-2,1,-3,4,-1,2,1,-5,4]  
 * maxi = INT_MIN, -2, 1, 4, 5, 6
 * sum = -2, 0, 1, -2, 0, 4, 3, 5, 6, 1, 5
*/
int optimalApproach(vector<int> arr) {
  int n = arr.size();
  if(n == 0) return 0;

  int maxi = INT_MIN, sum = 0;
  int tstart = 0, start = 0, end = 0;

  for(int i=0; i<n; i++) {
    if(sum == 0) tstart = i;
    sum = sum + arr[i];
    // cout<<"sum "<<sum<<" ";
    if(sum > maxi) {
      maxi = sum;
      start = tstart, end = i;
    }
    if(sum < 0) {
      sum = 0;
    }
  }

  if(maxi < 0) maxi = 0;
  cout<<"Start "<<start<<" & "<<"End "<<end<<endl;
  return maxi;
}

int main() {
  // vector<int> arr { 1, 2, 7, -4, 3, 2, -10, 9, 1 };
  vector<int> arr { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  // int op = optimalApproach(arr);
  int op = bruteForce(arr);
  cout<<"\nMaximum subarray sum: "<<op;
}
