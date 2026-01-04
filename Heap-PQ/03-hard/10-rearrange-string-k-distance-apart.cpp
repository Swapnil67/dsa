/*
 * Leetcode - 767
 * Rearrange String k Distance Apart
 * 
 * Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
 * Return any possible rearrangement of s or return "" if not possible.

 * Example 1
 * input  : s = "aabbcc", k = 3
 * output : "abcabc"

 * Example 2
 * input  : s = "aaabc", k = 3
 * output : ""

 * Example 3
 * input  : s = "aaadbbcc", k = 2
 * output : "abacabcd"
 * 
 * https://neetcode.io/problems/rearrange-string-k-distance-apart/
 * https://leetcode.com/problems/rearrange-string-k-distance-apart/description/
*/

// ! Google, Tiktok, Amazon

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int findMaxIndex(std::vector<int> &freq) {
  int max_idx = 0;
  for (int i = 1; i < freq.size(); ++i) {
    if (freq[i] > freq[max_idx])
      max_idx = i;
  }
  return max_idx;
}

void debug(std::vector<int> &freq) {
  // * For Debugging
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) {
      std::cout << (char)('a' + i) << " = " << freq[i] << std::endl;
    }
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * using max_heap + queue
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
std::string rearrangeString(std::string &s, int k) {
  int n = s.size();

  // * Store the frequency for each character.
  std::vector<int> freq_mp(26, 0);
  for (auto &c: s) {
    freq_mp[c - 'a']++;
  }

  // * Insert the characters with their frequencies in the max heap.
  std::priority_queue<std::pair<int, char>> max_heap;
  for (int i = 0; i < 26; ++i) {
    if (freq_mp[i] > 0) {
      max_heap.push({freq_mp[i], i});
    }
  }

  // * This queue stores the characters that cannot be used now.
  // * {freq, char}
  std::queue<std::pair<int, int>> busy;
  std::string ans;
  while (ans.size() != n) {
    int idx = ans.size();

    // * Insert the character that could be used now into the free heap.
    if (!busy.empty() && ((idx - busy.front().first) >= k)) {
      auto q = busy.front();
      busy.pop();
      max_heap.push({freq_mp[q.second], q.second});
    }

    // * If the free heap is empty, it implies no character can be used at this index.
    if (max_heap.empty())
      return "";

    int cur_char = max_heap.top().second;
    max_heap.pop();
    ans += cur_char + 'a';

    freq_mp[cur_char]--;
    if (freq_mp[cur_char] > 0)
      busy.push({idx, cur_char});
  }

  return ans;
}

int main(void) {
  // * testcase 1
  int k = 3;
  std::string s = "aabbcc";

  // * testcase 2
  // int k = 3;
  // std::string s = "aaabc";

  // * testcase 3
  // int k = 2;
  // std::string s = "aaadbbcc";

  std::cout << "K: " << k << std::endl;
  std::cout << "Input String: " << s << std::endl;

  std::string ans = rearrangeString(s, k);
  std::cout << "Reorganize String: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-rearrange-string-k-distance-apart.cpp -o output && ./output