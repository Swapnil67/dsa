/*
* Leetcode - 116
* Populating Next Right Pointers in Each Node

* https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
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
    TreeNode* next;
  
  TreeNode(int val) {
    data = val;
    left = right = next = nullptr;
  }
};

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * BFS using queue
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
TreeNode *connect_bfs_brute(TreeNode *root) {
  if (!root)
    return root;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    while (n) {
      TreeNode *node = q.front();
      q.pop();

      // * Connect of cur level has next node
      if (n > 1)
        node->next = q.front();

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);

      n--;
    }
  }

  return root;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * BFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
TreeNode *connect_bfs_optimal(TreeNode *root) {
  if (!root)
    return root;

  TreeNode *cur = root, *nxt = root->left;

  while (cur && nxt) {
    std::cout << cur->data << std::endl;
    cur->left->next = cur->right;
    if (cur->next) {
      cur->right->next = cur->next->left;
    }

    // * Move to the next node in current level
    cur = cur->left;
    if (!cur) {
      cur = nxt;
      nxt = cur->left;
    }
  }

  return root;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) (Auxillary recursion stack space)
TreeNode *connect_dfs(TreeNode *root) {
  if (!root)
    return root;

  if (root->left) {
    // * For left node
    root->left->next = root->right;

    if (root->next) {
      // * For right node
      root->right->next = root->next->left;
    }

    connect_dfs(root->left);
    connect_dfs(root->right);
  }

  return root;
}

int main(void) {
  // * testcase 1
  // * tree 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // connect_dfs(root);
  // connect_bfs_brute(root);
  connect_bfs_optimal(root);

  return 0;
}

// * Run the code
// * g++ --std=c++17 27-populating-next-right-pointers-in-each-node.cpp -o output && ./output

