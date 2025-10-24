/*
* Leetcode - 98
* Validate Binary Search Tree
* Given the root of a binary tree, determine if it is a valid binary search tree (BST).

* A valid BST is defined as follows:
* - The left subtree of a node contains only nodes with keys strictly less than the node's key.
* - The right subtree of a node contains only nodes with keys strictly greater than the node's key.
* - Both the left and right subtrees must also be binary search trees.

*
*                  5
*               /     \  
*             2        6
*           /  \     /   \  
*          1    4   x     7

* Example 1:
* Input: root = [5,1,6,2,4,null,7]
* Output: true

*
*                  5
*               /     \  
*             1        6
*           /  \     /   \  
*          2    4   3     7

* Example 1:
* Input: root = [5,1,6,2,4,3,7]
* Output: false

* https://leetcode.com/problems/validate-binary-search-tree/description/
* https://www.naukri.com/code360/problems/validate-bst_981275
*/

#include <vector>
#include <climits>
#include <iostream>

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

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

// * TIME COMPLEXITY  O(N)
// * SPACE COMPLEXITY O(1) - Auxillary space for recursion
bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
  if (!root)
    return true;
  if (root->data <= minVal || root->data >= maxVal)
    return false;
  return isValidBST(root->left, minVal, root->data) &&
         isValidBST(root->right, root->data, maxVal);
}

int main(void) {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(7);

  bool ans = isValidBST(root, LONG_MIN, LONG_MAX);
  std::cout << "Is valid bst: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 04-validate-bst.cpp -o output && ./output
