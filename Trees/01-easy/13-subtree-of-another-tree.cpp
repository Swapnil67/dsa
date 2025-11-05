/*
* Leetcode - 572
* Subtree of Another Tree

* Example 1:
* Input: root = [3,4,5,1,2], subRoot = [4,1,2]
* Output: true

* https://leetcode.com/problems/subtree-of-another-tree/
* https://www.naukri.com/code360/problems/subtree-of-another-tree_893071
* https://www.geeksforgeeks.org/problems/check-if-subtree/1
*/

// ! Meta, Amazon, Microsoft

#include <vector>
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
};

bool isSameTree(TreeNode *rootA, TreeNode *rootB) {
  if (!rootA || !rootB)
    return rootA == rootB;

  return (rootA->data == rootB->data &&
          isSameTree(rootA->left, rootB->left) &&
          isSameTree(rootA->right, rootB->right));
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  // * We can have empty subtree
  if (!subRoot)
    return true;

  if (!root)
    return false;

  // * Check from the root itself first
  if (isSameTree(root, subRoot))
    return true;

  // * Now Check from root->left & root->right subtrees
  return (isSubtree(root->left, subRoot) ||
          isSubtree(root->right, subRoot));
}

int main(void) {
  TreeNode *rootA = new TreeNode(3);
  rootA->left = new TreeNode(4);
  rootA->right = new TreeNode(5);
  
  rootA->left->left = new TreeNode(1);
  rootA->left->right = new TreeNode(2);
  
  TreeNode *rootB = new TreeNode(3);
  rootB->left = new TreeNode(1);
  rootB->right = new TreeNode(2);

  bool ans = isSubtree(rootA, rootB);
  std::cout << "Subtree of Another Tree: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-subtree-of-another-tree.cpp -o output && ./output

