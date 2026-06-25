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

// ! Amazon, Tesla

#include <queue>
#include <vector>
#include <climits>
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


int findMaxIndex(vector<int> &freq) {
  int max_idx = 0;
  for (int i = 1; i < freq.size(); ++i) {
    if (freq[i] > freq[max_idx])
      max_idx = i;
  }
  return max_idx;
}

void debug(vector<int> &freq) {
  // * For Debugging
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) {
      cout << (char)('a' + i) << " = " << freq[i] << endl;
    }
  }
}

// * ------------------------- Brute Force Approach -------------------------`
// * Find max freq for every char
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
string bruteForce(string &s) {
  int n = s.size();
  // * save the freq of each char in freq vector 
  vector<int> freq(26, 0);
  for (char &c : s) {
    freq[c - 'a']++;
  }

  // * If duplicates are more than (n/2)
  int max_freq = *max_element(freq.begin(), freq.end());
  if (max_freq > (n + 1) / 2) {
    return "";
  }
  // debug(freq);

  string res = "";
  while (res.size() < n) {
    int max_freq_idx = findMaxIndex(freq);
    char max_freq_char = 'a' + max_freq_idx;
    // cout << max_freq_idx << " " << max_freq_char << endl;
    res += max_freq_char;
    freq[max_freq_idx]--;

    if (freq[max_freq_idx] == 0)
      continue;

    int temp = freq[max_freq_idx];
    freq[max_freq_idx] = INT_MIN; // * To get next max occuring char

    int second_max_freq_idx = findMaxIndex(freq);
    char second_max_freq_char = 'a' + second_max_freq_idx;
    // cout << second_max_freq_idx << " " << second_max_freq_char << endl;

    res += second_max_freq_char;
    freq[second_max_freq_idx]--;
    freq[max_freq_idx] = temp;
  }

  return res;
}

// * ------------------------- Optimal Approach -------------------------
// * using max_heap
// * k is the number of distinct characters in the input string s (maximum 26)
// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(1)
string reorganizeString(string &s) {
  int n = s.size();

  // * find the freq of each char
  vector<int> freq(26, 0);
  int max_freq = 0;
  for (char &c : s) {
    freq[c - 'a']++;
    max_freq = max(max_freq, freq[c - 'a']);
  }
  
  // * If duplicates are more than (n/2)
  if (max_freq > (n + 1) / 2) {
    return "";
  }

  // * Fill the max_heap
  priority_queue<pair<int, char>> max_heap;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] > 0) {
      max_heap.push({freq[i], 'a' + i});
    }
  }

  string res = "";
  while (res.size() < n) {
    // * Add the 1st max char
    auto [freq, ch] = max_heap.top();
    max_heap.pop();
    res += ch;
    freq--;

    // * Add the 2nd max char
    if (!max_heap.empty()) {
      auto [freq2, ch2] = max_heap.top();
      max_heap.pop();
      res += ch2;
      if (--freq2 > 0)
        max_heap.push({freq2, ch2});
    }

    if (--freq > 0)
      max_heap.push({freq, ch});
  }

  return res;
}

int main(void) {
  // * testcase 1
  // string s = "aab";

  // * testcase 2
  string s = "aaab";

  cout << "Input String: " << s << endl;

  string ans = bruteForce(s);
  // string ans = reorganizeString(s);

  cout << "Reorganize String: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-reorganize-string.cpp -o output && ./output