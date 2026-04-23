#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

void printMatrix(vector<vector<int>> matrix) {
  int r = matrix.size();
  if(r == 0) return;
  int c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    cout << "{ ";
    for (int j = 0; j < c; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << "},";
    cout << endl;
  }
  cout << endl;
}

void printVectorString(vector<string> strs) {
  int n = strs.size();
  cout << "[ "; 
  for (string s : strs) {
    cout << '"' << s << '"' << ", ";
  }
  cout << "]" << endl;
}

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// * 15 - Squares of a Sorted Array
// vector<int> sortedSquares(vector<int> &nums) {
// TODO
// }

// * 16 - Remove Element
// int removeElement(int val, vector<int> &nums) {
// TODO
// }

// * 17 - Sort Array By Parity II
// vector<int> sortArrayByParityII(vector<int> &nums) {
// TODO
// }

// * ------------------------------------------------------------------------ 

// * 01 - Minimum Difference Between Highest and Lowest of K Scores
// int minimumDifference(vector<int> &arr, int k) {
// TODO
// }

// * 02 - Merge Two Sorted Arrays
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
// TODO
// }

// * 03 - Remove Duplicates from Sorted Array
// int removeDuplicates(vector<int> &arr) {
// TODO
// }

// * 04 - Assign Cookies
// int findContentChildren(vector<int> &g, vector<int> &s) {
// TODO
// }

// * 05 - Find First Palindromic String in the Array
// string firstPalindrome(vector<string> &words) {
// TODO
// }

// * 06 - Sort Array By Parity
// vector<int> sortArrayByParity(vector<int> &nums) {
// TODO
// }

// * 07 - Reverse Words in a String III
// string reverseWords(string s) {
// TODO
// }

// * 08 - Merge Two 2D Arrays by Summing Values
// vector<vector<int>> mergeArrays(
//     vector<vector<int>> nums1,
//     vector<vector<int>> nums2) {
// TODO
// }

// * 09 - Move Zero's to End
// void moveZeroes(vector<int> &arr) {
// TODO
// }

// * 10 - Valid Word Abbreviation
// bool validWordAbbreviation(string &word, string &abbr) {
// TODO
// }

// * 11 - Reverse Vowels of a String
// bool reverseVowels(string &word, string &abbr) {
// TODO
// }

// * 12 - Apply Operations to an Array
// vector<int> applyOperations(vector<int>& nums) {
// TODO
// }

// * 13 - Backspace String Compare
// bool backspaceCompare(string word1, string word2) {
// TODO
// }

// * 14 - Check If Two String Arrays are Equivalent
// bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ -std=c++20 practice.cpp -o output && ./output




