#include <vector>
#include <deque>
#include <iostream>
#include <numeric>
#include <climits>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * 02 - med
// int subarraySum(std::vector<int> arr, int k) {    
// TODO
// }

// * 03 - med
// std::vector<int> firstNegative(std::vector<int> arr, int k) {
// TODO
// }

// * 04 - med
// int longestOnes(std::vector<int> arr, int k) {
// TODO
// }

// * 05 - med
// int totalFruit(std::vector<int> fruits) {
// TODO
// }

// * 06 - med
// int maxFrequency(std::vector<int> arr, int k) {
// TODO
// }

// * 07 - med
// int minSubArrayLen(std::vector<int> arr, int target) {
// TODO
// }

// * 08 - med
// std::vector<int> findClosestElements(std::vector<int> arr, int k, int x) {
// TODO
// }

// * 09A - med
// int minOperations(std::vector<int> arr, int x) {
// TODO
// }

// * 09B - med
// int minOperations2(std::vector<int> arr, int x) {
// TODO
// }

// * 10 - med
// int numSubarraysWithSum(std::vector<int> arr, int goal) {
// TODO
// }

// * 11 - med
// int numSubarrayProductLessThanK(std::vector<int> arr, int k) {
// TODO
// }

// * 12 - med
// int maxSubarrayLength(std::vector<int> arr, int k) {
// TODO
// }

// * 13 - med
// int countSubarrays(std::vector<int> arr, int k) {
// TODO
// }

// * 14 - med
// int lengthOfLongestSubstring(std::string s) {
// TODO
// }

// * 15 - med
// int kDistinctChars(std::string s, int k) {
// TODO
// }

// * 16 - med
// int numberOfSubstrings(std::string s) {
// TODO
// }

// * 17 - med
// int characterReplacement(std::string s, int k) {
// TODO
// }

// * 18 - med
// bool checkInclusion(std::string s1, std::string s2) {
// TODO
// }


// * 19 - med
// int maxVowels(std::string s, int k) {
// TODO
// }

long long countOfSubstrings(std::string s, int k) {
  int n = s.size();
  std::unordered_map<char, int> vowels_map;
  std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  int i = 0, j = 0, consonants = 0, ans = 0;

  while(j < n) {
    if(vowels.count(s[j])) {
      vowels_map[s[j]]++;
    }
    else {
      consonants++;
    }

    while (consonants > k) {
      if(vowels.count(s[i])) { 
        vowels_map[s[i]]--;
      }
      else {
        consonants--;
      }
      i++;
    }

    if (consonants == k && vowels_map['a'] > 0 
         && vowels_map['e'] > 0 && vowels_map['i'] > 0
         && vowels_map['o'] > 0 && vowels_map['u'] > 0)
    {
      ans++;
    }
    j++;
  }
  return ans;
}

int main() {
  int k = 2;
  std::string word = "iqeaouqi"; 
  long long ans = countOfSubstrings(word, k);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output