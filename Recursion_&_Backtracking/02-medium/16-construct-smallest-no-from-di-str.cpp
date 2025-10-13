/*
 * Leetcode - 2375
 * Construct Smallest Number From DI String
 * 
 * You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' 
 * meaning decreasing.
 * 
 * A 0-indexed string num of length n + 1 is created using the following conditions:
 * 
 * num consists of the digits '1' to '9', where each digit is used at most once.
 * - If pattern[i] == 'I', then num[i] < num[i + 1].
 * - If pattern[i] == 'D', then num[i] > num[i + 1].
 
 * Return the lexicographically smallest possible string num that meets the conditions.

 * Example 1
 * input       : pattern = "IIIDIDDD"
 * output      : "123549876"

 * Example 2
 * input       : pattern = "III"
 * output      : "1234"

 * Example 3
 * input       : pattern = "DDD"
 * output      : "4321"

 * https://leetcode.com/problems/construct-smallest-number-from-di-string
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

bool is_matching_pattern(std::string &num, std::string &pattern) {
  for (int i = 0; i <= pattern.size(); ++i) {
    if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
        (pattern[i] == 'D' && num[i] < num[i + 1]))
    {
      return false;
    }
  }
  return true;
}

bool dfs_permutation(std::string num,
                     std::string &cur,
                     std::string &pattern,
                     std::vector<bool> used)
{
  if (cur.size() == num.size()) {
    // std::cout << cur << " -> " << is_matching_pattern(cur, pattern) << std::endl;
    return is_matching_pattern(cur, pattern);
  }

  for (int j = 0; j < num.size(); ++j) {
    if (used[j])
      continue;

    used[j] = true;
    cur.push_back(num[j]);

    if (dfs_permutation(num, cur, pattern, used))
      return true;

    used[j] = false;
    cur.pop_back();
  }
  return false;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------`
// * Find all permutation
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
std::string splitString(std::string pattern) {
  std::string num = "";
  for (int i = 1; i <= pattern.size() + 1; ++i) {
    num += (i + '0');
  }
  // std::cout << "num: " << num << std::endl;

  std::vector<bool> used(num.size());
  std::string ans = "";
  dfs_permutation(num, ans, pattern, used);
  return ans;
}

// * ------------------------- Approach 2: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) (Recursion Stack)

int main(void) {
  // * testcase 1
  // std::string pattern = "III";

  // * testcase 2
  // std::string pattern = "DDD";
  
  // * testcase 3
  std::string pattern = "IIIDIDDD";
  
  std::cout << "pattern string: " << pattern << std::endl;

  std::string ans = splitString(pattern);
  std::cout << "is possible to split: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-construct-smallest-no-from-di-str.cpp -o output && ./output