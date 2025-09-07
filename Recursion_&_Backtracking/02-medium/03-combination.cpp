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

void helper(int i, std::vector<int> &temp, int k, int &n, std::vector<std::vector<int>> &ans) {
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

// * ------------------------- Optimal Approach -------------------------`
// * TIME COMPLEXITY O(nCk)
// * SPACE COMPLEXITY O(n)
std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  helper(1, temp, k, n, ans);
  return ans;
}

int main(void) {
  int n = 4, k = 2;
  std::cout << "n: " << n << " k: " << k << std::endl;

  std::vector<std::vector<int>> ans = combine(n, k);
  std::cout << "Combinations: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

 return 0;
}

// * Run the code
// * g++ --std=c++20 03-combination.cpp -o output && ./output