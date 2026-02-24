/*
 * Leetcode - 429 
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/
*/

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

TreeNode *insertIntoMaxTree(TreeNode *root, int val)
{
  if (!root || val > root->data) {
    TreeNode *new_node = new TreeNode(val);
    new_node->left = root;
    return new_node;
  }
  root->right = insertIntoMaxTree(root->right, val);
  return root;
}

TreeNode *insertIntoMaxTree(TreeNode *root, int val)
{
  
  TreeNode *new_node = new TreeNode(val);
  TreeNode *cur = root;
  if (!root || val > root->data) {
    new_node->left = root;
    return new_node;
  }

  // * Go to right till we have <= val
  while (cur->right && cur->right->data > val) {
    cur = cur->right;
  }
  new_node->right = cur->right;
  cur->right = new_node;
  return root;
}


int main(void) {
  // * Do this on leetcode
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 59-n-ary-tree-level-order-traversal.cpp -o output && ./output
