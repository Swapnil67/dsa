/*
* Leetcode - 1325
* Delete Leaves With a Given Value

* Given a binary tree root and an integer target, delete all the leaf nodes with value target.

* Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, 
* it should also be deleted (you need to continue doing that until you cannot).

* Input: root = [1,2,3,2,null,2,4], target = 2
* Output: [1,null,3,null,4]
* Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
*              After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
* 
* https://leetcode.com/problems/delete-leaves-with-a-given-value/description/
*/

#include <iostream>

typedef struct TreeNode TreeNode;

struct TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

TreeNode* removeLeafNodes(TreeNode* root, int target) {
  // * Base Case
  if (!root)
    return nullptr;

  root->left = removeLeafNodes(root->left, target);    // * solve for left subtree
  root->right = removeLeafNodes(root->right, target);    // * solve for right subtree

  // * If leaf node then check is this the target node
  if (!root->left && !root->right && root->data == target)
    return nullptr;

  return root;
}

int main(void) {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(2);
  
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(4);

  TreeNode* ans = removeLeafNodes(root, 2);

  return 0;
}

// * Run the code
// * g++ --std=c++20 18-del-leaves-with-given-val.cpp -o output && ./output

