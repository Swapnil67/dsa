#include <stack>
#include <queue>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

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

// * 01A - In Order Recursive DFS
// void inOrderRecursive(TreeNode *node) {
  // TODO
  // }

// * 01B - In Order Iterative DFS
// void inOrderIterative(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 02A - Pre Order Recursive DFS
// void preOrderRecursive(TreeNode *node, std::vector<int> &ans) {
// TODO
// }

// * 02B - Pre Order Iterative DFS
// void preOrderIterative(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 03A - Post Order Recursive DFS
// void postOrderRecursive(TreeNode *node, std::vector<int> &ans) {
// TODO
// }

// * 03B - Post Order Iterative DFS
// void postOrderIterative3(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 04 - All 3 traversals
// void threeTraversal(TreeNode *root,
//                     std::vector<int> &preOrder,
//                     std::vector<int> &postOrder,
//                     std::vector<int> &inOrder)
// {
// TODO
// }
  

// * 05A - Maximum Depth of Binary Tree
// int maxDepthDFS(TreeNode *root) {
// TODO
// }

// * 05B - Maximum Depth of Binary Tree
// int maxDepthBFS(TreeNode *root) {
// TODO
// }

// * 06A - Maximum Depth of Binary Tree
// int minDepthDFS(TreeNode *root) {
// TODO
// }

// * 06B - Minimum Depth of Binary Tree
// int minDepthBFS(TreeNode *root) {
// TODO
// }

// * 07 - Balanced Binary Tree
// int isBalanced(TreeNode *root) {
// TODO
// }

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);


  return 0;
}

// * run the code
// * g++ --std=c++17 practice.cpp -o output && ./output
