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



// * 16 - med
// bool areSentencesSimilar(std::string s) {
// TODO
// }

// * 17 - med
// std::string reverseWords(std::string &s) {
// TODO
// }

// * 01 - med
// int removeDuplicates(std::vector<int> &arr) {    
// TODO
// }

// * 02 - med
// std::vector<int> findTwoSum(std::vector<int> &arr, int target) {    
// TODO Tonight
// }

// * 03 - med
// std::vector<std::vector<int>> threeSum(std::vector<int> &arr, int target) {
// TODO Tonight
// }

// * 04 - med
// std::vector<std::vector<int>> fourSum(std::vector<int> &arr, int target) {
// TODO Tonight
// }

// * 05 - med
// int maxArea(std::vector<int> &height) {
// TODO 
// }


// * 06 - Number of Subsequences That Satisfy the Given Sum Condition
// int numSubseq(std::vector<int> arr, int target) {
// TODO Tonight
// }

// * 07 - Boats to Save People
// int numRescueBoats(std::vector<int> boats, int limit) {
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

// * 11 - Divide Players Into Teams of Equal Skill
// long long dividePlayers(std::vector<int> skill) {
// TODO
// }

// * 12 - Partition Array According to Given Pivot
// std::vector<int> pivotArray2(std::vector<int> arr, int pivot) {
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


int main() {
  // * testcase 1
  std::string s1 = "My name is Haley", s2 = "My Haley";

  // * testcase 2
  // std::string s1 = "of", s2 = "of course";

  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;

  // bool ans = areSentencesSimilar(s1, s2);
  // std::cout << "Is similar sentences: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

