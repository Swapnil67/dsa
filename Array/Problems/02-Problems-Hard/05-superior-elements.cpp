/*
 * Superior Elements
 * An element is called a Superior Element if it is greater than all the elements present to its right.
 * You must return an array all Superior Elements in the array ‘a’.
 * 
 * Example 1:
 * Input: nums = [1,2,3,2]
 * Output: [3, 2]

 * Example 2:
 * Input: nums = [5,4,3]
 * Output: [5,4,3]
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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N) (In worst case)
vector<int> bruteForce(vector<int> nums) {
  vector<int> ans;

  for(int i=0; i<nums.size(); i++) {
    bool is_superior = true;
    for(int j=i+1; j<nums.size(); j++) {
      // cout<<"j "<<nums[j]<<" i "<<nums[i]<<endl;
      if(nums[j] >= nums[i]) {
        is_superior = false;
        break;
      }
    }
    if(is_superior) {
      ans.push_back(nums[i]);
    }
  }

  return ans;
}


// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`
// * Using Back Iteration
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) (In worst case)
vector<int> optimalApproach(vector<int> nums) {
  int maxi = INT_MIN;
  vector<int> ans;
  for(int i=nums.size()-1; i>=0; i--) {
    // cout<<"nums[i] "<<nums[i]<<" maxi "<<maxi<<endl;
    if(nums[i] > maxi) {
      ans.push_back(nums[i]);
      maxi = nums[i];
    }
  }
  return ans;
}

int main() {
  vector<int> nums {1,2,3,2};
  // vector<int> nums {1,2,2,1};
  // vector<int> nums {5,4,3};
  vector<int> ans;

  // * Approach 1
  // ans = bruteForce(nums);
  // sort(ans.begin(), ans.end());
  // print(ans);

  // * Approach 2
  ans = optimalApproach(nums);
  sort(ans.begin(), ans.end());
  print(ans);
}