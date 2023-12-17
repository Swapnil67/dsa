/*
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 * You may assume that the majority element always exists in the array. 
 * 
 * Example 1:
 * Input: nums = [3,2,3], Output: 3
 * 
 * Example 2: 
 * Input: nums = [2,2,1,1,1,2,2], Output: 2
*/
#include<map>
#include<vector>
#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`


// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> nums) {
  int occurence = nums.size()/2;
  for(int i=0; i<nums.size(); i++) {
    int c = 0;
    for(int j=i; j<nums.size(); j++) {
      if(nums[i] == nums[j]) {
        c++;
      }
    }
    if(c >= occurence) return nums[i];
  }
  return -1;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`

// * TIME COMPLEXITY O(NlogN) + O(N) (for traversing map)
// * SPACE COMPLEXITY O(N)
int betterApproach(vector<int> nums) {
  map<int, int> countMap;
  int occurence = nums.size()/2;

  for (int i = 0; i < nums.size(); i++) {
    countMap[nums[i]]++;
  }
  for(auto it: countMap) {
    // cout<<it.first<<" : "<<it.second<<endl;
    if(it.second >= occurence) {
      return it.first;
    }
  }
  return -1;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------`

// * Moore's Voting Algorithm
/*
* Get the element which does get cancel out
* Re check if that element exists more than n/2 times
*/
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(vector<int> nums) {
  int ele = -1, c = 1;
  for(int i=0; i<nums.size(); i++) {
    if(ele == nums[i]) {
      c++;
    } else {
      c--;
    }
    if(c == 0) {
      c = 1;
      ele = arr[i];
    }
  }

  // * No need to do this if problem states "You may assume that the majority element always exists in the array."
  int occurence = nums.size()/2, c_ele = 0;
  for(int i=0; i<nums.size(); i++) {
    if(nums[i] == ele) {
      c_ele++;
    }
  }
  if(c_ele >= occurence) {
    return ele;
  }

  return -1;
}

int main() {
  // vector<int> nums {2,2,1,1,1,1,2,2};
  vector<int> nums {3,3,4};

  // int op = bruteForce(nums);
  // int op = betterApproach(nums);
  int op = optimalApproach(nums);
  cout<<"Majority element: "<<op;
}