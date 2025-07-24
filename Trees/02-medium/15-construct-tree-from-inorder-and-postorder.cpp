/**
 * * Leetcode - 106
 * * Construct Binary Tree from Inorder and Postorder Traversal
 * 
 * * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * * Output: [3,9,20,null,null,15,7]
 * 
 * * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

typedef struct TreeNode TreeNode;

struct TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

TreeNode *buildTreeHelper(std::vector<int> postorder, int postStart, int postEnd,
                          std::vector<int> inorder, int inStart, int inEnd,
                          std::unordered_map<int, int> inMap)
{
  if (postStart > postEnd || inStart > inEnd)
    return nullptr;

  TreeNode *root = new TreeNode(postorder[postEnd]);

  // * Find the position of this root in 'inorder' using 'inMap'
  int inRoot = inMap[root->data];
  int numsLeft = inRoot - inStart; // * How many nodes are on the left of the tree

  root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1,
                               inorder, inStart, inRoot - 1, inMap);

  root->right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inMap);
  return root;
}

TreeNode *buildTree(std::vector<int> &postorder, std::vector<int> &inorder) {
  if (postorder.size() != inorder.size())
    return nullptr;

  // * Map of inorder val to index
  std::unordered_map<int, int> inMap;
  for (int i = 0; i < inorder.size(); ++i) {
    inMap[inorder[i]] = i;
  }

  TreeNode *root = buildTreeHelper(postorder, 0, postorder.size() - 1,
                                   inorder, 0, inorder.size() - 1, inMap);

  return root;
}

void inOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  
  inOrderTraversal(root->left);
  std::cout << root->data << std::endl;
  inOrderTraversal(root->right);
}

int main(void) {
  std::vector<int> postorder = {9, 15, 7, 20, 3},
                   inorder = {9, 3, 15, 20, 7};

  TreeNode *root = buildTree(postorder, inorder);
  inOrderTraversal(root);
  return 0;
}

// * run the code
// * g++ --std=c++20 15-construct-tree-from-inorder-and-postorder.cpp -o output && ./output
