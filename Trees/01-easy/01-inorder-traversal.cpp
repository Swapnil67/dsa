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
// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Left | Root | Right
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
// * SPACE COMPLEXITY Best Case  = O(logn) ~ O(height of tree) * Size of Activation Record
void inOrder(TreeNode* node, std::vector<int> &ans) {
  if (node == nullptr)
    return;

  inOrder(node->left, ans);
  ans.push_back(node->data);
  inOrder(node->right, ans);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);


  std::vector<int> ans;
  inOrder(root, ans);

  printArr(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 01-inorder-traversal.cpp -o output && ./output
