/*
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 * You may assume that the majority element always exists in the array. 
 * 
 * Example 1:
 * Input: nums = [3,2,3], Output: 3
 * 
 * Example 2: 
 * Input: nums = [2,2,1,1,1,2,2], Output: 2
 * 
 * https://www.naukri.com/code360/problems/majority-element_6783241
 * https://leetcode.com/problems/majority-element/description/
*/

#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) {
    int cnt = 0;
    for(int j=0; j<n; j++) {
      if(arr[i] == arr[j]) cnt++;
    }
    if (cnt > (n / 2))
      return arr[i];
  }
  return -1;
}


// * ------------------------- APPROACH 2: Better APPROACH -------------------------`
// * Hashmap
// * TIME COMPLEXITY O(NlogN) + O(N) (for traversing map)
// * SPACE COMPLEXITY O(N)
int betterApproach(std::vector<int> arr) {
  int n = arr.size();
  std::map<int, int> countMap;
  // * O(NlogN)
  for(int i=0; i<n; i++) {
    countMap[arr[i]]++;
  }

  // * O(N)
  for(auto it: countMap) {
    if(it.second > (n/2)) return it.first;
  }
  return -1;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------`
// * Moore's voting algorithm
/*
* Get the element which does get cancel out
* Re check if that element exists more than n/2 times
*/
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int optimalApproach(std::vector<int> arr) {
  int cnt = 0, n = arr.size();
  int ele;

  // * O(N)
  for(int i=0; i<n; i++) {
    if(cnt == 0) {
      ele = arr[i];
      cnt++;
    }
    else if(arr[i] == ele) {
      cnt++;
    }
    else {
      cnt--;
    }
  }

  // * No need to do this if problem states "You may assume that the majority element always exists in the array."
  // * Get the count of ele
  // * O(N)
  int countMaxEle = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == ele) countMaxEle++;
  }
  // * Check if ele is majority element or not
  if(countMaxEle > (n/2)) return ele;
  return -1;
}

int main() {
  // std::vector<int> arr = {3, 2, 3}; // * 3
  std::vector<int> arr = {58, 58, 28, 95, 58, 15, 58, 58 }; // * 58
  // std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2}; // * 2

  std::cout<<"Input Array"<<std::endl;
  printArr(arr);

  // int majorityEle = bruteForce(arr);
  // int majorityEle = betterApproach(arr);
  int majorityEle = optimalApproach(arr);
  std::cout<<"Majority Element "<<majorityEle<<std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02.majority-element.cpp -o 02.majority-element && ./02.majority-element