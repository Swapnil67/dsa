/*
* Leetcode - 101
* Symmetric Tree

* Example 1:
* Input: root = [1,2,2,3,4,4,3]
*
*                  1
*               /     \  
*             2        2
*           /  \     /   \  
*          3    4   4     3

* Output: true

* Example 2:
* Input: root = [1,2,2,null,3,null,3]
*
*                  1
*               /     \  
*             2        2
*              \         \  
*               3         3

* Output: false

* https://leetcode.com/problems/symmetric-tree/description/
* https://www.naukri.com/code360/problems/tree-symmetricity_630426
*/

#include <vector>
#include <iostream>

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

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

// * rootA -> root | left | right
// * rootB -> root | right | left
// * And Compare 
bool isSymmetricHelp(TreeNode* rootA, TreeNode* rootB) {
  if (!rootA || !rootB)
    return rootA == rootB;

  if (rootA->data != rootB->data)
    return false;

  return isSymmetricHelp(rootA->left, rootB->right) &&
         isSymmetricHelp(rootA->right, rootB->left);
}

bool isSymmetric(TreeNode* root) {
  if (!root)
    return true;
  
  return isSymmetricHelp(root->left, root->right);
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(2);

  // root->left->left = new TreeNode(3);
  // root->left->right = new TreeNode(4);

  // root->right->left = new TreeNode(4);
  // root->right->right = new TreeNode(3);

  // * testcase 2
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(3);

  bool ans = isSymmetric(root);
  std::cout << "Is Symmetric Tree " << ans << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 10-symmetrical-trees.cpp -o output && ./output
