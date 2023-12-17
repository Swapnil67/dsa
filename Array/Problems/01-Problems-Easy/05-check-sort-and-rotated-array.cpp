// * INPUT: nums = [3,4,5,1,2] | Output = true
// * INPUT: nums = [2,1,3,4] | Output = false

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

bool checkSortedAndRotated(vector<int> nums) {
  int count = 0;
  int n = nums.size();
  for(int i=1; i<n; i++) {
    if(nums[i-1] > nums[i]) {
      count++;
    }
  }

  if(nums[n-1] > nums[0]) {
    count++;
  }

  return count<=1;
}

int main() {
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(1);
  nums.push_back(2);

  // * Not sorted or rotated
  // nums.push_back(2);
  // nums.push_back(1);
  // nums.push_back(3);
  // nums.push_back(4);

  print(nums);
  bool check = checkSortedAndRotated(nums);
  cout<<"Is Sorted & Rotated: "<<check;
  return 0;
}

