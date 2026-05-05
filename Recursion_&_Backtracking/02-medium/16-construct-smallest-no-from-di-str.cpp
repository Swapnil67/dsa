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
bool is_matching_pattern(string &num, string &pattern) {
  for (int i = 0; i <= pattern.size(); ++i) {
    if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
        (pattern[i] == 'D' && num[i] < num[i + 1])) {
      return false;
    }
  }
  return true;
}

bool dfs_permutation(string &num,
                     string &cur,
                     string &pattern,
                     vector<bool> used)
{
  if (cur.size() == num.size()) {
    // cout << cur << " -> " << is_matching_pattern(cur, pattern) << endl;
    return is_matching_pattern(cur, pattern);
  }

  for (int i = 0; i < num.size(); ++i) {
    if (used[i])
      continue;

    used[i] = true;
    cur.push_back(num[i]);

    if (dfs_permutation(num, cur, pattern, used))
      return true;

    used[i] = false;
    cur.pop_back();
  }
  return false;
}

// * ------------------------- Approach 1: Brute Force Approach -------------------------
// * Find all permutation
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
string smallestNumber(string pattern) {
  string num = "";
  for (int i = 1; i <= pattern.size() + 1; ++i) {
    num += (i + '0');
  }
  // cout << "num: " << num << endl;

  vector<bool> used(num.size());
  string ans = "";
  dfs_permutation(num, ans, pattern, used);
  return ans;
}

// * ------------------------- Approach 2: Optimal Approach -------------------------
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(n) (Recursion Stack)

int main(void) {
  // * testcase 1
  // string pattern = "III";

  // * testcase 2
  string pattern = "DDD";
  
  // * testcase 3
  // string pattern = "IIIDIDDD";
  
  cout << "pattern string: " << pattern << endl;

  string ans = smallestNumber(pattern);
  cout << "is possible to split: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 16-construct-smallest-no-from-di-str.cpp -o output && ./output