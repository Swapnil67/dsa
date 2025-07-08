/*
* Leetcode - 111
* Minimum Depth of Binary Tree 

* https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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

// * Using BFS 
int minDepthBFS(TreeNode *root) {
  if (root == nullptr)
    return 0;
  
  int level = 1;
  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {

    // * Process the complete level
    int n = q.size();
    // std::cout << n << std::endl;

    while (n--) {
      TreeNode *node = q.front();
      q.pop();
      // std::cout << node->data << std::endl;

      // * Found the first leaf node
      if (node->left == nullptr && node->right == nullptr)
        return level;
        
      // * If exists left node then push
      if (node->left)
        q.push(node->left);

      // * If exists right node then push
      if (node->right)
        q.push(node->right);
    }

    level++;
  }

  return -1;
}

// * Using DFS 
int minDepthDFS(TreeNode *root) {
  if (root == nullptr)
    return 0;

  // * Leaf node
  if (!root->left && !root->right)
    return 1;

  int lh = root->left ? minDepthDFS(root->left) : INT_MAX;
  int rh = root->right ? minDepthDFS(root->right) : INT_MAX;

  return 1 + std::min(lh, rh);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // int depth = minDepthBFS(root);
  int depth = minDepthDFS(root);
  std::cout << "Minimum Depth: " << depth << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 06-min-depth-of-bt.cpp -o output && ./output

