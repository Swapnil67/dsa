/*
* Leetcode - 988
* Smallest String Starting From Leaf

* A binary tree is named Even-Odd if it meets the following conditions:

* - The root of the binary tree is at level index 0, its children are at level index 1, 
*   their children are at level index 2, etc.

* - For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order 
*   (from left to right).

* - For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order 
*   (from left to right).

* Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

* Example 1:
* Input       : root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
*
*                      1
*                /           \  
*              10              4
*            /               /   \
*           3               7     9
*         /  \             /       \
*        12   8           6         2
*

* Output      : true

* Example 2:
* Input       : root = [5,4,2,3,3,7]
*
*                    5
*                /       \  
*              4          2
*            /   \       / 
*           3     3     7  
*

* Output      : false
* 
* https://leetcode.com/problems/even-odd-tree/description/
*/

// ! Amazon

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include "common.hpp"

using namespace std;

void dfs_brute(std::string cur, TreeNode *root, std::vector<std::string> &strs) {
  if (!root) {
    strs.push_back(cur);
    return;
  }

  cur = char(root->data + 'a') + cur; // * since we need from leaf to root 
  dfs_brute(cur, root->left, strs);
  dfs_brute(cur, root->right, strs);
}

void dfs(std::string &res, std::string cur, TreeNode *root) {
  if (!root)  {
    return;
  }

  cur = (char)(root->data + 'a') + cur;
  
  // * check if possible answer
  if (!root->left && !root->right) {
    // std::cout << cur << std::endl;
    if (res == "" || res > cur) {
      res = cur;
      return;
    }
  }

  dfs(res, cur, root->left);
  dfs(res, cur, root->right);
}

// * ------------------------- APPROACH 1: Brute Force APPROACH -------------------------
// * DFS - Bottom Up + Sorting
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::string bruteForce(TreeNode *root) {
  if (!root)
    return "";

    // * Generate all 
  std::vector<std::string> strs;
  dfs_brute("", root, strs);
  printArr(strs);

  // * sort the strings array
  std::sort(begin(strs), end(strs));
  return strs[0];
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * DFS - Bottom Up
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::string smallestFromLeaf(TreeNode *root) {
  std::string res = "";
  if (!root)
    return res;
  
  dfs(res, "", root);
  return res;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(0);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(4);

  std::cout << "Input BT" << std::endl;
  levelOrderTraversal(root);

  // * testcase 2
  std::string ans = smallestFromLeaf(root);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 54-smallest-string-starting-from-leaf.cpp -o output && ./output

