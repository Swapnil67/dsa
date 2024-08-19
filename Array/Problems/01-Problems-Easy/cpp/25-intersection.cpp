/**
 * * Intersection of Two Arrays

 * * Example 1
 * * Input  : nums1 = [1,2,2,1], nums2 = [2,2]
 * * Output : [2]
 * 
 * * Example 2
 * * Input  : nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * * Output : [9,4]
 * * Explanation: [4,9] is also accepted.

 * * https://leetcode.com/problems/intersection-of-two-arrays/description/
*/

#include<set>
#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> num1, std::vector<int> num2) {
  std::set<int> st;
  int n1 = num1.size(), n2 = num2.size();
  for (int i = 0; i < n1; ++i) {
    bool found = false;
    for (int j = 0; j < n2; ++j) {
      if (num1[i] == num2[j])
        found = true;
    }
    if(found) 
      st.insert(num1[i]);
  }
  std::vector<int> ans(st.begin(), st.end());
  return ans;
}

std::vector<int> betterApproach(std::vector<int> num1, std::vector<int> num2) {
  std::set<int> hashSet;
  std::vector<int> ans;

  int n1 = num1.size(), n2 = num2.size();
  if(n1 > n2) {
    betterApproach(num2, num1);
  }

  // * fill the smaller array into hashset
  for (int i = 0; i < n1; ++i) {
    hashSet.insert(num1[i]);
  }

  // * loop over second array
  for (int i = 0; i < n2; ++i) {
    if(hashSet.find(num2[i]) != hashSet.end()) {
      ans.push_back(num2[i]);
      hashSet.erase(num2[i]);
    }
  }

  return ans;
}



int main() {
  // * testcase 1
  std::vector<int> num1 = {4, 9, 5};
  std::vector<int> num2 = {9, 4, 9, 8, 4};

  // * testcase 2
  // std::vector<int> num1 = {1, 2, 2, 1};
  // std::vector<int> num2 = {2, 2};

  std::cout << "num1 = ";
  printArr(num1);
  std::cout << "num2 = ";
  printArr(num2);

  // std::vector<int> ans = bruteForce(num1, num2);
  std::vector<int> ans = betterApproach(num1, num2);
  std::cout << "------------ Intersection ----------" << std::endl;
  printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 25-intersection.cpp -o output && ./output