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

#include <vector>
#include <iostream>

void printArr(std::vector<std::string> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

std::vector<std::string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                        "mno", "qprs", "tuv", "wxyz"};
std::vector<std::string> ans;
void solve(std::string &digits, int idx, std::string temp) {
  if (idx >= digits.length()) {
    ans.push_back(temp);
    return;
  }

  std::string str = digitToChar[digits[idx] - '0'];
  for (int i = 0; i < str.length(); ++i) {
    temp.push_back(str[i]);

    solve(digits, idx + 1, temp);

    temp.pop_back();
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * N = length of substring
// * TIME COMPLEXITY O(4^n * n)
// * SPACE COMPLEXITY O(n)
std::vector<std::string> letterCombinations(std::string digits) {
  std::string temp = "";
  solve(digits, 0, temp);
  return ans;
}

int main(void) {
  std::string digits = "23";
  std::cout << "Input digits: " << digits << std::endl;

  std::vector<std::string> ans = letterCombinations(digits);
  std::cout << "Letter Combinations of a Phone Number: " << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 09-letter-combinations-of-a-home-no.cpp -o output && ./output