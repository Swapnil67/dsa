/*
 * Longest Successive Elements
 * A sequence is successive when the adjacent elements of the sequence have a difference of 1.
 * You must return the length of the longest successive sequence.
 * 
 * Example 1:
 * Input: nums = [5,8,3,2,1,4]
 * Output: 5
 * Explanation: The resultant sequence can be 1,2,3,4,5 therefore its length 5
*/

#include<vector>
#include<iostream>
using namespace std;


void print(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

bool linearSearch(vector<int> a, int n) {
  bool found = false;
  for(int i=0; i<a.size(); i++) {
    if(a[i] == n) found = true;
  }
  // cout<<n<<" -> "<<found<<" "<<endl;
  return found;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> nums) {
  int longest = 1;
  for(int i=0; i<nums.size(); i++) {
    int x = nums[i];
    int c = 0;
    while(linearSearch(nums, x) == true) {
      x = x+1;
      c = c+1;
    }
    longest = max(longest, c);
  }
  return longest;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------

// * TIME COMPLEXITY O(nlogn) (sorting) + O(N) (loop)
// * SPACE COMPLEXITY O(1)
int betterApproach(vector<int> nums) {
  sort(nums.begin(), nums.end());
  print(nums);
  int longest = 1, last_smaller = INT_MIN;
  int cur_cnt = 0;
  for(int i=0; i<nums.size(); i++) {
    if(nums[i]-1 == last_smaller) {
      cur_cnt = cur_cnt + 1;
      last_smaller = nums[i];
    }
    else if(nums[i] != last_smaller) {
      // * when new sequence starts
      cur_cnt = 1;
      last_smaller = nums[i];
    }
    cout<<"nums: "<<nums[i]<<" | nums[i]-1: "<<nums[i]-1<<" | "<<last_smaller<<" | cur_cnt: "<<cur_cnt<<endl;
    longest = max(longest, cur_cnt);
  }
  return longest;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// TODO


int main() {
  // vector<int> nums { 5,8,3,2,1,4 };
  // vector<int> nums { 1,2,2,1 };
  vector<int> nums { 15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3 }; // * o/p = 6
  // int longest = bruteForce(nums);
  int longest = betterApproach(nums);
  cout<<"longest "<<longest;

}