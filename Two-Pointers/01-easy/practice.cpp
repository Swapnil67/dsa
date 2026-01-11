#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

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


// * ------------------------------------------------------------------------ 

// * 01 - Minimum Difference Between Highest and Lowest of K Scores
// int minimumDifference(std::vector<int> &arr, int k) {
// TODO
// }

// * 02 - Merge Two Sorted Arrays
// void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
// TODO
// }

// * 03 - Remove Duplicates from Sorted Array
// int removeDuplicates(std::vector<int> &arr) {
// TODO
// }

// * 04 - Assign Cookies
// int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
// TODO
// }

// * 05 - Find First Palindromic String in the Array
// std::string firstPalindrome(std::vector<std::string> &words) {
// TODO
// }

// * 06 - Sort Array By Parity
// std::vector<int> sortArrayByParity(std::vector<int> &nums) {
// TODO
// }

// * 07 - Reverse Words in a String III
// std::string reverseWords(std::string s) {
// TODO
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
// TODO
// }

// * 11 - Reverse Vowels of a String
// bool reverseVowels(std::string &word, std::string &abbr) {
// TODO
// }

// * 12 - Apply Operations to an Array
// std::vector<int> applyOperations(std::vector<int>& nums) {
// TODO
// }

// * 13 - Backspace String Compare
// bool backspaceCompare(std::string word1, std::string word2) {
// TODO
// }

// * 14 - Check If Two String Arrays are Equivalent
// bool arrayStringsAreEqual(std::vector<std::string> &word1, std::vector<std::string> &word2) {
// TODO
// }

// * 15 - Squares of a Sorted Array
// std::vector<int> sortedSquares(std::vector<int> &nums) {
// TODO
// }

// * 16 - Remove Element
// int removeElement(int val, std::vector<int> &nums) {
// TODO
// }

// * 17 - Sort Array By Parity II
// std::vector<int> sortArrayByParityII(std::vector<int> &nums) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ -std=c++20 practice.cpp -o output && ./output




