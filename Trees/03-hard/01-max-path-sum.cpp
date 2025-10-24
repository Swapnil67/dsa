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

int maxPathSum(TreeNode* root, int &maxSum) {
  if (!root)
    return 0;

  // * caculate left sum
  int ls = std::max(0, maxPathSum(root->left, maxSum)); // * if -ve return 0
  
  // * caculate right sum
  int rs = std::max(0, maxPathSum(root->right, maxSum)); // * if -ve return 0

  int curSum = root->data + ls + rs;
  maxSum = std::max(maxSum, curSum);
  // std::cout << ls << " " << rs << std::endl;
  // std::cout << root->data << " -> " << curSum << std::endl;

  return root->data + std::max(ls, rs);
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);

  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);

  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(7);


  // * testcase 2
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(-1);

  // * testcase 3
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(-2);
  // root->right = new TreeNode(3);

  int maxSum = 0;
  maxPathSum(root, maxSum);
  std::cout << "Max path sum: " << maxSum << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++17 01-max-path-sum.cpp -o output && ./output
