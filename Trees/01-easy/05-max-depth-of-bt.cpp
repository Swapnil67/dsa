/*
* Leetcode - 104
* Maximum Depth of Binary Tree 

* https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
*/

#include <queue>
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

// * Using BFS
int maxDepthBFS(TreeNode *root) {
  int level = 0;
  if (!root)
    return level;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {

    // * Process the complete level
    int n = q.size();
    // std::cout << n << std::endl;
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      // * If exists left node then push
      if(node->left) 
      q.push(node->left);
      
      // * If exists right node then push
      if(node->right) 
        q.push(node->right);
    }
    level++; // * Add this level to tree depth
  }

  return level;
}

// * Using DFS
int maxDepthDFS(TreeNode *root) {
  if (!root)
    return 0;
  
  // * calculate left height
  int lh = maxDepthDFS(root->left);

  // * calculate right height
  int rh = maxDepthDFS(root->right);

  return 1 + std::max(lh, rh);
}

int main(void) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  int depth = maxDepthBFS(root);
  // int depth = maxDepthDFS(root);
  std::cout << "Maximum Depth: " << depth << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 05-max-depth-of-bt.cpp -o output && ./output