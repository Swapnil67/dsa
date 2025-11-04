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

void inOrder(TreeNode *root) {
  if (!root)
    return;
  inOrder(root->left);
  std::cout << root->data << " ";
  inOrder(root->right);
}

// * 01 - Insert into a Binary Search Tree
// TreeNode* insertIntoBST(TreeNode* root, int val) {
// TODO
// }

// * 02 - Delete Node in a BST
// TreeNode* deleteNode(TreeNode* root, int key) {
// TODO
// }

// * 03 - Kth Smallest Element in a BST
// int kthSmallest(TreeNode* root, int k) {
// TODO
// }

// * 04 - Validate Binary Search Tree
// bool isValidBST(TreeNode* root) {
// TODO
// }

// * 05 - Lowest Common Ancestor of a Binary Search Tree
// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
// TODO
// }

// * 06 - Recover Binary Search Tree
// void recoverTree(TreeNode* root) {
// TODO
// }

int main(void) {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
