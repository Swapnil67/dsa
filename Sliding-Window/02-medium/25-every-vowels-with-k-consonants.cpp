
/**
 * * Leetcode - 3306
 * * Count of Substrings Containing Every Vowel and K Consonants II
 * * You are given a string word and a non-negative integer k.
 * * Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') 
 * * at least once and exactly k consonants.
 * 
 * * Example 1
 * * Input  : word = "aeioqq", k = 1
 * * Output : 0
 * 
 * * Example 1
 * * Input  : word = "aeiou", k = 0
 * * Output : 1
 * 
 * * Example 1
 * * Input  : word = "ieaouqqieaouqq", k = 1
 * * Output : 3
 * 
 * * Example 1
 * * Input  : word = "iqeaouqi", k = 2
 * * Output : 3
 * 
 * * https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all possible substrings
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
long long bruteForce(std::string s, int k) {
  int n = s.size();
  std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  int i = 0, j = 0, ans = 0;
  
  for (int i = 0; i < n; ++i) {
    int consonants = 0;
    std::unordered_map<char, int> vowels_map;
    for (int j = i; j < n; ++j) {
      if(vowels.count(s[j])) { 
        vowels_map[s[j]]++;
      }
      else {
        consonants++;
      }
      if (consonants == k && vowels_map.size() == 5) {
        ans++;
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
long long countOfSubstrings(std::string s, int k) {
  int n = s.size();
  std::unordered_map<char, int> vowels_map;
  std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  
  // * Pre calculate the next consonant index
  // *  a e i o q q
  // * [4 4 4 4 5 6]
  std::vector<int> next_consonant_idx_vec(n);
  int last_consonant_idx = n;
  for (int i = n - 1; i >= 0; --i) {
    next_consonant_idx_vec[i] = last_consonant_idx;
    if(!vowels.count(s[i])) last_consonant_idx = i;
  }
  // printArr(next_consonant_idx_vec);

  long long ans = 0;
  int i = 0, j = 0, consonants = 0;

  while(j < n) {
    if(vowels.count(s[j])) {
      vowels_map[s[j]]++;
    } else {
      consonants++;
    }

    // * Shrink window from left
    while (consonants > k) {
      char ch = s[i];
      if (vowels.count(ch)) {
        vowels_map[ch]--;
        if (vowels_map[ch] == 0)
          vowels_map.erase(ch);
      } else {
        consonants--;
      }
      i++;
    }

    // * Add the subarrays to ans
    if (consonants == k && vowels_map.size() == 5) { // * Valid Window
      // * because we want to include those subarrays to ans
      // * Eg: 
      // * a e i o u s a e s
      // *           ^ = j
      // *                 ^ = idx
      // * idx - j = 3 (i.e., 3 subarrays with 1 consonant)
      int idx = next_consonant_idx_vec[j]; // * This will return index of next consonant after jth index
      ans += (idx - j);

      // * Shrink window once from left because we added all possible array from previous 'i'
      char ch = s[i];
      if (vowels.count(ch)) {
        vowels_map[ch]--;
        if (vowels_map[ch] == 0)
          vowels_map.erase(ch);
      } else {
        consonants--;
      }
      i++;

    }

    j++;
  }
  return ans;
}

int main() {
  int k = 1;
  std::string word = "aeioqq"; 

  // int k = 0;
  // std::string word = "aeiou"; 

  // int k = 1;
  // std::string word = "ieaouqqieaouqq"; 

  // int k = 0;
  // std::string word = "aouiei"; 

  // int k = 2;
  // std::string word = "iqeaouqi"; 

  std::cout << word << std::endl;

  // long long ans = bruteForce(word, k);
  long long ans = countOfSubstrings(word, k);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 25-every-vowels-with-k-consonants.cpp -o output && ./output
