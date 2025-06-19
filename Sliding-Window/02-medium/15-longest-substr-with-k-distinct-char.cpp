/**
 * * Leetcode - 
 * * Longest Substring with At Most K Distinct Characters
 * * You are given a string 'str' and an integer ‘K’.
 * * Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

 * * Example 1
 * * Input  : s = "abbbbbbc", k = 2
 * * Output : 7
 * * Explanation: substring "abbbbbb"

 * * Example 2
 * * Input  : s = "bbbbb", k = 1
 * * Output : 5
 * * Explanation: substring "bbbbb"

 * * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
 * * https://www.naukri.com/code360/problems/distinct-characters_2221410
*/

#include <map>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible substrings
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(256)
int bruteForce(std::string s, int k) {
  int n = s.size();
  int max_len = 0;
  for (int i = 0; i < n; ++i) {
    std::map<int, int> freq_map;
    for (int j = i; j < n; ++j) {
      freq_map[s[j]]++;
      if (freq_map.size() > k) {
        break;
      }
      max_len = std::max(max_len, j - i + 1);
    }
  }
  return max_len;
}


// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Classic Sliding Window
// * Keep frequency map of character occurences
// * If frequency map size becomes greater than k then remove frequency map till it gets to k size
// * Use while loop to decrease size of frequency map
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(256)
int betterApproach(std::string s, int k) {
  int n = s.size();
  int i = 0, j = 0, max_len = 0;
  std::map<int, int> freq_map;
  while(j < n) {
    freq_map[s[j]]++;

    // * Keep frequency map with k distinct elements
    while (freq_map.size() > k) {
      freq_map[s[i]]--;
      if (freq_map[s[i]] == 0) {
        freq_map.erase(s[i]);
      }
      i++;
    }

    if(freq_map.size() <= k) {
      max_len = std::max(max_len, j - i + 1);
    }

    j++;
  }

  return max_len;
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Classic Sliding Window
// * Keep frequency map of character occurences
// * Only calculate max_len if map size is within k or else decrease the frequency map
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(256)
int kDistinctChars(std::string s, int k) {
  int n = s.size();
  int i = 0, j = 0, max_len = 0;
  std::map<int, int> freq_map;
  while(j < n) {
    freq_map[s[j]]++;

    // * Keep frequency map with k distinct elements
    if(freq_map.size() > k) {
        freq_map[s[i]]--;
        if(freq_map[s[i]] == 0) {
          freq_map.erase(s[i]);
        }
        i++;
    }
    else {
      // * Only calculate if we have k distinct characters
      max_len = std::max(max_len, (j - i + 1));
    }

    j++;
  }

  return max_len;
}



int main() {
  // int k = 2;
  // std::string s = "abbbbbbc";

  int k = 8;
  std::string s = "fitmgntcesze";

  std::cout << "Distinct Characters: " << k << std::endl;
  std::cout << "Input String: " << s << std::endl;

  // int ans = bruteForce(s, k);
  // int ans = betterApproach(s, k);
  int ans = kDistinctChars(s, k);
  std::cout << "Longest Substring with At Most K Distinct Characters: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 15-longest-substr-with-k-distinct-char.cpp -o output && ./output
