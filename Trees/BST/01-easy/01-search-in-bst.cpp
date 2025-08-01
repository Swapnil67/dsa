/*
* Leetcode - 700
* Search in a Binary Search Tree
* You are given the root of a binary search tree (BST) and an integer val.

* Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
* If such a node does not exist, return null.

*
*                  4
*               /     \  
*             2        7
*           /  \     /   \  
*          1    3   x     x

* Example 1:
* Input: root = [4,2,7,1,3], val = 2
* Output: [2,1,3]

* Example 2:
* Input: root = [4,2,7,1,3], val = 5
* Output: []

* https://leetcode.com/problems/search-in-a-binary-search-tree/
* https://www.naukri.com/code360/problems/search-in-bst_1402878
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

// * TIME COMPLEXITY  O(logn)
// * SPACE COMPLEXITY O(1)
TreeNode* searchBST(TreeNode* root, int val) {
  while (root && root->data != val) {
    root = val < root->data ? root->left : root->right;
  }
  return root;
}

int main(void) {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  // int val = 2;
  int val = 5;

  TreeNode *ans = searchBST(root, val);
  if(ans) {
    std::cout << ans->data << std::endl;
  } else {
    std::cout << "Node not found" << std::endl;
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-search-in-bst.cpp -o output && ./output
