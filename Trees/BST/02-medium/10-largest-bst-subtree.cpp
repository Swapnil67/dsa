/*
 * Leetcode - PAID
 * Largest BST Subtree
 * 
 * Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), 
 * where the largest means subtree has the largest number of nodes.
 * 
 * A subtree of treeName is a tree consisting of a node in treeName and all of its descendants.
 * 
 * Note: A subtree must include all of its descendants.
 * 
 * 
 * Example 1    :
 *      10
 *     /  \
 *    5    15
 *   / \     \
 *  1   8     7
 * Input        : root = [10,5,15,1,8,null,7]
 * Output       : 3
 * 
 * Example 2    :
 *        4
 *       / \
 *      2   7
 *     / \  /
 *    2   3 5
 *   /       \
 *  2         1

 * Input        : root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
 * Output       : 2
 * Explanation  : 
 * 
 * https://neetcode.io/problems/largest-bst-subtree/question
*/

// ! Meta, Microsoft, Tiktok

#include <vector>
#include <climits>
#include <iostream>
#include "../common.hpp"

using namespace std;

class NodeValue {
  public:
    int minValue, maxValue, maxSize;
    NodeValue(int minval, int maxval, int maxsize)
    {
      this->minValue = minval;
      this->maxSize = maxval;
      this->maxSize = maxsize;
    }
};

NodeValue dfs(TreeNode *root) {
  if (!root)
    return NodeValue(INT_MAX, INT_MIN, 0);
  
  auto left = dfs(root->left);
  auto right = dfs(root->right);

  // * Current node is greater than max in left AND smaller than min in right, it is a BST.
  if (root->data > left.maxValue && root->data < right.minValue) {
    // * It is a BST.
    int c = (1 + left.maxSize + right.maxSize);
    return NodeValue(min(root->data, left.minValue),
                     max(root->data, right.maxValue), c);
  }

  // * Otherwise, return [-inf, inf] so that parent can't be valid BST
  return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(n) 
// * SPACE COMPLEXITY O(h) [recursion stack]
int largestBSTSubtree(TreeNode *root) {
  return dfs(root).maxSize;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(8);
  root->right->right = new TreeNode(7);
  
  int ans = largestBSTSubtree(root);
  std::cout << "Largest BST Size: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 10-largest-bst-subtree.cpp -o output && ./output
