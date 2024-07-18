#include <map>
#include <string>
#include <iostream>

bool isAlphabet(char c) {
  return ((int)c >= (int)'A' && (int)c <= (int)'Z') || ((int)c >= (int)'a' && (int)c <= (int)'z');
}

void printVectorString(std::vector<std::string> arr) {
  std::cout<<"[ ";
  for(std::string s: arr) {
    std::cout<<s;
    std::cout<<", ";
  }
  std::cout<<"]\n";
}

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * -------------- Valid Anagram --------------

bool validAnagram(std::string s, std::string t) {
  std::vector<int> charArr(26, 0);
  for (char ch : s) {
    int idx = ch - (int)'a';
    charArr[idx]++;
  }

  for (char ch : t) {
    int idx = ch - (int)'a';
    if(charArr[idx] <= 0) {
      return false;
    }
    charArr[idx]--;
  }

  return true;
}

// * -------------- Is Subsequence --------------

bool isSubsequence(std::string s, std::string t) {
  int n1 = s.size(), n2 = t.size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if(s[i] == t[j]) {
      i++;
    }
    j++;
  }
  return i == n1;
}

// * ------------ Length of last word ------------

int lengthOfLastWord(std::string s) {
  int n = s.size(), c = 0;

  int p = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if(!isAlphabet(s[i])) {
      p--;
    }
    else {
      break;
    }
  }

  for (int i = p; i >= 0; i--) {
    if(isAlphabet(s[i])) {
      c++;
    }
    else {
      break;
    }
  }
  return c;
}


// * ------------ Longest Common Prefix ------------

std::string longestCommonPrefix(std::vector<std::string> strs) {
  int n = strs.size();
  std::string strPrefix = "";
  for (int i = 0; i < strs[0].size(); i++) {
    char ch = strs[0][i];
    bool match = true;
    std::cout << ch << std::endl;
    for (int j = 1; j < n; j++) {
      if(ch != strs[j][i]) {
        match = false;
        break;
      }
    }

    if(!match) {
      break;
    }
    strPrefix += ch;
  }
  return strPrefix;
}

// * ------------ Longest Common Prefix ------------


int main() {

  // * Problem 1 - Valid Anagram
  // std::cout << "Valid Anagram" << std::endl;
  // std::string s = "anagram", t = "nagaram";
  // std::string s = "aacc", t = "ccac";
  // std::cout << "s = " << s << " t = " << t << std::endl;
  // bool isValid = validAnagram(s, t);
  // std::cout << "Is valid anagram " << isValid << std::endl;

  // * Problem 2 - Is Subsequence
  // std::cout << "Is Subsequence" << std::endl;
  // std::string s = "abc", t = "ahbgdc";
  // std::string s = "ace", t = "ahbgdc";
  // std::cout << "s = " << s << " t = " << t << std::endl;
  // bool isValid = isSubsequence(s, t);
  // std::cout << "Is Subsequence " << isValid << std::endl;

  // * Problem 3 - Length of last word
  // std::string str = "luffy is still joyboy";
  // std::string str = "   fly me   to   the moon  ";
  // std::cout << str << std::endl;
  // int len = lengthOfLastWord(str);
  // std::cout << "Length of last word is " << len << std::endl;

  // * Problem 4 - Longest Common Prefix
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  printVectorString(strs);
  std::string commonPrefix = longestCommonPrefix(strs);
  std::cout << "Longest Common Prefix is = " << commonPrefix << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice