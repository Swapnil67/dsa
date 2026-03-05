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

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

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

bool matchesPattern(string num, string &pattern) {
  for (int i = 0; i < pattern.size(); ++i) {
    if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
        (pattern[i] == 'D' && num[i] < num[i + 1]))
    {
      return false;
    }
  }
  return true;
}

// * ------------------------- Approach 1: Brute Force Approach ---------------------
// * Find all permutation
// * TIME COMPLEXITY O(n!)
// * SPACE COMPLEXITY O(n) (Recursion Stack)
// string bruteForce(string pattern) {
// * Go to Recursion folder
// }

// * ------------------------- Approach 2: Better Approach -------------------------
// * CPP STL
// * TIME COMPLEXITY O(n * O(n+1)!)
// * SPACE COMPLEXITY O(n)
string betterApproach(string pattern) {
  int n = pattern.size();
  string num = "";
  for (int i = 1; i <= n + 1; ++i) {
    num.push_back(i + '0');
  }

  while (!matchesPattern(num, pattern)) { // * O(n)
    next_permutation(begin(num), end(num)); // * O(n+1)! [Permutation TC]
  }
  return num;
}

// * ------------------------- Approach 3: Optimal Approach -------------------------
// * we want to place smaller numbers as early as possible
// *  When we encounter a sequence of 'D's, we need to reverse the order of those numbers.
// * Same as find permutation
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
string smallestNumber(string pattern) {
  stack<int> st;
  string ans = "";
  int n = pattern.size();
  for (int i = 1; i <= n; ++i) {
    st.push(i);
    if (pattern[i - 1] == 'I') {
      while (!st.empty()) {
        ans.push_back(st.top() + '0');
        st.pop();
      }
    }
  }

  st.push(n + 1);
  while (!st.empty()) {
    ans.push_back(st.top() + '0');
    st.pop();
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // string pattern = "III";

  // * testcase 2
  // string pattern = "DDD";
  
  // * testcase 3
  string pattern = "IIIDIDDD";
  
  cout << "pattern string: " << pattern << endl;

  string ans = betterApproach(pattern);
  // string ans = smallestNumber(pattern);
  cout << "Smallest Number From DI String: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 24-construct-smallest-no-from-di-str.cpp -o output && ./output