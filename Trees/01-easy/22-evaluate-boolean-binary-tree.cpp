/*
 * Leetcode - 2331
 * Evaluate Boolean Binary Tree
 * 
 * Example 1    :
 * Input        : root = [2,1,3,null,null,0,1]
 * Output       : true
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : root = [0]
 * Output       : false
 * 
 * https://leetcode.com/problems/evaluate-boolean-binary-tree/description/
*/

#include <vector>
#include <iostream>

using namespace std;

typedef struct TreeNode TreeNode;

struct TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  
  TreeNode(int val) {
    data = val;
    left = right = nullptr;
  }
};

bool evaluateTree(TreeNode* root) {
  if (!root->left && !root->right)
    return root->data;

  int a = evaluateTree(root->left); // * Get ans from left subtree
  int b = evaluateTree(root->right); // * Get ans from right subtree

  return (root->data == 2) ? (a || b) : (a && b);
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 22-evaluate-boolean-binary-tree.cpp -o output && ./output
