/**
 * * Leetcode - 1408
 * * String Matching in an Array
 * * Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 * * Example 1
 * * Input  : words = ["mass","as","hero","superhero"]
 * * Output : ["as","hero"]
 *
 * * Example 2
 * * Input  : ["leetcode","et","code"]
 * * Output : ["et","code"]
 *
 * * Example 3
 * * Input  : words = ["blue","green","bu"]
 * * Output : []

 * * https://leetcode.com/problems/string-matching-in-an-array/description/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ ";
  for (std::string s : strs)
  {
    std::cout << '"' << s << '"' << ", ";
  }
  std::cout << "]" << std::endl;
}

// * Nested Loop
bool checkSubstringBrute(std::string t, std::string s)
{
  int n = s.length(), m = t.length();
  if (m > n) {
    return false;
  }
  
  for(int i = 0; i < n; i++) {
    int k = i, j = 0;
    while (j < m) {
      if (s[k] == t[j]) {
        k++, j++;
      }
      else {
        break;
      }
    }
    if (j >= m)
      return true;
  }
  return false;
}


std::vector<std::string> bruteForce(std::vector<std::string> words) {
  int n = words.size();
  std::vector<std::string> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      if (checkSubstringBrute(words[i], words[j])) {
        std::cout << words[i] << " " << words[j] << std::endl;
        // if (checkSubstring(words[i], words[j])) {
        ans.push_back(words[i]);
        break;
      }
    }
  }
  return ans;
}

std::vector<int> findLPS(std::string s) {
  int n = s.size();
  std::vector<int> lps(n, 0);  

  int i = 1;
  int length = 0;
  while (i < n) {
    if (s[i] == s[length]) {
      length++;
      lps[i] = length;
      i++;
    } else {
      if (length > 0) {
        length = lps[length - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }

  return lps;
}

std::vector<int> kmp(std::string s, std::string pattern) {
  // std::cout << s << " " << pattern << std::endl;

  // * 1. find the lps of 'pattern' string
  std::vector<int> lps = findLPS(pattern);
  // printArr(lps);

  std::vector<int> occurences;
  int n = s.size(), m = pattern.size();
  int i = 0, j = 0;
  while (i < n) {
    if(s[i] == pattern[j]) {
      i++, j++;
    } else {
      if(j == 0) {
        i++;
      } else {
        j = lps[j - 1];
      }
    }
    
    if (j >= m) {
      occurences.push_back(i - m);
      // * becoz 'j' is currently out of bound
      j = lps[j - 1];
    }
  }

  return occurences;
}

std::vector<std::string> stringMatchingKMP(std::vector<std::string> words) {
  int n = words.size();
  std::vector<std::string> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      std::vector<int> occurences = kmp(words[j], words[i]);
      if (occurences.size()) {
        // std::cout << "s: '"<< words[i] << "', pattern: '" << words[j] << "'" << std::endl;
        // printArr(occurences);
        // std::cout << "---------------------------" << std::endl;
        ans.push_back(words[i]);
        break;
      }
    }
  }
  return ans;
}

std::vector<std::string> stringMatching(std::vector<std::string> words) {
  int n = words.size();
  std::vector<std::string> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && words[j].find(words[i]) != std::string::npos) {
        ans.push_back(words[i]);
        break;
      }
    }
  }
  return ans;
}

int main(void)
{
  // std::vector<std::string> words = {"as", "ssa", "hero", "superhero"};
  std::vector<std::string> words = {"leetcode", "et", "code"};
  // std::vector<std::string> words = {"blue", "green", "bu"};

  printVectorString(words);

  // std::vector<std::string> ans = bruteForce(words);
  std::vector<std::string> ans = stringMatching(words);
  printVectorString(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 19-string-matching-array.cpp -o output && ./output