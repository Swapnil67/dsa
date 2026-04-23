/*
 * Leetcode - 2062
 * Count Vowel Substrings of a String
 * 
 * Example 1    :
 * Input        : word = "aeiouu"
 * Output       : 2
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : word = "unicornarihan"
 * Output       : 0
 * Explanation  : 
 * 
 * Example 3    :
 * Input        : word = "cuaieuouac"
 * Output       : 7
 * 
 * https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/
*/

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)

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

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int helper(string word, int goal) {
  int n = word.size();
  unordered_map<char, int> vowel_freq_mp;
  int i = 0, j = 0, ans = 0;
  while (j < n) {
    if (vowels.count(word[j])) {
      vowel_freq_mp[word[j]]++;
    }
    else { // * consonant the move the ith pointer to 1 after current substring
      i = j + 1;
      j++;
      vowel_freq_mp.clear();
      continue;
    }

    // * Shrink the window
    while (vowel_freq_mp.size() > goal) {
      vowel_freq_mp[word[i]]--;
      if (vowel_freq_mp[word[i]] == 0)
        vowel_freq_mp.erase(word[i]);

      i++;
    }

    ans += (j - i + 1);
    j++;
  }
  return ans;
}

int countVowelSubstrings(string word) {
  return helper(word, 5) - helper(word, 4);
}

int main(void) {
  std::cout << "Vowels Substring: " << countVowelSubstrings("aeiouu") << std::endl;
  std::cout << "Vowels Substring: " << countVowelSubstrings("aunicornarihanu") << std::endl;
  std::cout << "Vowels Substring: " << countVowelSubstrings("cuaieuouac") << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-count-vowel-substrings-of-a-string.cpp -o output && ./output
