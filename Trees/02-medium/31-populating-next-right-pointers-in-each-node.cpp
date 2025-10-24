/*
* Leetcode - 117
* Populating Next Right Pointers in Each Node II

* https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
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


// * ------------------------- APPROACH 1: Brute Force APPROACH -------------------------
// * BFS Brute 
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
TreeNode *connect_bfs_brute(TreeNode *root) {
  if (!root)
    return root;

  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();

    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      if (n > 0) {
        node->next = q.front();
      }

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
  }

  return root;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * BFS Optimal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
TreeNode *connect(TreeNode *root) {
  if (!root)
    return root;

  TreeNode* head = root;
  while (head) {
    TreeNode *dummy = new TreeNode(0);
    TreeNode *temp = dummy;

    // * loop over the current level
    while (head) {
      if (head->left) {
        temp->next = head->left;
        temp = temp->next;
      }

      if (head->right) {
        temp->next = head->right;
        temp = temp->next;
      }

      head = head->next;
    }

    head = dummy->next;
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

  connect_bfs_brute(root);

  return 0;
}

// * Run the code
// * g++ --std=c++20 31-populating-next-right-pointers-in-each-node.cpp -o output && ./output

