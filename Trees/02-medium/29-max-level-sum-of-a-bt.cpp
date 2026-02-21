/*
* Leetcode - 1161
* Maximum Level Sum of a Binary Tree

* Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
* Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

* Example 1:
* Input: 
*                   1             
*               /      \     
*             7         0
*           /   \     /  \  
*          7    -8   x   x

* Output: 2

* https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include "common.hpp"

using namespace std;

// * ------------------------- APPROACH 1: Brute Force APPROACH -------------------------
// * Use Max Heap

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Calculate level sum on the go
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxLevelSum(TreeNode* root) {
  if (!root)
    return 0;

  std::queue<TreeNode *> q;
  q.push(root);

  int ans = 0;
  int max_sum = INT_MIN, level = 1;

  while (!q.empty()) {
    int level_sum = 0;
    int n = q.size();

    // * loop over current level
    while (n--) {
      TreeNode *node = q.front();
      q.pop();
      
      level_sum += node->data;

      if (node->left) 
        q.push(node->left);
      
      if (node->right) 
        q.push(node->right);
    }
    std::cout << "level_sum " << level_sum << std::endl;
    if (level_sum > max_sum) {
      max_sum = level_sum;
      ans = level;
    }
    level++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // TreeNode* root = new TreeNode(1);
  // root->left = new TreeNode(7);
  // root->right = new TreeNode(0);
  
  // root->left->left = new TreeNode(7);
  // root->left->right = new TreeNode(-8);

  // * testcase 2
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(1);
  root->right = new TreeNode(0);
  
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);
  
  root->right->left = new TreeNode(-7);
  root->right->right = new TreeNode(9);

  std::cout << "Input Tree" << std::endl;
  levelOrderTraversal(root);
  
  int level = maxLevelSum(root); 
  std::cout << "Max sum level: " << level << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 29-max-level-sum-of-a-bt.cpp -o output && ./output