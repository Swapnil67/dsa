#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <math.h>
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
    std::cout << '"' << s << '"' << ", ";
  }
  std::cout << "]" << std::endl;
}

// * 11 - Divide Players Into Teams of Equal Skill
// long long dividePlayers(std::vector<int> skill) {
// TODO
// }

// * 12 - Partition Array According to Given Pivot
// std::vector<int> pivotArray(std::vector<int> arr, int pivot) {
// TODO
// }

// * 13 - Rotate array by K places
// std::vector<int> rotate(std::vector<int> &arr, int k) {
// TODO
// } 

// * 14 - Minimum Time to Make Rope Colorful
// int minTimeToMakeRopeColorful(std::string colors, std::vector<int> neededTime) {
// TODO
// }

// * 15 - Minimum Length of String After Deleting Similar Ends
// int minimumLength(std::string s) {
// TODO
// }

// * 16 - Sentence Similarity III
// bool areSentencesSimilar(std::string s1, std::string s2) {
// TODO
// }

// * 17 - Reverse Words in a String
// std::string reverseWords(std::string &s) {
// TODO
// } 

// * 18 - Adding Spaces to a String
// std::string addSpaces(std::string s, std::vector<int> &spaces) {
// TODO
// }

// * 19 - Maximum Width Ramp
// int maxWidthRampA(std::vector<int> &nums) {
// TODO
// }

// * 20 - Array With Elements Not Equal to Average of Neighbors 
// std::vector<int> rearrangeArray(std::vector<int> &nums) {
// TODO
// }

// * 21 - Maximum Matching of Players With Trainers
// int matchPlayersAndTrainers(std::vector<int> players, std::vector<int> trainers) {
// TODO
// }

// * 22 - String Compression
// int compress(std::vector<char> &chars) {
// TODO
// }

// * ----------------------------------------------------------------

// * 01 - Remove Duplicates from Sorted Array II
// int removeDuplicates(std::vector<int> &nums) {
// TODO
// }

// * 02 - Two Sum II - Input Array Is Sorted
// std::vector<int> findTwoSumSorted(std::vector<int> &arr, int target) {    
// TODO
// }

// * 03 - Three Sum
// std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
// TODO
// }

// * 04 - Four Sum
// std::vector<std::vector<int>> fourSum(std::vector<int> &arr, int target) {
// TODO
// }

// * 05 - Container With Most Water
// int maxArea(std::vector<int> &height) {
// TODO
// }

// * 06 - Number of Subsequences That Satisfy the Given Sum Condition
// int numSubseq(std::vector<int> arr, int target) {
// TODO
// }

// * 07 - Boats to Save People
// int numRescueBoats(std::vector<int> &people, int limit) {
// TODO
// }

// * 08 - K-th Symbol in Grammar
// int kthGrammar(int n, int k) {
// TODO
// } 

// * 09 - Bag of Tokens
// int bagOfTokensScore(std::vector<int> tokens, int power) {
// TODO
// }

// * 10 - Rearrange Array Elements by Sign
// std::vector<int> rearrangeArray(std::vector<int> arr) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
