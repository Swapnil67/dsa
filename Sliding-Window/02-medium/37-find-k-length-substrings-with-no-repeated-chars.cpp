/*
 * Leetcode - 
 * Find K-Length Substrings With No Repeated Characters
 * 
 * Given a string s and an integer k, return the number of substrings in s of length k with no repeated characters.
 * 
 * Example 1
 * Input        : s = "havefunonneetcode", k = 5
 * Output       : 6
 * Explanation  : There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.
 * 
 * Example 2
 * Input        : s = "home", k = 5
 * Output       : 0
 * Explanation  : Notice k can be larger than the length of s. In this case, it is not possible to find any substring.

 * https://neetcode.io/problems/find-k-length-substrings-with-no-repeated-characters/question
*/

// ! Amazon

#include <vector>
#include <iostream>
#include <unordered_map>

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

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Keep frequency map of character occurences
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int numKLenSubstrNoRepeats(std::string s, int k) {
  int n = s.size();
  int ans = 0;

  if (k > n) // * Edge case
    return ans;

  std::unordered_map<char, int> freq_mp;
  int i = 0, j = 0;
  while(j < n) {
    freq_mp[s[j]]++;

    while (i < j && ((j - i + 1) > k || freq_mp[s[j]] > 1)) {
      freq_mp[s[i]]--;
      if (freq_mp[s[i]] == 0)
        freq_mp.erase(s[i]);
      i++;
    }

    if ((j - i + 1) == k) {
      ans++;
    }

    j++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  int k = 5;
  std::string s = "havefunonneetcode";

  // * testcase 2
  // int k = 5;
  // std::string s = "home";

  std::cout << "Max Length: " << k << std::endl;
  std::cout << "Input String: " << s << std::endl;

  int ans = numKLenSubstrNoRepeats(s, k);
  std::cout << "K-length Substring with Distinct Characters: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 37-find-k-length-substrings-with-no-repeated-chars.cpp -o output && ./output