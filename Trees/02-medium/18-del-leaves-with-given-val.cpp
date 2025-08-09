/*
TODO
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

