/*
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 * You may assume that the majority element always exists in the array. 
 * 
 * Example 1:
 * Input: nums = [3, 2, 3], Output: 3
 * 
 * Example 2:
 * Input: nums = [2, 2, 1, 1, 1, 2, 2], Output: 2
*/

#include<map>
#include<iostream>
using namespace std;

int bruteForce(vector<int> arr) {
}

int betterApproach(vector<int> arr) {
}

int optimalApproach(vector<int> arr) {
}

int main() {
  // * 2 2 1 1 2 2 1
  // vector<int> arr = { 2, 2, 1, 1, 2, 2, 1 };
  vector<int> arr = { 3, 2, 3 };
  // int majorELe = bruteForce(arr);
  // int majorELe = betterApproach(arr);
  // int majorELe = optimalApproach(arr);
  cout<<"majorELe: "<<majorELe<<endl;
  return 0;
}

