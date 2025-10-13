/*
 * Leetcode - 1849
 * Splitting a String Into Descending Consecutive Values
 * 
 * Check if we can split s into two or more non-empty substrings such that the numerical values of the substrings are 
 * in descending order and the difference between numerical values of every two adjacent substrings is equal to 1.

 * For example, the string s = "0090089" can be split into ["0090", "089"] with numerical values [90,89]. 
 * The values are in descending order and adjacent values differ by 1, so this way is valid.

 * Another example, the string s = "001" can be split into ["0", "01"], ["00", "1"], or ["0", "0", "1"].
 * However all the ways are invalid because they have numerical values [0,1], [0,1], and [0,0,1] respectively, 
 * all of which are not in descending order.

 * Return true if it is possible to split s​​​​​​ as described above, or false otherwise.

 * Example 1
 * input       : s = "1234"
 * output      : false
 * Explanation : There is no valid way to split s.

 * Example 2
 * input       : s = "050043"
 * output      : true
 * Explanation : s can be split into ["05", "004", "3"] with numerical values [5,4,3].
 *               The values are in descending order with adjacent values differing by 1.

 * Example 3
 * input       : s = "9080701"
 * output      : false
 * Explanation : There is no valid way to split s.
 * 
 * https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/
*/

#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

bool isValid(std::vector<long long> &arr) {
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] != arr[i - 1] - 1)
      return false;
  }
  return arr.size() > 1;
}

bool dfs(std::string &s, int i, std::vector<long long> &splits) {
  if (i >= s.size()) {
    printArr(splits);
    return isValid(splits);
  }
  
  unsigned long long num = 0;
  for (int j = i; j < s.size(); ++j) {
    num = num * 10 + (s[j] - '0');
    splits.push_back(num);

    if (dfs(s, j + 1, splits))
      return true;

    splits.pop_back();
  }

  return false;
}

bool dfs2(std::string &s, int i, unsigned long long prev) {
  if (i == s.size()) {
    return true;
  }
  
  unsigned long long num = 0;
  for (int j = i; j < s.size(); ++j) {
    num = num * 10 + (s[j] - '0');

    if (num + 1 == prev && dfs2(s, j + 1, num))
      return true;

    if (num >= prev)
      break;
  }

  return false;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------`
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
bool bruteForce(std::string s) {
  std::vector<long long> splits;
  return dfs(s, 0, splits);
}

// * ------------------------- Approach 2: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
bool splitString(std::string s) {
  int n = s.size();
  unsigned long long val = 0;
  for (int i = 0; i < n - 1; ++i) {
    val = val * 10 + (s[i] - '0');
    if (dfs2(s, i + 1, val)) {
      return true;
    }
  }

  return false;
}

int main(void) {
  // * testcase 1
  std::string s = "1234";
  
  // * testcase 2
  // std::string s = "050043";
  
  // * testcase 3
  // std::string s = "9080701";

  std::cout << "numerical string: " << s << std::endl;

  // bool ans = bruteForce(s);
  bool ans = splitString(s);
  std::cout << "is possible to split: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 15-Splitting-a-str-into-desc-consecutive-values.cpp -o output && ./output