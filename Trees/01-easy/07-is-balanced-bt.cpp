/*
* Leetcode - 110
* Balanced Binary Tree 

* https://leetcode.com/problems/balanced-binary-tree/
*/

#include <queue>
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
};


// * Use Max Depth of a tree
// * Using DFS 
int isBalanced(TreeNode *root) {
  if (!root)
    return 0;

  int lh = isBalanced(root->left);
  if (lh == -1)
    return -1;

  int rh = isBalanced(root->right);
  if (rh == -1)
    return -1;

  if (std::abs(rh - lh) > 1)
    return -1;

  return 1 + std::max(lh, rh);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);

  // * toggle this
  // root->left->left->left = new TreeNode(5);

  int balanced = isBalanced(root);
  // std::cout << balanced << std::endl;
  std::cout << "is Balanced Binary Tree: " << (balanced >= 0 ? true : false) << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 07-is-balanced-bt.cpp -o output && ./output

