
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

int bruteForce(vector<int> arr) {
}

int optimalApproach(vector<int> arr) {
} 

int main() {
  // vector<int> arr { -2,1,-3,4,-1,2,1,-5,4 };
  vector<int> arr { -3, -5, -6 };
  // int maxs = bruteForce(arr);
  int maxs = optimalApproach(arr);
  cout<<"maxs: "<<maxs<<endl;
  return 0;
}

/*
 * [-2,1,-3,4,-1,2,1,-5,4]  
 * maxi = INT_MIN, -2, 1, 4, 5, 6
 * sum = -2, 0, 1, -2, 0, 4, 3, 5, 6, 1, 5
*/