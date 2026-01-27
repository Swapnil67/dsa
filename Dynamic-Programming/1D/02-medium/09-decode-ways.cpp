/*
 * Leetcode - 91
 * Decode Ways
 * 
 * You have intercepted a secret message encoded as a string of numbers. The message is decoded via
 * the following mapping:
 * 
 * "1" -> 'A'
 * "2" -> 'B'
 * ...
 * "25" -> 'Y'
 * "26" -> 'Z'
 * 
 * However, while decoding the message, you realize that there are many different ways you can decode the 
 * message because some codes are contained in other codes ("2" and "5" vs "25").
 * For example, "11106" can be decoded into:
 * - "AAJF" with the grouping (1, 1, 10, 6)
 * - "KJF" with the grouping (11, 10, 6)
 * 
 * The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
 * 
 * Note: there may be strings that are impossible to decode.
 * 
 * Given a string s containing only digits, return the number of ways to decode it. 
 * If the entire string cannot be decoded in any valid way, return 0.
 * 
 * https://leetcode.com/problems/decode-ways/description/
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Adobe, Oracle

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

int main(void) {
  // * testcase 1
  string s = "bbbab";

  // * testcase 2
  // string s = "cbbd";

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
