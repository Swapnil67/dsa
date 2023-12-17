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

#include<iostream>
using namespace std;

void print(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

vector<int> bruteForce(vector<int> arr) {
  int n = arr.size();
  vector<int> ans;
  vector<int> p_arr;
  vector<int> n_arr;
  for(int i=0; i<n; i++) {
    if(arr[i] >= 0) p_arr.push_back(arr[i]);
    if(arr[i] < 0) n_arr.push_back(arr[i]);
  }
  for(int i=0; i<n/2; i++) {
    ans.push_back(p_arr[i]);
    ans.push_back(n_arr[i]);
  }
  return ans;
}

vector<int> optimalApproach(vector<int> arr) {
  int n = arr.size();
  vector<int> ans (n, 0);
  int posIndex = 0, negIndex = 1;
  for(int i=0; i<n; i++) {
    int val = arr[i];
    if(val >= 0) {
      ans[posIndex] = val;
      posIndex += 2;
    } else {
      ans[negIndex] = val;
      negIndex += 2;
    }
  }
  return ans;
}

int main() {
  // vector<int> nums {-1,1};
  vector<int> nums {3,1,-2,-5,2,-4};
  print(nums);
  // vector<int> ans = bruteForce(nums);
  vector<int> ans = optimalApproach(nums);
  print(ans);
  return 0;
}

// * 3 1 2 
// * -2 -5 -4