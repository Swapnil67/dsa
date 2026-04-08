/*
 * Leetcode - 17
 * Letter Combinations of a Phone Number
 * 
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number 
 * could represent. Return the answer in any order.

 * A mapping of digits to letters (just like on the telephone buttons) is given below. 
 * Note that 1 does not map to any letters.

 * Example 1
 * input  : digits = "23"
 * output : ["ad","ae","af","bd","be","bf","cd","ce","cf"]

 * Example 2
 * input  : digits = "2"
 * output : ["a","b","c"]
 * 
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Oracle, Uber

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

vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                              "mno", "qprs", "tuv", "wxyz"};

vector<string> ans;
void solve(string &digits, int idx, string temp) {
  if (idx >= digits.length()) {
    ans.push_back(temp);
    return;
  }

  string str = digitToChar[digits[idx] - '0'];
  for (int i = 0; i < str.length(); ++i) {
    temp.push_back(str[i]);
    solve(digits, idx + 1, temp);
    temp.pop_back();
  }
}

// * ------------------------- Optimal Approach -------------------------
// * N = length of substring
// * TIME COMPLEXITY O(4^n * n)
// * SPACE COMPLEXITY O(n)
vector<string> letterCombinations(string digits) {
  string temp = "";
  solve(digits, 0, temp);
  return ans;
}

int main(void) {
  string digits = "23";
  cout << "Input digits: " << digits << endl;

  vector<string> ans = letterCombinations(digits);
  cout << "Letter Combinations of a Phone Number: " << endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-letter-combinations-of-a-home-no.cpp -o output && ./output