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

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

string to_binary_string(int &num, int &length) {
  string binary = "";
  for (int i = length - 1; i >= 0; --i) {
    binary += (num & (1 << i)) ? '1' : '0';
  }
  return binary;
}

bool dfs(
    string &ans,
    vector<string> &nums,
    unordered_set<string> &st)
{
  if (ans.size() == nums.size()) {
    return (st.count(ans) == 0);
  }

  ans.push_back('0');
  if (dfs(ans, nums, st))
    return true;
  ans.pop_back();

  ans.push_back('1');
  if (dfs(ans, nums, st))
    return true;
  ans.pop_back();

  return false;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
string bruteForce(vector<string>& nums) {
  unordered_set<string> st(nums.begin(), nums.end());
  string ans = "";
  dfs(ans, nums, st);
  return ans;
}

// * ------------------------- Approach 2: Better Approach -------------------------
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n)
string betterApproach(vector<string>& nums) {
  int n = nums.size();
  unordered_set<string> st(nums.begin(), nums.end());
  for (int num = 0; num < n + 1; ++num) {
    string res = to_binary_string(num, n);
    // std::cout << num << " -> " << res << std::endl;
    if (st.find(res) == st.end())
      return res;
  }
  return "";
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
string findDifferentBinaryString(vector<string>& nums) {
  string ans = "";
  for (int i = 0; i < nums.size(); ++i) {
    ans += (nums[i][i] == '0') ? '1' : '0';
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // vector<string> nums = {"01", "10"};

  // * testcase 2
  vector<string> nums = {"00", "01"};

  // * testcase 3
  // vector<string> nums = {"111", "011", "001"};

  cout << "Input: ";
  printArr(nums);

  // string ans = bruteForce(nums);
  string ans = betterApproach(nums);
  // string ans = findDifferentBinaryString(nums);
  cout << "Unique Binary String: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 17-find-unique-binary-str.cpp -o output && ./output