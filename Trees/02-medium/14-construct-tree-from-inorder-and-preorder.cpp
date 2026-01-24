/*
 * Leetcode - 105
 * Construct Binary Tree from Preorder and Inorder Traversal
 * 
 * * Input: 
 *                   3
 *                 /   \  
 *               9     20
 *                    /  \  
 *                  15    7
 * * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * * Output: [3,9,20,null,null,15,7]
 * 
 * * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 * * https://www.naukri.com/code360/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539
 * * https://www.geeksforgeeks.org/problems/construct-tree-1/1
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

TreeNode *helper(std::vector<int> preorder, int pre_start, int pre_end,
                          std::vector<int> inorder, int in_start, int in_end,
                          std::unordered_map<int, int> in_idx_mp)
{
  if (pre_start > pre_end || in_start > in_end)
    return nullptr;
  // std::cout << pre_start << " " << pre_end << " | " << in_start << " " << in_end << std::endl;

  TreeNode *root = new TreeNode(preorder[pre_start]);

  // * Find the position of this root in 'inorder' using 'in_idx_mp'
  int in_root_idx = in_idx_mp[root->data];
  int numsLeft = in_root_idx - in_start; // * How many nodes are on the left of the tree

  root->left = helper(preorder, pre_start + 1, pre_start + numsLeft,
                               inorder, in_start, in_root_idx - 1, in_idx_mp);

  root->right = helper(preorder, pre_start + numsLeft + 1, pre_end,
                                inorder, in_root_idx + 1, in_end, in_idx_mp);

  return root;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
  int pre_size = preorder.size(), in_size = inorder.size();
  if (pre_size != in_size)
    return nullptr;

  // * Map of inorder val to index
  std::unordered_map<int, int> in_idx_mp;
  for (int i = 0; i < in_size; ++i) {
    in_idx_mp[inorder[i]] = i;
  }

  TreeNode *root = helper(preorder, 0, pre_size - 1,
                          inorder, 0, in_size - 1, in_idx_mp);

  return root;
}

int main(void) {
  // * testcase 1
  std::vector<int> preorder = {3, 9, 20, 15, 7},
                   inorder = {9, 3, 15, 20, 7};

  // * testcase 2
  // std::vector<int> preorder = {-1},
  //                  inorder = {-1};

  std::cout << "Preorder: ";
  printArr(preorder);
  
  std::cout << "Inorder: ";
  printArr(inorder);

  TreeNode *root = buildTree(preorder, inorder);
  inOrderTraversal(root);
  return 0;
}

// * run the code
// * g++ --std=c++20 14-construct-tree-from-inorder-and-preorder.cpp -o output && ./output
