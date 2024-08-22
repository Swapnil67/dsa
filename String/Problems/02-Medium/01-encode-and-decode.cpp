/*
 * Encode & Decode Strings
 * 
 * Example 1:
 * Input: strs = ["neet","code","love","you"]
 * Output: ["neet","code","love","you"]
 * 
 * Example 2:
 * Input: strs = ["we","say",":","yes"]
 * Output: ["we","say",":","yes"]

 * https://neetcode.io/problems/string-encode-and-decode
 * https://leetcode.com/problems/encode-and-decode-strings/description/
*/

#include<string>
#include<iostream>

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}

std::string encodeStrings(std::vector<std::string> strs) {
  int n = strs.size();
  std::string encoded_str = "";
  for(std::string s : strs) {
    int str_len = s.size();
    std::string delimiter = std::to_string(str_len) + "#";
    encoded_str += delimiter + s;
  }
  return encoded_str;
}

std::vector<std::string> decodeStrings(std::string str) {
  int n = str.size();
  std::vector<std::string> ans;
  int i = 0;
  while(i < n) {
    int j = i;
    while(str[j] != '#') 
      ++j;
    
    // * ex 1 2 # s w a p n i l a d s u l
    // *    i   j
    std::string cnt = str.substr(i, j); // * get the number from delimiter
    // std::cout << i << " " << c << std::endl;
    int word_c = std::stoi(cnt);
    std::string word = str.substr(j + 1, word_c);
    // std::cout << word << std::endl;
    ans.push_back(word);
    i = j + 1 + word_c;
  }

  return ans;
}

int main() {
  // std::vector<std::string> strs = {};
  // std::vector<std::string> strs = {""};
  // std::vector<std::string> strs = {"neet", "code", "love", "you"};
  std::vector<std::string> strs = {"we", "say", ":", "yes", "!@#$%^&*()"};
  printVectorString(strs);

  // * Encode String
  std::string encoded_string = encodeStrings(strs);
  std::cout << "Encoded String " << encoded_string << std::endl;

  // * Decode String
  std::vector<std::string> ans = decodeStrings(encoded_string);
  printVectorString(ans);
  return 0;
}

// * run the code

// * g++ --std=c++17 01-encode-and-decode.cpp -o output && ./output