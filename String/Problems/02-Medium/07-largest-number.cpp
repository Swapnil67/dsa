/*
 * Largest Number
 * Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
 * Since the result may be very large, so you need to return a string instead of an integer.
 * 
 * Example 1:
 * Input: nums = [10,2]
 * Output: "210"
 * 
 * Example 2:
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"

 * https://leetcode.com/problems/largest-number/description/
*/

#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool compare(std::string n1, std::string n2) {
    std::string c1 = n1 + n2;
    std::string c2 = n2 + n1;
    if(c1 > c2) 
        return true;
    return false;
}

void merge(std::vector<std::string> &strVec, int low, int mid, int high) {
  std::vector<std::string> temp;
  int l = low, r = mid + 1;
  while(l <= mid && r <= high) {
    if(compare(strVec[l], strVec[r])) {
      temp.push_back(strVec[l++]);
    }
    else {
      temp.push_back(strVec[r++]);
    }
  }

  while(l <= mid) {
    temp.push_back(strVec[l++]);
  }
  while(r <= high) {
    temp.push_back(strVec[r++]);
  }

  for (int i = low; i <= high; ++i) {
    strVec[i] = temp[i - low];
  }
}

void mergeSort(std::vector<std::string> &strVec, int l, int r) {
  if (l == r)
    return;
  int m = (l + r) / 2;
  mergeSort(strVec, l, m);
  mergeSort(strVec, m + 1, r);
  merge(strVec, l, m, r);
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Using nested loop & swapping
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
std::string bruteForce(std::vector<int> nums) {
  int n = nums.size();

  std::vector<std::string> strVec(n);
  for (int i = 0; i < n; ++i) {
    strVec[i] = std::to_string(nums[i]);
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if(!compare(strVec[i], strVec[j])) {
        swap(strVec[i], strVec[j]);
      }
    }
  }

  std::string ans = "";
  for (std::string s : strVec) {
    ans += s;
  }

  return std::to_string(std::stoi(ans));
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Using Merge Sort
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
std::string largestNumber(std::vector<int> nums) {
  int n = nums.size();

  std::vector<std::string> strVec(n);
  for (int i = 0; i < n; ++i) {
    strVec[i] = std::to_string(nums[i]);
  } 

  mergeSort(strVec, 0, n-1);

  std::string ans = "";
  for (std::string s : strVec) {
    ans += s;
  }

  if(ans[0] == '0')
      return "0";
    
  return ans;
}

int main() {
  std::vector<int> nums = {3, 30, 34, 5, 9};
  // std::vector<int> nums = {10, 2};
  // std::vector<int> nums = {8308, 8308, 830};
  printArr(nums);
  // std::string s = bruteForce(nums);
  std::string s = largestNumber(nums);
  std::cout << "Largest Number : " << s << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 07-largest-number.cpp -o output && ./output
