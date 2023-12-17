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

#include<iostream>
using namespace std;

void print(vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

vector<int> bruteForce(vector<int> arr) {
}

vector<int> optimalApproach(vector<int> arr) {
}

int main() {

  // vector<int> nums { 1, 2, 3, 2 };
  // vector<int> nums { 1, 2, 2, 1 };
  vector<int> nums { 5, 4, 3 };
  vector<int> ans;
  // ans = bruteForce(nums);
  
  // ans = optimalApproach(nums);
  // sort(ans.begin(), ans.end());
  // print(ans);
  return 0;
}