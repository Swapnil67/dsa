#include <stack>
#include <queue>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

void levelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    std::vector<int> level;
    int n = q.size();
    while (n--) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      std::cout << node->data << " ";
    }
    std::cout << std::endl;
  }
}

// * ---------------------------------------------------------------------------------------

// * 01A - In Order DFS
// void inOrderDFS(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 01B - In Order Iterative DFS
// void inOrderIterative(TreeNode *root, std::vector<int> &ans) {
// TODO
// }
  
// * 02A - Pre Order Recursive DFS
// void preOrderDFS(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 02B - Pre Order Iterative DFS
// void preOrderIterative(TreeNode *root, std::vector<int> &ans) {
// TODO
// }

// * 03A - Post Order Recursive DFS
// void postOrderDFS(TreeNode *root, std::vector<int> &ans) {
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

// * 06A - Minimum Depth of Binary Tree (DFS)
// int minDepthDFS(TreeNode *root) {
// TODO
// }

// * 06B - Minimum Depth of Binary Tree (BFS)
// int minDepthBFS(TreeNode *root) {
// TODO
// }
  
// * 07 - Balanced Binary Tree
// int isBalanced(TreeNode *root) {
// TODO
// }

// * 08 - Diameter of Binary Tree
// int diameterOfBinaryTree(TreeNode *root, int &diameter) {
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
// std::vector<std::string> rootToNode(TreeNode* root) {
// TODO
// }

// * 12 - Count Complete Tree Nodes
// int countNodes(TreeNode* root) {
// TODO
// }

// * 13 - Subtree of Another Tree
// int isSubtree(TreeNode* root) {
// TODO
// }

// * 14 - Merge Two Binary Trees
// TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
// TODO
// }

// * 15 - Path Sum
// bool hasPathSum(TreeNode* root, int targetSum) {
// TODO
// }

// * 16 - Cousins in Binary Tree
// bool isCousins(TreeNode* root, int x, int y) {
// TODO
// }

// * 17 - Invert Binary Tree
// TreeNode *invertTreeDFS(TreeNode *root) {
// TODO
// }

int main(void) {
  return 0;
}

// * run the code
// * g++ --std=c++17 practice.cpp -o output && ./output
