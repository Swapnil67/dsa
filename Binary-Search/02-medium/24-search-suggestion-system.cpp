/*
 * Leetcode - 1268
 * Search Suggestions System 
 * 
 * You are given an array of strings products and a string searchWord.
 * Design a system that suggests at most three product names from products after each character of searchWord is typed. 
 * Suggested products should have common prefix with searchWord. 
 * If there are more than three products with a common prefix return the three lexicographically minimums products.
 * 
 * Return a list of lists of the suggested products after each character of searchWord is typed.
 * 
 * https://leetcode.com/problems/search-suggestions-system/description/
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printArr(vector<string> arr) {
  int n = arr.size();
  cout << "[";
  for (string &s : arr) {
    cout << '"' << s  << '"' << ", ";
  }
  cout << "]" << endl;
}

void printMatrix(vector<vector<string>>&mat) {
  int n = mat.size();
  if(n == 0) return;
  int m = mat[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * Two pointers
// * TIME COMPLEXITY O(n * m)
// * SPACE COMPLEXITY O(1)
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
  std::sort(products.begin(), products.end()); // * O(nlogn)
  // printArr(products);

  vector<vector<string>> ans = {};
  int l = 0, r = products.size() - 1;
  for (int i = 0; i < searchWord.size(); ++i) {
    char ch = searchWord[i];

    // * Check if prefix matches
    while (l <= r && (products[l].size() <= i || products[l][i] != ch)) {
      l++;
    }

    // * Check if prefix matches
    while (l <= r && (products[r].size() <= i || products[r][i] != ch)) {
      r--;
    }

    // * Get the suggestion from l pointer (3 or less than 3)
    int sliceTill = std::min(3, r - l + 1);
    // std::cout << sliceTill << std::endl;
    vector<string> suggestions(products.begin() + l, products.begin() + l + sliceTill);
    ans.push_back(suggestions);
  }

  return ans;  
}

int main(void) {
  // * testcase 1
  string searchWord = "mouse";
  vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};

  printArr(products);
  cout << "Search Word: " << searchWord << endl;

  vector<vector<string>> ans = suggestedProducts(products, searchWord);
  printMatrix(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 24-search-suggestion-system.cpp -o output && ./output

