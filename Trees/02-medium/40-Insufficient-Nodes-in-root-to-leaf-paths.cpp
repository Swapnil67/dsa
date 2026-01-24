/*
  * Leetcode - 1080
  * Insufficient Nodes in Root to Leaf Paths

  * Given the root of a binary tree and an integer limit, delete all insufficient nodes in the 
  * tree simultaneously, and return the root of the resulting binary tree.

  * A node is insufficient if every root to leaf path intersecting this node has a sum strictly less than limit.
  * A leaf is a node with no children.

  * Example 1:
  *                 10        
  *               /   \     
  *             5      10

  * Input       : root = [10,5,10], limit = 21
  * Output      : []

  * Example 2:
  *                  5        
  *               /     \     
  *             4        8
  *           /         /  \ 
  *          11        17   4
  *        /  \            / \
  *       7   1           5   3

  * Input       : root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
  * Output      : [5,4,8,11,null,17,4,7,null,null,null,5]


  * https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
*/

// ! Google

#include <queue>
#include <vector>
#include <iostream>

typedef struct TreeNode TreeNode;

struct TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
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

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;

  std::queue<TreeNode *> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();
    // * traverse the whole level
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      std::cout << node->data << " ";

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    std::cout << std::endl;
  }
}

TreeNode* dfs(TreeNode* root, int limit) {
  if (!root)
    return nullptr;

  limit -= root->data;

  // * Check if sum at leaf node exceeds given limit
  if (!root->left && !root->right) {
    return limit > 0 ? nullptr : root;
  }

  root->left = dfs(root->left, limit);
  root->right = dfs(root->right, limit);

  // * After recursion, if both children become nullptr, this node also becomes insufficient — 
  // * prune it by returning nullptr.
  return !root->left && !root->right ? nullptr : root;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) [recursion stack]
TreeNode* sufficientSubset(TreeNode* root, int &limit) {
  return dfs(root, limit);
}

int main(void) {
  // * testcase 1
  int limit = 21;
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(10);

  // * testcase 2
  // int limit = 22;
  // TreeNode *root = new TreeNode(5);
  // root->left = new TreeNode(4);
  // root->right = new TreeNode(8);
  // root->left->left = new TreeNode(11);
  // root->left->left->left = new TreeNode(7);
  // root->left->left->right = new TreeNode(1);

  // root->right->left = new TreeNode(17);
  // root->right->right = new TreeNode(4);
  // root->right->right->left = new TreeNode(5);
  // root->right->right->right = new TreeNode(3);

  // * testcase 3
  // int limit = -1;
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(-3);
  // root->left->left = new TreeNode(-5);
  // root->right->left = new TreeNode(4);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  std::cout << "Answer: " << std::endl;
  TreeNode* ans = sufficientSubset(root, limit);
  levelOrderTraversal(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 40-Insufficient-Nodes-in-root-to-leaf-paths.cpp -o output && ./output

