#include<vector>
#include<climits>
#include<iostream>
#include<algorithm>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << '"' << s << '"' << ", ";
  }
  std::cout << "]" << std::endl;
}

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// * 01 - Minimum Difference Between Highest and Lowest of K Scores
// int minimumDifference(std::vector<int> &arr, int k) {
// TODO
// }

// * 02 - Minimum Difference Between Highest and Lowest of K Scores
// void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
// TODO
// }

// * 03 - Minimum Difference Between Highest and Lowest of K Scores
// int removeDuplicates(std::vector<int> &arr) {
// TODO
// }

// * 04 - Assign Cookies
// int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
// TODO
// }

// * 05 - Assign Cookies
// std::string firstPalindrome(std::vector<std::string> &words) {
// TODO Tonight
// }

// * 10 - Valid Word Abbreviation
// std::string validWordAbbreviation(std::vector<std::string> &words) {
// TODO Tonight
// }

// * 06 - Sort Array By Parity 
// std::vector<int> sortArrayByParity(std::vector<int> &arr) {
// TODO Tonight
// }

std::string reverseWord(std::string temp) {
  int l = 0, r = temp.size() - 1;
  std::cout << "Temp " << temp << std::endl;
  while(l < r) {
    swap(temp[l], temp[r]);
    l++;
    r--;
  }
  return temp;
} 


// * 06 - Sort Array By Parity 
std::string reverseWords(std::string s) {
  int n = s.size();
  std::string ans = "";
  int start = 0;
  for(int i = 0; i < n; ++i) {
    char ch = s[i];
    if(isspace(ch)) {
      std::cout << start - i << " " << i << std::endl;
      std::string word = reverseWord(s.substr(i - start, i));
      std::cout << "word " << word << std::endl;
      ans += word;
      ans += " ";
      i += 1;
      start = i;
    }
  }
  // reverseWord(s, start, n - 1);
  std::cout << "ans " << ans << std::endl;
  return ans;
}

// * Let's take LeetCode contest
// *      i


int main() {
  // std::string s = "Let's take LeetCode contest";
  // std::string s = "Roronoa Zoro";
  std::string s = "Mr Ding";
  std::cout << s << std::endl;
  std::string ans = reverseWords(s);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ -std=c++17 practice.cpp -o output && ./output