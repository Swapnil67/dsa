#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

template <typename T>
void reverseArr(T &arr, int l, int r) {
  int n = arr.size();
  while(l < r) {
    swap(arr[l++], arr[r--]);
  }
}

void reverseString(std::string &s, int l, int r) {
  while (isspace(s[r]))
    r -= 1;
  while(l < r) {
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    l += 1;
    r -= 1;
  }
}


template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printMatrix(std::vector<std::vector<T>> matrix) {
  int r = matrix.size();
  if(r == 0) return;
  int c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    printf("[");
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    printf("]");
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void printVectorString(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}

// * 01 - med
// int removeDuplicates(std::vector<int> &arr) {    
// TODO
// }

// * 02 - med
// std::vector<int> findTwoSum(std::vector<int> &arr, int target) {    
// TODO
// }

// * 03 - med
// std::vector<std::vector<int>> threeSum(std::vector<int> &arr, int target) {
// TODO
// }

// * 04 - med
// std::vector<std::vector<int>> fourSum(std::vector<int> &arr, int target) {
// TODO
// }

// * 05 - med
// int maxArea(std::vector<int> &nums) {
// TODO
// }

// * 06 - med
// int numSubseq(std::vector<int> arr, int target) {
// TODO
// }

// * 07 - med
// int numRescueBoats(std::vector<int> boats, int limit) {
// TODO
// }

// * 08 - med
// int numRescueBoats(std::vector<int> boats, int limit) {
// TODO
// }

// * 09 - med
// int bagOfTokensScore(std::vector<int> tokens, int power) {
// TODO
// }

// * 10 - med
// std::vector<int> rearrangeArray(std::vector<int> arr) {
// TODO
// }

// * 11 - med
// long long dividePlayers(std::vector<int> skill) {
// TODO
// }

// * 12 - med
// std::vector<int> pivotArray2(std::vector<int> arr, int pivot) {
// TODO
// } 

// * 13 - med
// std::vector<int> rotate(std::vector<int> &arr, int k) {
// TODO
// }

// * 14 - med
// int minTimeToMakeRopeColorful(std::string colors, std::vector<int> neededTime) {
// TODO
// }

// * 15 - med
// int minimumLength(std::string s) {
// TODO
// }

// * 16 - med
// bool areSentencesSimilar(std::string s) {
// TODO
// }

// * 17 - med
// std::string reverseWords(std::string &s) {
// TODO
// }


int main() {
    // std::string s = "I am zoro";
    std::string s = "   Roronoa      Zoro     ";
    std::cout << s << std::endl;
    // std::string ans = reverseWords(s);
    // std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
