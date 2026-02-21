/*
* Leetcode - 958
* Check Completeness of a Binary Tree

* Given the root of a binary tree, determine if it is a complete binary tree.
* In a complete binary tree, every level, except possibly the last, is completely filled, and 
* all nodes in the last level are as far left as possible. 
* It can have between 1 and 2h nodes inclusive at the last level h.

* Example 1:
* Input: 
*                   1        
*               /      \     
*             2         3
*           /  \      /   \  
*          4    5    6    x

* Input: root = [1,2,3,4,5,6]
* Output: true

* Example 2:
* Input: 
*                   1        
*               /      \     
*             2         3
*           /  \      /   \  
*          4    5    x    7

* Input: root = [1,2,3,4,5,null,7]
* Output: false

* https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
* https://www.naukri.com/code360/problems/check-whether-binary-tree-is-complete_1280147
* https://www.geeksforgeeks.org/problems/complete-binary-tree/1
*/

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

int countNodes(TreeNode* root) {
  if (!root)
    return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

bool dfs(TreeNode* root, int i, int &total_nodes) {
  if (!root)
    return true;

  if (i > total_nodes)
    return false;

  return dfs(root->left, (2 * i), total_nodes) &&
         dfs(root->right, (2 * i + 1), total_nodes);
}

// * BFS
bool isCompleteTreeBFS(TreeNode* root) {
  queue<TreeNode *> q;
  q.push(root);

  bool past = false;
  while(!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr) {
      past = true;
    }
    else {
      // * Did we saw any null nodes in past
      if (past == true)
        return false;
      
      q.push(node->left);
      q.push(node->right);
    }
  }

  return true;
}

// * DFS
bool isCompleteTreeDFS(TreeNode* root) {
  int total_nodes = countNodes(root);
  cout << "Total Nodes " << total_nodes << endl;

  int i = 1;
  return dfs(root, i, total_nodes);
}

int main(void) {
  // * testcase 1
  // TreeNode* root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->right->left = new TreeNode(6);

  // * testcase 2
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(7);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  // bool ans = isCompleteTreeBFS(root);
  bool ans = isCompleteTreeDFS(root);
  cout << "Is BT complete: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 26-check-if-complete-bt.cpp -o output && ./output

