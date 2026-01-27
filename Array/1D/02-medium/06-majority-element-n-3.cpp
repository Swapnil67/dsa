/*
 * Leetcode - 229
 * Majority Element (N/3)
 * 
 * Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.
 * A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.
 * Note: The floor function returns the number rounded down to the nearest integer.

 * Example 1
 * Input  :  'n' = 9, 'arr' = [2, 2, 1, 3, 1, 1, 3, 1, 1]
 * Output : 1
 * 
 * Example 2
 * Input  :  'n' = 6, 'arr' = [1, 1, 1, 2, 2, 2]
 * Output : [1,2]

 * https://www.naukri.com/code360/problems/majority-element_6915220
 * https://leetcode.com/problems/majority-element-ii/description/
*/

#include <map>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
std::vector<int> bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int occurence = n / 3;

  std::unordered_set<int> st;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (arr[i] == arr[j])
        cnt++;

      if (cnt > occurence) {
        st.insert(arr[i]);
        break;
      }
    }
  }

  std::vector<int> ans(st.begin(), st.end());
  return ans;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Map Data Structure
// * TIME COMPLEXITY O(NlogN) [Ordered map]
// * TIME COMPLEXITY O(N) [Best Case UnOrderd Map] or O(N^2) [Worst Case Unordered Map]
// * SPACE COMPLEXITY O(N)
std::vector<int> betterApproach(std::vector<int> arr) {
  int n = arr.size();
  int occurence = floor(n / 3);
  std::unordered_map<int, int> freq_mp;

  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    freq_mp[arr[i]]++;

    if (freq_mp[arr[i]] > occurence)
      ans.push_back(arr[i]);

    if (ans.size() == 2)
      break;
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Moore's Voting Algorithm
/*
* Get the element which does get cancel out
* Re check if that element exists more than n/2 times
*/
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
std::vector<int> majorityElement(std::vector<int> nums) {
  int n = nums.size();
  int c1 = 0, c2 = 0;
  int ele1 = INT_MIN, ele2 = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (c1 == 0 && nums[i] != ele2) {
      c1 = 1;
      ele1 = nums[i];
    }
    else if (c2 == 0 && nums[i] != ele1) {
      c2 = 1;
      ele2 = nums[i];
    }
    else if (ele1 == nums[i])
      c1++;
    else if (ele2 == nums[i])
      c2++;
    else {
      c1--, c2--;
    }
  }

  c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (ele1 == nums[i])
      c1++;
    if (ele2 == nums[i])
      c2++;
  }
  
  std::vector<int> ans;
  int occurence = std::floor(n / 3);
  if (c1 > occurence)
    ans.push_back(ele1);
  if (c2 > occurence)
    ans.push_back(ele2);

  return ans;
}

int main() {
  // * testcase 1
  // std::vector<int> nums = {2, 2, 1, 3, 1, 1, 3, 1, 1};

  // * testcase 2
  std::vector<int> nums = {1, 1, 1, 2, 2, 2};

  std::cout << "Input Array" << std::endl;
  printArr(nums);

  std::cout << "Majority Element [n/3]" << std::endl;
  // std::vector<int> ans = bruteForce(nums);
  // std::vector<int> ans = betterApproach(nums);
  std::vector<int> ans = majorityElement(nums);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++17 06-majority-element-n-3.cpp -o output && ./output