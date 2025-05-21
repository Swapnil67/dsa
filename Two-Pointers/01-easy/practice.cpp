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

void printMatrix(std::vector<std::vector<int>> matrix) {
  int r = matrix.size();
  if(r == 0) return;
  int c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    std::cout << "{ ";
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "},";
    std::cout << std::endl;
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

// * 06 - Sort Array By Parity 
// std::vector<int> sortArrayByParity(std::vector<int> &arr) {
// TODO Tonight
// }

// * 07 - TODO
// std::string reverseWords(std::string s) {
// TODO Tonight
// }

// * 08 - Merge Two 2D Arrays by Summing Values
// std::vector<std::vector<int>> mergeArrays(
//     std::vector<std::vector<int>> nums1,
//     std::vector<std::vector<int>> nums2) {
// TODO
// }

// * 09 - Move Zero's to End
// void moveZeroes(std::vector<int> &arr) {
// TODO
// }

// * 10 - Valid Word Abbreviation
// bool validWordAbbreviation(std::string &word, std::string &abbr) {
// TODO Submit Tonight
// }

int main() {
  return 0;
}

// * Run the code
// * g++ -std=c++17 practice.cpp -o output && ./output




