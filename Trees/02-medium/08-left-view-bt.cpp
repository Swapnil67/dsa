
/*
* Left View of Binary tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \        \  
*          4    5        7  
*              /
*             6


* Output: ans = [1, 2, 4, 6]

* https://www.naukri.com/code360/problems/left-view-of-binary-tree_625707
* https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
*/

// ! Amazon, Apple, Uber, Adobe, Razorpay

#include "../common.hpp"

// * Recursive Pre Order Traversal (Root -> Left -> Right)
void dfs(TreeNode *root, vector<int> &ans, int level) {
  if (!root)
    return;

  // * To get the first node from level
  if (level == ans.size())
    ans.push_back(root->data);

  dfs(root->left, ans, level + 1);
  dfs(root->right, ans, level + 1);
}

// * DFS
vector<int> leftViewDFS(TreeNode *root) {
  vector<int> ans;
  dfs(root,ans,0);
  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using Level Order Traversal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<int> leftViewBFS(TreeNode *root) {
  vector<int> ans;
  if (!root)
    return ans;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    vector<int> level;
    while (n--) {
      TreeNode *node = q.front();
      q.pop();

      level.push_back(node->data);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    ans.push_back(level[0]);
  }

  return ans;
}

int main() {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);

  root->right->right = new TreeNode(7);
  
  cout << "Left view of the BT" << endl;
  vector<int> ans = leftViewDFS(root);
  // vector<int> ans = leftViewBFS(root);
  printArr(ans);

  return 0;
}


// * run the code
// * g++ --std=c++20 08-left-view-bt.cpp -o output && ./output
