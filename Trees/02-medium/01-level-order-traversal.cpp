/*
 * Leetcode - 102
 * Binary Tree Level Order Traversal 
 * 
 * Example 1:
 * Input  : root = [3,9,20,null,null,15,7]
 * Output : [[3],[9,20],[15,7]]
 * 
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

#include <queue>
#include <vector>
#include <iostream>
#include "../common.hpp"

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> ans;

  if (root == nullptr)
    return ans;

  // * Create the queue of TreeNode and push the root node
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    vector<int> level;
    int size = q.size();
    for(int i = 0; i < size; ++i) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      // cout << node->data << endl;
    }
    ans.push_back(level);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  vector<vector<int>> ans = levelOrder(root);

  cout << "Level Order Traversal:" << endl;
  for (auto &vec : ans)
    printArr(vec);

  return 0;
}


// * Run the code
// * g++ --std=c++20 01-level-order-traversal.cpp -o output && ./output
