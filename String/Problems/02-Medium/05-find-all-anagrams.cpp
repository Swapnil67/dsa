/*
 * Find All Anagrams in a String
 * Given two strings s and p, return an array of all the start indices of p's anagrams in s.
 * You may return the answer in any order.

 * Example 1:
 * Input : s = "cbaebabacd", p = "abc"
 * Output: [0, 6]
 * Explanation :  The substring with start index = 0 is "cba", which is an anagram of "abc".
 *                The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * Example 2:
 * Input : s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation : The substring with start index = 0 is "ab", which is an anagram of "ab".
 *               The substring with start index = 1 is "ba", which is an anagram of "ab".
 *               The substring with start index = 2 is "ab", which is an anagram of "ab".

 * https://www.naukri.com/code360/problems/find-all-anagrams_975387
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
*/

#include <map>
#include <iostream>


void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool checkAnagram(std::string s, std::string t) {
  std::vector<int> alphabets(26, 0);
  int n1 = s.size(), n2 = t.size();
  if (n1 != n2)
    return false;
  for (int i = 0; i < n1; ++i) {
    int idx = s[i] - 'a';
    alphabets[idx]++;
  }

  for(char ch : t) {
    int idx = ch - 'a';
    if(alphabets[idx] == 0) 
      return false;
    alphabets[idx]--;
  }

  return true;
}

template <typename Map>
bool map_compare(Map const &lhs, Map const &rhs) {
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(s * p)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::string s, std::string p) {
  std::vector<int> ans;
  int n1 = s.size(), n2 = p.size();
  for (int i = 0; i < n1; ++i) {
    std::string t = "";
    for (int j = 0; j < n2; ++j) {
      if (i + j < n1)
        t += s[i + j];
    }
    bool isAnagram = checkAnagram(p, t);
    // std::cout << t << " " << p << std::endl;
    // std::cout << isAnagram << std::endl;
    if(isAnagram) {
      ans.push_back(i);
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(s)
// * SPACE COMPLEXITY O(1)
std::vector<int> findAnagrams(std::string s, std::string p) {
  int n1 = s.size(), n2 = p.size();
  if (n2 > n1)
    return {};

  // * create a hashmap for p string & cur hashmap
  std::map<char, int> curMap;
  std::map<char, int> anagramMap;
  for (int i = 0; i < n2; ++i) {
    anagramMap[p[i]]++;
    curMap[s[i]]++;
  }

  std::vector<int> res;
  bool ans = map_compare(anagramMap, curMap);
  if(ans)
    res.push_back(0);

  int l = 0;
  for (int r = n2; r < n1; ++r) {
    // * add the right pointer char to map
    curMap[s[r]]++;

    // * dcre the left pointer 
    curMap[s[l]]--;
    if(curMap[s[l]] == 0) {
      // * remove the left char from map
      curMap.erase(s[l]);
    }

    l++; // * Incr the left pointer
    // std::cout << l << " " << r << std::endl;

    if(map_compare(curMap, anagramMap)){
      res.push_back(l);
    }
    
  }
  return res;
}

int main() {
  // std::string s = "cbaebabacd", p = "abc";
  std::string s = "abab", p = "ab";
  std::cout << s << " " << p << std::endl;
  // std::vector<int> ans = bruteForce(s, p);
  std::vector<int> ans = findAnagrams(s, p);
  printArr(ans);
  return 0;
}

// * run the code
// * g++ --std=c++17 05-find-all-anagrams.cpp -o output && ./output