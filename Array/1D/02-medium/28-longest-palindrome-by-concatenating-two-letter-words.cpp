/*
 * Leetcode - 2131
 * Longest Palindrome by Concatenating Two Letter Words
 * 
 * You are given an array of strings words. Each element of words consists of two lowercase English letters.
 * Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. 
 * Each element can be selected at most once.
 * 
 * Return the length of the longest palindrome that you can create. 
 * If it is impossible to create any palindrome, return 0.
 * 
 * Example 1    :
 * Input        : words = ["lc","cl","gg"]
 * Output       : 6
 * Explanation  : One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6. 
 *                Note that "clgglc" is another longest palindrome that can be created.
 * 
 * Example 2    :
 * Input        : words = ["ab","ty","yt","lc","cl","ab"]
 * Output       : 8
 * Explanation  : One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
 *                Note that "lcyttycl" is another longest palindrome that can be created.
 * 
 * Example 3    :
 * Input        : words = ["cc","ll","xx"]
 * Output       : 2
 * Explanation  : One longest palindrome is "cc", of length 2. 
 *                Note that "ll" is another longest palindrome that can be created, and so is "xx".
 * 
 * 
 * https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
*/


#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int longestPalindrome(vector<string>& words) {
  unordered_map<string, int> wordFreq;
  int ans = 0;
  for (string &w : words)
    wordFreq[w]++;

  bool flag = false;
  for (string &w : words) {
    if (w[0] != w[1]) { 
      // * Reverse the word
      string rw = "";
      rw += w[1];
      rw += w[0];

      if (wordFreq.count(rw)) {
        ans += (min(wordFreq[w], wordFreq[rw]) * 4);
      }
      wordFreq.erase(rw); // * remove reversed word
    }
    else {
      int cnt = wordFreq[w];
      if (cnt % 2 == 0) {
        ans += (cnt * 2);
      }
      else {
        if (!flag) {
          ans += (cnt * 2);
          flag = true;
        }
        else {
          ans += ((cnt - 1) * 2);
        }
      }
    }
    wordFreq.erase(w); // * remove word
  }
  return ans;
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
