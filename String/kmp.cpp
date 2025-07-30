#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * Returns Longest Prefix & Suffix
std::vector<int> findLPS(std::string s) {
  int n = s.size();
  std::vector<int>lps(n, 0);

  int length = 0;
  int i = 1;
  while (i < n) {
    if (s[i] == s[length]) {
      length++;
      lps[i] = length;
      i++;
    } else {
      if(length != 0) {
        // * We need to check with previous lps
        length = lps[length - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
    // std::cout << s[i] << " " << length << std::endl;
  }
  return lps;
}

std::vector<int> matchPattern(std::string s, std::string pattern) {
  int n = s.size(), m = pattern.size();

  // * 1. Find the lps of string 's'
  std::vector<int> lps = findLPS(pattern);
  // printArr(lps);

  // * 2. Find the pattern using KMP
  std::vector<int> occurences;
  int i = 0, j = 0;
  while (i < n) {
    if (s[i] == pattern[j]) {
      i++, j++;
    } else {
      if (j == 0) {
        i++;
        continue;
      } else {
        j = lps[j - 1];
      }
    }

    // * found one occurence of pattern
    // * here 'i' will point at the end of pattern string matching in 's' 
    if (j >= m) {
      // std::cout << i << std::endl;
      // * to get the starting idx of pattern we'll subtract from pattern size
      occurences.push_back(i - m);
      j = lps[j - 1]; 
    }
  }

  return occurences;
}

int main(void) {
  // * testcase 1
  // std::string s = "aaacaaaa";
  // std::string pattern = "ca";

  // * testcase 2
  // std::string s = "abcab";
  // std::string pattern = "ab";

  // * testcase 3
  // std::string s = "aabaacaadaabaaba";
  // std::string pattern = "aaba";
  
  // * testcase 4
  std::string s = "abesdu";
  std::string pattern = "edu";
  
  std::cout << "Input string: " << s << std::endl;
  std::cout << "Pattern: " << pattern << std::endl;

  std::vector<int> occurences = matchPattern(s, pattern);
  std::cout << "Matched Occurences" << std::endl;
  printArr(occurences);

  return 0;
}

// * Run the code
// * g++ --std=c++20 kmp.cpp -o output && ./output