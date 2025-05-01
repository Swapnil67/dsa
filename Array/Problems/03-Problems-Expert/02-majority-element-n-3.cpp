/**
 * * Majority Element (N/3)
 * * Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.
 * * A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.
 * * Note: The floor function returns the number rounded down to the nearest integer.

 * * Example 1
 * * Input  :  'n' = 9, 'arr' = [2, 2, 1, 3, 1, 1, 3, 1, 1]
 * * Output : 1
 * 
 * * Example 2
 * * Input  :  'n' = 6, 'arr' = [1, 1, 1, 2, 2, 2]
 * * Output : [1,2]

 * * https://www.naukri.com/code360/problems/majority-element_6915220
 * * https://leetcode.com/problems/majority-element-ii/description/
*/

#include <map>
#include <cmath>
#include <iostream>
#include <vector>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
std::vector<int> bruteForce(std::vector<int> arr) {
  int n = arr.size(), occurence = n/3;
  std::set<int> majoritySet;
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if(arr[i] == arr[j]) cnt++;
      if(cnt > occurence) {
        majoritySet.insert(arr[i]);
        break;
      }
    }
  }
  for (auto ele : majoritySet) {
    ans.push_back(ele);
  }
  return ans;
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Map Data Structure
// * TIME COMPLEXITY O(NlogN) [Ordered Map]
// * TIME COMPLEXITY O(N) [Best Case UnOrderd Map] or O(N^2) [Worst Case UnOrdered Map]
// * SPACE COMPLEXITY O(N)
std::vector<int> betterApproach(std::vector<int> arr) {
  int n = arr.size();
  int occurence = floor(n/3);
  std::map<int, int> eleCountMap;
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    eleCountMap[arr[i]]++;
    if (eleCountMap[arr[i]] > occurence)
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
std::vector<int> optimalApproach(std::vector<int> arr) {
  int n = arr.size();
  int c1 = 0, c2 = 0;
  int ele1 = INT_MIN, ele2 = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (c1 == 0 && arr[i] != ele2) {
      c1 = 1;
      ele1 = arr[i];
    }
    else if (c2 == 0 && arr[i] != ele1) {
      c2 = 1;
      ele2 = arr[i];
    }
    else if (ele1 == arr[i])
      c1++;
    else if (ele2 == arr[i])
      c2++;
    else {
      c1--, c2--;
    }
  }

  c1 = 0, c2 = 0;
  int occurence = std::floor(n/3);
  for (int i = 0; i < n; i++) {
    if (ele1 == arr[i])
      c1++;
    if (ele2 == arr[i])
      c2++;
  }
  std::vector<int> ans;

  if (c1 > occurence)
    ans.push_back(ele1);
  if (c2 > occurence)
    ans.push_back(ele2);

  return ans;
}

int main() {
  std::vector<int> arr = {2, 2, 1, 3, 1, 1, 3, 1, 1};
  // std::vector<int> arr = {1, 1, 1, 2, 2, 2};
  std::cout<<"Input Array"<<std::endl;
  printArr(arr);
  std::cout<<"Majority Element [n/3]"<<std::endl;
  // std::vector<int> ans = bruteForce(arr);
  // std::vector<int> ans = betterApproach(arr);
  std::vector<int> ans = optimalApproach(arr);
  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-majority-element-n-3.cpp -o 02-majority-element-n-3 && ./02-majority-element-n-3