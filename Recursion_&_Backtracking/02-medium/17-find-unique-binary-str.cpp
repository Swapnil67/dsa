/*
 * Leetcode - 1980
 * Find Unique Binary String
 * 
 * Given an array of strings nums containing n unique binary strings each of length n, 
 * return a binary string of length n that does not appear in nums. If there are multiple answers, 
 * you may return any of them.
 * 
 * num consists of the digits '1' to '9', where each digit is used at most once.
 * - If pattern[i] == 'I', then num[i] < num[i + 1].
 * - If pattern[i] == 'D', then num[i] > num[i + 1].
 
 * Return the lexicographically smallest possible string num that meets the conditions.

 * Example 1
 * input       : nums = ["01","10"]
 * output      : "11"
 * Explanation : "11" does not appear in nums. "00" would also be correct.
 
 
 * Example 2
 * input       :  nums = ["00","01"]
 * output      : "11"
 * Explanation : "11" does not appear in nums. "10" would also be correct.
 
 * Example 3
 * input       : nums = ["111","011","001"]
 * output      : "101"
 * Explanation : "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

 * https://leetcode.com/problems/find-unique-binary-string/description/
*/

#include <vector>
#include <iostream>
#include <unordered_set>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::string to_binary_string(int &num, int &length) {
  std::string binary;
  for (int i = length - 1; i >= 0; --i) {
    binary += (num & (1 << i)) ? '1' : '0';
  }
  return binary;
}

bool dfs_permutation(
    std::vector<std::string> &nums,
    std::unordered_set<std::string> &st,
    std::string &cur)
{
  if (cur.size() == nums.size()) {
    std::cout << cur << std::endl;
    return st.count(cur) == 0;
  }

  for (int i = 0; i < nums.size(); ++i) {
    cur.push_back('0');
    if (dfs_permutation(nums, st, cur))
      return true;
    cur.pop_back();

    cur.push_back('1');
    if (dfs_permutation(nums, st, cur))
      return true; 
    cur.pop_back();
  }
  return false;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------`
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
std::string bruteForce(std::vector<std::string>& nums) {
  std::unordered_set<std::string> st(nums.begin(), nums.end());
  std::string ans = "";
  dfs_permutation(nums, st, ans);
  return ans;
}

// * ------------------------- Approach 2: Better Approach -------------------------`
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
std::string betterApproach(std::vector<std::string>& nums) {
  int n = nums.size();
  std::unordered_set<std::string> st(nums.begin(), nums.end());
  for (int num = 0; num < n + 1; ++num) {
    std::string res = to_binary_string(num, n);
    if (st.find(res) == st.end())
      return res;
  }
  return "";
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
std::string findDifferentBinaryString(std::vector<std::string>& nums) {
  std::string ans = "";
  for (int i = 0; i < nums.size(); ++i) {
    ans += (nums[i][i] == '0') ? '1' : '0';
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<std::string> nums = {"01", "10"};

  // * testcase 2
  // std::vector<std::string> nums = {"00", "01"};

  // * testcase 3
  std::vector<std::string> nums = {"111", "011", "001"};

  std::cout << "Input: ";
  printArr(nums);

  // std::string ans = bruteForce(nums);
  // std::string ans = betterApproach(nums);
  std::string ans = findDifferentBinaryString(nums);
  std::cout << "Unique Binary String: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 17-find-unique-binary-str.cpp -o output && ./output