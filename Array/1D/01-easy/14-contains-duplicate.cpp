/**
 * * Leetcode - 217
 * * Contains Duplicate
 * * Given an integer array nums, return true if any value appears at least twice in the array, and return false if
 * * every element is distinct.

 * * Example 1
 * * Input  : nums = [1,2,3,1]
 * * Output : true

 * * Example 2
 * * Input  : nums = [1,2,3,4]
 * * Output : false

 * * https://leetcode.com/problems/contains-duplicate/description/
*/

#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Hashmap to Count
// * TIME COMPLEXITY O(N) + O(N)
// * SPACE COMPLEXITY O(N)
bool bruteForce(vector<int> &nums) {
  unordered_map<int, int> countMap;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    countMap[nums[i]]++;
  }

  // * loop over count map
  for(auto it : countMap) {
    if(it.second > 1) {
      return true;
    }
  }
  return false;
} 

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------`
// * Set Data Structure
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
bool containsDuplicate(vector<int> &nums) {
  set<int> st;
  for (int i = 0; i < nums.size(); i++) {
    if (st.find(nums[i]) != st.end()) {
      return true;
    }
    st.insert(nums[i]);
  }
  return false;
}

int main() {
  // vector<int> arr = {1, 2, 3, 4};
  vector<int> arr = {1, 2, 3, 1};
  cout<<"Input Array "<<endl;
  printArr(arr);
  bool isDuplicate = bruteForce(arr);
  // bool isDuplicate = containsDuplicate(arr);
  cout<<"Does array contains duplicate "<<isDuplicate<<endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 14-contains-duplicate.cpp -o 14-contains-duplicate && ./14-contains-duplicate