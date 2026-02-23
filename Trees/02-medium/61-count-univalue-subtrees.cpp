/*
* Leetcode - 894
* Count Univalue Subtrees

* Given the root of a binary tree, return the number of uni-value subtrees.

* A subtree of treeName is a tree consisting of a node in treeName and all of its descendants.

* A uni-value subtree means all nodes of the subtree have the same value.

* A full binary tree is a binary tree where each node has exactly 0 or 2 children.

* Example 1:
* Input       : root = [5,1,5,5,5,null,5]
* Output      : 4

* Example 2:
* Input       : root = [5,5,5,5,5,null,5]
* Output      : 6

* https://neetcode.io/problems/count-univalue-subtrees/question
*/

// ! DP
// ! Amazon, Google, Bloomberg

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

bool dfs(int &ans, TreeNode* root) {
  // * Leaf are always univalue
  if (!root->left && !root->right) {
    ans++;
    return true;
  }

  bool is_uni_value = true;
  if (root->left) {
    bool left_val = dfs(ans, root->left);
    is_uni_value = (is_uni_value && left_val && (root->data == root->left->data));
  }

  if (root->right) {
    bool right_val = dfs(ans, root->right);
    is_uni_value = (is_uni_value && right_val && (root->data == root->right->data));
  }

  if (is_uni_value)
    ans++;

  return is_uni_value;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * DFS - Bottom up approach
// * n - number of nodes in tree, h - height of tree
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(h) 
int countUnivalSubtrees(TreeNode* root) {
  if (!root)
    return 0;

  int ans = 0;
  dfs(ans, root);
  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(5);

  // * testcase 2
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(1);
  // root->right = new TreeNode(1);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  int ans = countUnivalSubtrees(root);
  std::cout << "Univalue BTs: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 61-count-univalue-subtrees.cpp -o output && ./output

