/*
 * Leetcode - 1929
 * Concatenation of Array
 * Given an integer array nums of length n, you want to create an array ans of length 2n 
 * where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

 * Specifically, ans is the concatenation of two nums arrays.
 * Return the array ans.

 * * Example 1
 * * Input  : nums = [1,2,1]
 * * Output : [1,2,1,1,2,1]
 * 
 * * Example 2
 * * Input  : nums = [1,3,2,1]
 * * Output : [1,3,2,1,1,3,2,1]

 * https://leetcode.com/problems/concatenation-of-array/description/
*/

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

vector<int> getConcatenation(vector<int>& nums) {
  vector<int> ans(begin(nums), end(nums));
  for (auto &num : nums) {
    ans.push_back(num);
  }
  return ans;
}

int main() {
  // * testcase 1
  // vector<int> arr = {1, 2, 1};

  // * testcase 2
  vector<int> arr = {1, 3, 2, 1};

  cout << "Before Concatenation" << endl;
  printArr(arr);

  vector<int> ans = getConcatenation(arr);

  cout<<"After Concatenation"<<endl;
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-concatenation-of-array.cpp -o output && ./output
