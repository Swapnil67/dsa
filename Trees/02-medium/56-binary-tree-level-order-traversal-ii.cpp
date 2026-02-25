/*
 * Leetcode - 107
 * Binary Tree Level Order Traversal II
 * 
 * 
 * Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
 * (i.e., from left to right, level by level from leaf to root).
 * 
 * Example 1:
 * Input: 
 *
 *                   1
 *               /     \  
 *             2        3
 *           /  \    
 *          4    5   
 * Output: ans = [[4, 5], [2, 3], [1]]
 * 
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii
 * 
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include "common.hpp"

using namespace std;

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> levelOrderBottom(TreeNode *root) {
  vector<vector<int>> ans;
  if (!root)
    return ans;

  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    vector<int> level;
    int n = q.size();
    while (n--)
    {
      TreeNode *node = q.front();
      q.pop();

      level.push_back(node->data);

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    ans.push_back(level);
  }

  reverse(begin(ans), end(ans));
  return ans;
}


int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);

  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);

  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);

  // * testcase 2
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);

  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  std::cout << "Input Tree:" << std::endl;
  levelOrderTraversal(root);

  std::vector<std::vector<int>> ans = levelOrderBottom(root);
  std::cout << "Zigzag Level Order Traversal: " << std::endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 56-binary-tree-level-order-traversal-ii.cpp -o output && ./output
