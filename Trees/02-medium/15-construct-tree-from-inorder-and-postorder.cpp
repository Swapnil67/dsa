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

void inOrderTraversal(TreeNode *root) {
  if (!root)
    return;
  
  inOrderTraversal(root->left);
  std::cout << root->data << std::endl;
  inOrderTraversal(root->right);
}

TreeNode *buildTreeHelper(std::vector<int> postorder, int post_start, int post_end,
                          std::vector<int> inorder, int in_start, int in_end,
                          std::unordered_map<int, int> inMap)
{
  if (post_start > post_end || in_start > in_end)
    return nullptr;

  TreeNode *root = new TreeNode(postorder[post_end]);

  // * Find the position of this root in 'inorder' using 'inMap'
  int in_root_idx = inMap[root->data];
  int nums_left = in_root_idx - in_start; // * How many nodes are on the left of the tree

  root->left = buildTreeHelper(postorder, post_start, post_start + nums_left - 1,
                               inorder, in_start, in_root_idx - 1, inMap);

  root->right = buildTreeHelper(postorder, post_start + nums_left, post_end - 1,
                                inorder, in_root_idx + 1, in_end, inMap);
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

int main(void) {
  std::vector<int> postorder = {9, 15, 7, 20, 3},
                   inorder = {9, 3, 15, 20, 7};

  TreeNode *root = buildTree(postorder, inorder);
  inOrderTraversal(root);
  return 0;
}

// * run the code
// * g++ --std=c++20 15-construct-tree-from-inorder-and-postorder.cpp -o output && ./output
