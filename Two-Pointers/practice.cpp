#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

// /**
//  * * Assign Cookies
//  * * Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
//  * * Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
//  * * and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
//  * * Your goal is to maximize the number of your content children and output the maximum number.

//  * * Example 1
//  * * Input  : g = [1,2,3], s = [1,1]
//  * * Output : 1
//  * 
//  * * Example 2
//  * * Input  : g = [1,2], s = [1,2,3]
//  * * Output : 2

//  * * https://leetcode.com/problems/assign-cookies/description/
// */

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());
  int i = 0, j = 0, ans = 0;
  while (i < g.size() && j < s.size()) {
    if (s[j] >= g[i]) {
      ans += 1;
      i += 1;
    }
    j += 1;
  }
  return ans;
}

int main() {
  std::vector<int> g = {1, 2};
  std::vector<int> s = {0, 0, 0, 1, 1, 3};
  // std::vector<int> g = {1, 2};
  // std::vector<int> s = {1, 2, 3};
  printf("Greed factor of children\n");
  printArr(g);
  printf("Sizes of cookies\n");
  printArr(s);
  int ans = findContentChildren(g, s);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output