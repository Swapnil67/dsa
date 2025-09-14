/*
 * Leetcode - 767
 * Reorganize String
 * 
 * Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
 * Return any possible rearrangement of s or return "" if not possible.

 * Example 1
 * input  : s = "aab"
 * output : "aba"

 * Example 2
 * input  : s = "aaab"
 * output : ""
 * 
 * https://leetcode.com/problems/reorganize-string/description/
*/

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

// * ------------------------- Brute Force Approach -------------------------`
// * Find max freq for every char
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
std::string bruteForce(std::string &s) {
  int n = s.size();
  std::vector<int> freq(26, 0);
  for (char &c : s) {
    freq[c - 'a']++;
  }

  // * If duplicates are more than (n/2)
  int max_freq = *std::max_element(freq.begin(), freq.end());
  if (max_freq > (n + 1) / 2) {
    return "";
  }
  // debug(freq);

  std::string res = "";
  while (res.size() < n) {
    int max_freq_idx = findMaxIndex(freq);
    char max_freq_char = 'a' + max_freq_idx;
    std::cout << max_freq_idx << " " << max_freq_char << std::endl;
    res += max_freq_char;
    freq[max_freq_idx]--;

    if (freq[max_freq_idx] == 0)
      continue;

    int temp = freq[max_freq_idx];
    freq[max_freq_idx] = INT_MIN;
    int second_max_freq_idx = findMaxIndex(freq);
    char second_max_freq_char = 'a' + second_max_freq_idx;
    std::cout << second_max_freq_idx << " " << second_max_freq_char << std::endl;
    res += second_max_freq_char;
    freq[second_max_freq_idx]--;
    freq[max_freq_idx] = temp;
  }

  return res;
}

// * ------------------------- Optimal Approach -------------------------`
// * using max_heap
// * k is the number of distinct characters in the input string s (maximum 26)
// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(1)
std::string reorganizeString(std::string &s) {
  // * find the freq of each char
  std::vector<int> freq(26, 0);
  for (char &c : s) {
    freq[c - 'a']++;
  }
  
  // * If duplicates are more than (n/2)
  int n = s.size();
  int max_freq = *std::max_element(freq.begin(), freq.end());
  if(max_freq > (n + 1) / 2) {
    return "";
  }
  
  // * Fill the max_heap
  std::priority_queue<std::pair<int, char>> max_heap;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) {
      max_heap.push({freq[i], 'a' + i});
    }
  }

  std::string res = "";
  while (res.size() < n) {
    // * first max freq char
    std::pair<int, char> p = max_heap.top();
    max_heap.pop();
    res += p.second;
    p.first -= 1;
    if (p.first == 0)
      continue;

    // * second max freq char
    std::pair<int, char> p2 = max_heap.top();
    max_heap.pop();
    res += p2.second;
    p2.first -= 1;

    max_heap.push(p);
    max_heap.push(p2);
  }

  return res;
}

int main(void) {
  std::string s = "aab";
  std::cout << "Input String: " << s << std::endl;

  std::string ans = reorganizeString(s);
  std::cout << "Reorganize String: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-reorganize-string.cpp -o output && ./output