/*
 * Leetcode - 455
 * Assign Cookies
 * 
 * Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
 * Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
 * and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
 * Your goal is to maximize the number of your content children and output the maximum number.

 * Example 1
 * Input  : g = [1, 2, 3], s = [1, 1]
 * Output : 1
 * 
 * Example 2
 * Input  : g = [1, 2], s = [1, 2, 3]
 * Output : 2

 * https://leetcode.com/problems/assign-cookies/description/
*/

// ! Amazon, Meta, Google, MIcrosoft, Apple, Uber

#include <vector>
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

// * ------------------------- Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(nlogn + mlogm)
// * SPACE COMPLEXITY O(1)
int findContentChildren(vector<int> children, vector<int> cookies) {
  // * sort both arrays
  sort(children.begin(), children.end()); // * children greed
  sort(cookies.begin(), cookies.end());   // * cookies size

  int i = 0, j = 0;
  while(i < children.size() && j < cookies.size()) {
    if(cookies[j] >= children[i]) {
      i++;
    }
    j++;
  }
  return i;
}

int main() {
  // * testcase 1
  // vector<int> children = {1, 2};
  // vector<int> cookies = {0, 0, 0, 1, 1, 3};

  // * testcase 2
  vector<int> children = {10, 9, 8, 7};
  vector<int> cookies = {5, 6, 7, 8};

  // * 7, 8, 9, 10
  // * 5, 6, 7, 8

  int ans = findContentChildren(children, cookies);
  cout << ans << endl;
  return 0;
}


// * Run the code
// * g++ --std=c++17 04-assign-cookies.cpp -o output && ./output
