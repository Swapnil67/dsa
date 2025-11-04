/*
* Leetcode - 235
* Lowest Common Ancestor of a Binary Search Tree
* Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

* According to the definition of LCA on Wikipedia: 
* “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has
* both p and q as descendants (where we allow a node to be a descendant of itself).”
*
*                  6
*               /     \  
*             2        8
*           /  \      / \  
*          0    4    7   9
*              / \ 
*             3   5

* Example 1:
* Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
* Output: 6

* Example 1:
* Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
* Output: 2

* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
* https://www.naukri.com/code360/problems/lca-in-a-bst_981280
*/

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
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY  O(logn) - (Height of tree)
// * SPACE COMPLEXITY O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root)
    return nullptr;

  while (root) {
    // * both nodes are on the right of current node
    if (p->data > root->data && q->data > root->data) {
      root = root->right;
    }
    // * both nodes are on the left of current node
    else if (p->data < root->data && q->data < root->data) {
      root = root->left;
    }
    else {
      return root;
    }
  }
  return nullptr;
}

int main(void) {
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  TreeNode *p = new TreeNode(2);
  TreeNode *q = new TreeNode(4);

  TreeNode *lca = lowestCommonAncestor(root, p, q);
  if (lca) {
    std::cout << "Lowest Common Ancestor: " << lca->data << std::endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-lca-in-bst.cpp -o output && ./output
