/**
 * * Leetcode - 2385
 * * Amount of Time for Binary Tree to Be Infected
*/

#include <queue>
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

TreeNode *buildTreeHelper(std::vector<int> preorder, int preStart, int preEnd,
                          std::vector<int> inorder, int inStart, int inEnd,
                          std::unordered_map<int, int> inMap)
{
  if (preStart > preEnd || inStart > inEnd)
    return nullptr;

  TreeNode *root = new TreeNode(preorder[preStart]);

  int inRoot = inMap[root->data];
  int numsLeft = inRoot - inStart;

  // std::cout << inRoot << std::endl;
  // std::cout << numsLeft << std::endl;

  root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inMap);

  root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inMap);

  return root;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {

  // * Map of inorder val to index
  std::unordered_map<int, int> inMap;
  for (int i = 0; i < inorder.size(); ++i) {
    inMap[inorder[i]] = i;
  }

  TreeNode *root = buildTreeHelper(preorder, 0, preorder.size() - 1,
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
  std::vector<int> preorder = {3, 9, 20, 15, 7},
                   inorder = {9, 3, 15, 20, 7};

  TreeNode *root = buildTree(preorder, inorder);
  inOrderTraversal(root);
  return 0;
}

// * run the code
// * g++ --std=c++20 14-construct-tree-from-inorder-ans-preorder.cpp -o output && ./output
