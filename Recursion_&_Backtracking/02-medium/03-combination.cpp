/*
 * Leetcode - 77
 * Combinations
 * 
 * Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

 * Example 1
 * input  : n = 4, k = 2
 * output : [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * 
 * https://leetcode.com/problems/combinations/description/
 * https://www.naukri.com/code360/problems/combinations_3625257
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

void helper(int i,
            std::vector<int> &temp,
            int k, int &n,
            std::vector<std::vector<int>> &ans)
{
  if (temp.size() == k) {
    ans.push_back(temp);
    return;
  }

  if (i > n) // * edge case
    return;

  // * take the i
  temp.push_back(i);
  helper(i + 1, temp, k, n, ans);
  
  // * don't take the i
  temp.pop_back();
  helper(i + 1, temp, k, n, ans);
}

// * OR
void helper2(int start,
             std::vector<int> &temp,
             int k, int &n,
             std::vector<std::vector<int>> &ans)
{
  if (k == 0) {
    ans.push_back(temp);
    return;
  }

  if (start > n) // * edge case
    return;

  for (int i = start; i <= n; ++i) {
    temp.push_back(i);
    helper2(i + 1, temp, k - 1, n, ans);
    temp.pop_back();
  }
}

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(nCk)
// * SPACE COMPLEXITY O(n)
std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  // helper(1, temp, k, n, ans);
  helper2(1, temp, k, n, ans);
  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 4, k = 2;
  
  // * testcase 2
  int n = 4, k = 3;
  
  // * testcase 3
  // int n = 3, k = 3;

  std::cout << "n: " << n << " k: " << k << std::endl;

  std::vector<std::vector<int>> ans = combine(n, k);
  std::cout << "Combinations: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

 return 0;
}

// * Run the code
// * g++ --std=c++20 03-combination.cpp -o output && ./output