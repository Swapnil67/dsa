/*
* Leetcode - 110
* Balanced Binary Tree 

* https://leetcode.com/problems/balanced-binary-tree/
* https://www.naukri.com/code360/problems/is-height-balanced-binary-tree_975497
* https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
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
};


// * Use Max Depth of a tree
// * Using DFS 
int isBalanced(TreeNode *root) {
  if (!root)
    return 0;

  // * calculate left height
  int lh = isBalanced(root->left);
  if (lh == -1)
    return -1;

  // * calculate right height
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
  bool ans = balanced >= 0;
  std::cout << "is Balanced Binary Tree: " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 07-is-balanced-bt.cpp -o output && ./output

