/*
* Leetcode - 623
* Add One Row to Tree

* Given the root of a binary tree and two integers val and depth, add a row of nodes with value val 
* at the given depth depth.

* Note that the root node is at depth 1.
* The adding rule is:
*
* - Given the integer depth, for each not null tree node cur at the depth depth - 1, 
*   create two tree nodes with value val as cur's left subtree root and right subtree root.
* - cur's original left subtree should be the left subtree of the new left subtree root.
* - cur's original right subtree should be the right subtree of the new right subtree root.
* - If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with 
*   value val as the new root of the whole original tree, and the original tree is the new root's left subtree.

* Example 1:
* Input : root = [4,2,6,3,1,5], val = 1, depth = 2
*                  4        
*               /     \     
*             2        6
*           /  \      /
*          3    1    5

* Output: [4,1,1,2,null,null,6,3,1,5]
*                  4        
*                /    \     
*              1       1
*              /        \     
*             2         6
*           /  \       /
*          3    1     5

* https://leetcode.com/problems/add-one-row-to-tree/description/
*/

// ! Google

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

// * ------------------------- APPROACH: OPTIMAL APPROACH -------------------------
// * BFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) 
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
  if (!root)
    return root;

  if (depth == 1) {
    TreeNode* new_root = new TreeNode(val);
    new_root->left = root;
  }

  queue<TreeNode *> q;
  q.push(root);
  int level = 0;
  while (!q.empty()) {
    level += 1;
    int N = q.size();
    while (N--) {
      TreeNode* node = q.front();
      q.pop();

      if (node->left) {
        q.push(node->left);
      }
      
      if (node->right) {
        q.push(node->right);
      }

      if (level == depth - 1) {
        // * Add new level to left
        TreeNode* new_left_node = new TreeNode(val);
        new_left_node->left = node->left;
        node->left = new_left_node;
        
        // * Add new level to right
        TreeNode* new_right_node = new TreeNode(val);
        new_right_node->right = node->right;
        node->right = new_right_node;
      }
    }
  }
  return root;
}

int main(void) {
  // * testcase 1
  int val = 1, depth = 4;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);

  // * testcase 2
  // int val = 1, depth = 2;
  // TreeNode *root = new TreeNode(4);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(6);
  // root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(1);
  // root->right->left = new TreeNode(5);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  cout << "Answer: " << endl;
  TreeNode *ans = addOneRow(root, val, depth);
  levelOrderTraversal(ans);


  return 0;
}

// * Run the code
// * g++ --std=c++20 47-add-one-row-to-tree.cpp -o output && ./output

