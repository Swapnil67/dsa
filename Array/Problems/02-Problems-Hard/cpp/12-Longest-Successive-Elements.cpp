/*
 * Longest Successive Elements
 * A sequence is successive when the adjacent elements of the sequence have a difference of 1.
 * You must return the length of the longest successive sequence.
 * 
 * Example 1:
 * Input: nums = [5,8,3,2,1,4]
 * Output: 5
 * Explanation: The resultant sequence can be 1,2,3,4,5 therefore its length 5
 * 
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 * https://www.naukri.com/code360/problems/longest-successive-elements_6811740
*/

#include<iostream>
#include<unordered_set>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool linearSearch(std::vector<int> arr, int ele) {
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] == ele) 
      return true;
  }
  return false;
}

// * ------------------------- APPROACH 1 -------------------------`
// * Nested Loop [Linear search]
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int maxC = 0, curC = 0;
  for (int i = 0; i < arr.size(); i++) {
    int cur = arr[i];
    while(linearSearch(arr, cur)) {
      curC++;
      cur += 1;
      maxC = std::max(maxC, curC);
    }
    curC = 0;
  }
  return maxC;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Sort the array and then found longest subsequence
// * TIME COMPLEXITY O(nLogn) + O(n)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> arr) {
  // * O(nlogn)
  std::sort(arr.begin(), arr.end());
  int n = arr.size(), longest = 1, lastSmaller = INT_MIN;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    // std::cout << lastSmaller << " " << arr[i] - 1 << std::endl;
    if (lastSmaller == arr[i] - 1) {
      cnt++;
      lastSmaller = arr[i];
    }
    else if(arr[i] != lastSmaller) {
      lastSmaller = arr[i];
      cnt = 1;
    }
    longest = std::max(longest, cnt);
  }
  return longest;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Find the starting point and then search 
// * TIME COMPLEXITY O(3N)
// * SPACE COMPLEXITY O(N)
int findlongestConsecutive(std::vector<int> &arr) {
  int n = arr.size();
  if(n == 0) return 0;
  int longest = 1;
  std::unordered_set<int> st;
  // * O(N) 
  for (int i = 0; i < n; i++) {
    // * O(1) [Assuming no collsions will occur]
    st.insert(arr[i]);
  }

  // * O(2N)
  for (auto it : st) {
    if (st.find(it - 1) == st.end()) {
      // * You are a first element
      int nextEle = it+1, cnt = 1;
      while(st.find(nextEle) != st.end()) {
        cnt++;
        nextEle += 1;
      }
      longest = std::max(longest, cnt);
    }
    else {
      // * Not a first element
    }
  }
  return longest;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
  // * testcase 2
  std::vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  // * testcase 3
  // std::vector<int> arr = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3}; // * o/p = 6
  printArr(arr);
  // int longestSubsequence = bruteForce(arr);
  // int longestSubsequence = betterApproach(arr);
  int longestSubsequence = findlongestConsecutive(arr);
  std::cout << "Longest subsequence is " << longestSubsequence << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 12-Longest-Successive-Elements.cpp -o 12-Longest-Successive-Elements && ./12-Longest-Successive-Elements