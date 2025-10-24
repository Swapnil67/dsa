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


// * 08 - Diameter of Binary Tree
// int diameterOfBinaryTree(TreeNode *root, int &diameter) {
// TODO
// }

// * 09 - Same Tree
// bool isSameTree(TreeNode* p, TreeNode* q) {
// TODO
// } 

// * 09 - Same Tree
// bool isSameTree(TreeNode* p, TreeNode* q) {
// TODO
// } 

// * 10 - Symmetric Tree
// bool isSymmetric(TreeNode* root) {
// TODO
// }

// * 11 - Binary Tree Paths
// void rootToNode(TreeNode* root, std::vector<std::string> &ans, std::string cur) {
// TODO
// }

// * ---------------------------------------------------------------------------------------

// * 01A - In Order DFS
// void inOrderRecursive(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 01B - In Order Iterative DFS
// void inOrderIterative(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 02A - Pre Order Recursive DFS
// void preOrderRecursive(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 02B - Pre Order Iterative DFS
// void preOrderIterative(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 03A - Post Order Recursive DFS
// void postOrderRecursive(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 03B - Post Order Iterative DFS
// void postOrderIterative(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 04 - All 3 traversals
// void threeTraversal(TreeNode *root,
//                     std::vector<int> &preOrder,
//                     std::vector<int> &inOrder,
//                     std::vector<int> &postOrder)
// {
// TODO
// }

// * 05A - Maximum Depth of Binary Tree (DFS)
// int maxDepthDFS(TreeNode *root) {
// TODO
// }

// * 05B - Maximum Depth of Binary Tree (BFS)
// int maxDepthBFS(TreeNode *root) {
// TODO
// }

// * 06A - Minimum Depth of Binary Tree
// int minDepthDFS(TreeNode *root) {
// TODO
// }

// * 06B - Minimum Depth of Binary Tree
// int minDepthBFS(TreeNode *root) {
// TODO
// }
  
// * 07 - Balanced Binary Tree
int isBalanced(TreeNode *root) {

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

// * run the code
// * g++ --std=c++17 practice.cpp -o output && ./output
