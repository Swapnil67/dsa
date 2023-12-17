/*
 * Rearrange Array Elements by Sign
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
 * 
 * Example 1:
 * Input: nums = [3,1,-2,-5,2,-4]
 * Output: [3,-2,1,-5,2,-4]
 * Explanation: The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].

 * Example 2:
 * Input: nums = [-1,1]
 * Output: [1,-1]
 * Explanation: 1 is the only positive integer and -1 the only negative integer in nums.
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// * TIME COMPLEXITY O(N) + O(N) = O(2N)
// * SPACE COMPLEXITY O(N)
vector<int> bruteForce(vector<int> nums) {
  vector<int> p_nums;
  vector<int> n_nums;
  int n = nums.size();
  vector<int> op_arr;

  for(int i=0; i<nums.size(); i++) {
    int val = nums[i];
    if(val >= 0) {
      p_nums.push_back(val);
    } else {
      n_nums.push_back(val);
    }
  }

  // for(int i=0; i<nums.size()/2; i++) {
  //   op_arr.insert(op_arr.begin()+2*i, p_nums[i]);
  //   op_arr.insert(op_arr.begin()+2*i+1, n_nums[i]);
  // }
  // * OR
  for(int i=0; i<n/2; i++) {
    ans.push_back(p_arr[i]);
    ans.push_back(n_arr[i]);
  }
  return op_arr;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`

// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(N)
vector<int> optimalApproach(vector<int> nums) {
  int n = nums.size();
  int posIndex = 0, negIndex = 1;
  vector<int> op_arr(n,0);
  for(int i=0; i<n; i++) {
    int val = nums[i];

    if(val >= 0) {
      // cout<<val<<" => "<<posIndex<<" \n";
      op_arr[posIndex] = val;
      posIndex += 2;
    } else {
      // cout<<val<<" => "<<negIndex<<" \n";
      op_arr[negIndex] = val;
      negIndex += 2;
    }
  }
  return op_arr;
}

int main() {
  // vector<int> nums {3,1,-2,-5,2,-4};
  vector<int> nums {-1,1};
  vector<int> ans;
  // ans = bruteForce(nums);
  ans = optimalApproach(nums);
  print(ans);
  return 0;
}
