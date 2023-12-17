// * INPUT: arr = [1,2,3,4]
// * OUTPUT: arr = [3,4,1,2]

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

vector<int> rotate(vector<int> nums, int k) {
  vector<int> temp(nums.size());
  int n = temp.size();
  for(int i=0;i<temp.size();i++) {
    temp[(i+k)%n] = nums[i];
  }
  return temp;
}

int main() {
  int k = 2;
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);

  cout<<"Before Rotating: "<<endl;
  print(nums);
  nums = rotate(nums, k);
  cout<<"After Rotating: "<<endl;
  print(nums);

  return 0;
}