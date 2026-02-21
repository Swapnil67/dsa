/*
* Leetcode - 951
* Flip Equivalent Binary Trees

* For a binary tree T, we can define a flip operation as follows: 
* choose any node, and swap the left and right child subtrees.

* A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after 
* some number of flip operations.

* Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or 
* false otherwise.

* Example 2:
* root1: 
*                  1        
*               /     \     
*             2        3
*           /   \    /     
*          4    5   6     
*             /   \    
*            7     8

* root2: 
*                  1        
*               /     \     
*             3        2
*              \     /   \   
*               6   4     5
*                       /   \    
*                      7     8

* Input       : root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
* Output      : true
* Explanation : We flipped at nodes with values 1, 3, and 5.


* https://leetcode.com/problems/flip-equivalent-binary-trees
* https://www.naukri.com/code360/problems/flip-equivalent-binary-tree_1234687
*/

// ! Microsoft, Google, Uber, Apple

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(4*N)
// * SPACE COMPLEXITY O(1)
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
  if (!root1 || !root2)
    return root1 == root2;

  if (root1->data != root2->data)
    return false;

  bool without_flip = flipEquiv(root1->left, root2->left) &&
                      flipEquiv(root1->right, root2->right);

  bool with_flip = flipEquiv(root1->left, root2->right) &&
                   flipEquiv(root1->right, root2->left);

  return without_flip || with_flip;
}

int main(void) {
  // * testcase 1
  // TreeNode *root1 = new TreeNode(1);
  // root1->left = new TreeNode(2);
  // root1->right = new TreeNode(3);
  // root1->left->left = new TreeNode(4);
  // root1->left->right = new TreeNode(5);
  // root1->left->right->left = new TreeNode(7);
  // root1->left->right->right = new TreeNode(8);
  // root1->right->left = new TreeNode(6);

  // TreeNode *root2 = new TreeNode(1);
  // root2->left = new TreeNode(3);
  // root2->right = new TreeNode(2);
  // root2->left->right = new TreeNode(6);
  // root2->right->left = new TreeNode(4);
  // root2->right->right = new TreeNode(5);
  // root2->right->right->left = new TreeNode(8);
  // root2->right->right->right = new TreeNode(7);

  // * testcase 2
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->left->left = new TreeNode(3);

  std::cout << "Input Binary Tree Root1:" << std::endl;
  levelOrderTraversal(root1);
  std::cout << "Input Binary Tree Root2:" << std::endl;
  levelOrderTraversal(root2);

  bool ans = flipEquiv(root1, root2);
  std::cout << "Number of Good Leaf Nodes Pairs: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 36-flip-equivalent-bt.cpp -o output && ./output

