/*
 * Find the Index of the First Occurrence in a String
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 
 * if needle is not part of haystack.
 * 
 * Example 1:
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0, so we return 0.
 * 
 * Example 2:
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.

 * https://www.naukri.com/code360/problems/implement-indexof_981288
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/


#include<map>
#include<iostream>

template <typename Map>
bool map_compare(Map const &lhs, Map const &rhs) {
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

// * Nested Loop
// * TIME COMPLEXITY O(n1 * n2)
// * SPACE COMPLEXITY O(N)
int bruteForce(std::string haystack, std::string needle) {
  int n1 = haystack.size(), n2 = needle.size();
  
  for (int i = 0; i < n1; ++i) {

    // * If first char does not matches continue
    if (haystack[i] != needle[i]) {
      continue;
    }

    std::string t = "";
    for (int j = 0; j < n2; ++j) {
      if (i + j < n1)
        t += haystack[j + i];
    }
    std::cout << t << std::endl;
    if(t == needle)
      return i;
  }
  return -1;
} 

// * Two pointer approach
// * TIME COMPLEXITY O(n1 + n2)
// * SPACE COMPLEXITY O(n1)
int betterApproach(std::string haystack, std::string needle) {
  int n1 = haystack.size(), n2 = needle.size();

  // * create a map for needle & curMap
  std::map<char, int> needleMap, curMap;
  for (int i = 0; i < n2; ++i) {
    needleMap[needle[i]]++;
    curMap[haystack[i]]++;
  }

  if(map_compare(needleMap, curMap)) {
    return 0;
  }

  // * Two pointer approach
  int i = 0;
  for (int j = n2; j < n1; ++j) {
    curMap[haystack[j]]++;
    curMap[haystack[i]]--;
    if(curMap[haystack[i]] == 0) {
      curMap.erase(curMap[haystack[i]]);
    }
    i++;
    if(map_compare(needleMap, curMap)) {
      return i;
    }
  }
  return -1;
} 

// * Knuth–Morris–Pratt KMP
// * TIME COMPLEXITY O(n1 + n2)
// * SPACE COMPLEXITY O(n2)
int kmp(std::string haystack, std::string needle) {
  int n1 = haystack.size(), n2 = needle.size();
  int prevLPS = 0, i = 1;
  std::vector<int> lps(n2);

  while (i < n2) {
    if(needle[i] == needle[prevLPS]) {
      lps[i] =  prevLPS + 1;
      prevLPS += 1;
      i += 1;
    }
    else if(prevLPS == 0) {
      // * first two chars are not matching
      lps[i] = 0;
      i += 1; 
    } else {
      prevLPS = lps[prevLPS - 1];
    }
  }

  i = 0;      // * ptr for haystack
  int j = 0;  // * ptr for needle
  while (i < n1) {
    if (haystack[i] == needle[j]) {
      i += 1;
      j += 1;
    }
    else {
      if (j == 0) {
        i += 1;
      }
      else {
        j = lps[j - 1];
      }
    }

    if (j == n2)
      return i - n2;
  }

  return -1;
}

int main() {
  std::string haystack = "sadbutsad", needle = "sad";
  // std::string haystack = "leetcode", needle = "leeto";

  std::cout << haystack << " " << needle << std::endl;

  // int ans = bruteForce(haystack, needle);
  // int ans = betterApproach(haystack, needle);
  int ans = kmp(haystack, needle);
  std::cout << ans << std::endl;
  return 0;
}