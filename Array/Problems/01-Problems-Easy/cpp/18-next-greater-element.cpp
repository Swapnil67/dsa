/**
 * * Next Greater Element
 * * The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
 * * You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

 * * For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater
 * * element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

 * * Example 1
 * * Input  : nums1 = [4,1,2], nums2 = [1,3,4,2]
 * * Output : [-1,3,-1]

 * * Example 2
 * * Input  : nums1 = [2,4], nums2 = [1,2,3,4]
 * * Output : [3,-1]

 * * https://leetcode.com/problems/next-greater-element-i/description/
*/

#include<stack>
#include<iostream>
#include<unordered_map>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N1) [For answer only]
std::vector<int> bruteForce(std::vector<int> nums1, std::vector<int> nums2) {
  int n1 = nums1.size(), n2 = nums2.size();
  std::vector<int> ans;
  for (int i = 0; i < n1; i++) {
    bool foundGreater = false;
    // * get j to such that nums1[i] == nums2[j]
    int j = 0;
    while(nums1[i] != nums2[j]) j++;
    for (;j < n2; j++) {
      if(nums2[j] > nums1[i]) {
        // std::cout << nums1[i] << " " << nums2[j] << std::endl;
        foundGreater = true;
        ans.push_back(nums2[j]);
        break;
      }
    }
    if(!foundGreater) {
      ans.push_back(-1);
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Stack Data structure
// * TIME COMPLEXITY O(N1 + N2)
// * SPACE COMPLEXITY O(N1) [For answer only]
std::vector<int> nextGreaterElements(std::vector<int> nums1, std::vector<int> nums2) {
  int n1 = nums1.size(), n2 = nums2.size();
  std::vector<int> ans(n1, -1);

  // * Step 1: Create the index map of nums1 elements such that nums1[i] == nums2[j]
  std::unordered_map<int, int> indexMap;
  for (int i = 0; i < n1; i++) {
    indexMap[nums1[i]] = i;
  }

  // * Step 2: Use stack to find the next greater element
  std::stack<int> st;
  for (int i = 0; i < n2; i++) {
    int cur = nums2[i];
    while(!st.empty() && cur > st.top()) {
      int pushIdx = indexMap[st.top()];
      // std::cout << pushIdx << std::endl;
      ans[pushIdx] = cur;
      st.pop();
    }
    // printArr(ans);
    // * Check if cur exists in nums1
    if (indexMap.find(cur) != indexMap.end()) {
      st.push(cur);
    }
  }

  return ans;
}

int main() {
  std::vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
  // std::vector<int> nums1 = {2, 4}, nums2 = {1, 2, 3, 4};
  // std::vector<int> nums1 = {4, 2, 1}, nums2 = {2, 1, 3, 4};
  std::cout<<"Nums 1: ";
  printArr(nums1);
  std::cout<<"Nums 2: ";
  printArr(nums2);
  // std::vector<int> ans = bruteForce(nums1, nums2);
  std::vector<int> ans = nextGreaterElements(nums1, nums2);
  printArr(ans);
}

// * Run the code
// * g++ --std=c++17 18-next-greater-element.cpp -o 18-next-greater-element && ./18-next-greater-element