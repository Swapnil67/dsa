
/*
* Leetcode - 199
* Right View of Binary tree

* Example 1:
* Input: 
*
*                  1
*               /     \  
*             2        3
*           /  \        \  
*          4    5        7  
*              /
*             6


* Output: ans = [1, 3, 7, 6]

* https://leetcode.com/problems/binary-tree-right-side-view/
* https://www.naukri.com/code360/problems/right-view_764605
* https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
*/

#include "../common.hpp"

// * Recursive Pre Order Traversal (Root -> Right -> Left)
void dfs(TreeNode *root, vector<int> &ans, int level) {
  if (!root)
    return;

  // * To get the last node from level
  if (level == ans.size())
    ans.push_back(root->data);

  dfs(root->right, ans, level + 1); // * First go to right
  dfs(root->left, ans, level + 1); // * Then check on left
}

// * DFS
vector<int> rightViewDFS(TreeNode *root) {
  vector<int> ans;
  dfs(root, ans, 0);
  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Using Level Order Traversal
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<int> rightViewBFS(TreeNode *root) {
  vector<int> ans;
  if (!root)
    return ans;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();

      if (i == n - 1)
        ans.push_back(node->data);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
  }

  return ans;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Variant1: Print Both Left & right side view in clockwise order (Do not repeat root node)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<int> rightViewVariant1(TreeNode *root) {
  vector<int> ans;
  if (!root)
    return ans;

  queue<TreeNode *> q;
  q.push(root);

  vector<int> left_side;
  vector<int> right_side;

  while (!q.empty()) {
    int n = q.size();
    for (int i = 0; i < n; ++i) {
      TreeNode *node = q.front();
      q.pop();

      if (i == 0)
        left_side.push_back(node->data);
      if (i == n - 1)
        right_side.push_back(node->data);

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
  }

  // * Merge two left_side & right_side clockwise
  for (int i = left_side.size() - 1; i >= 0; --i)
    ans.push_back(left_side[i]);
  for (int i = 1; i < right_side.size(); ++i)
    ans.push_back(right_side[i]);
  
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

  cout << "Input Tree" << endl;
  levelOrderTraversal(root);

  cout << "Right view of the BT" << endl;
  // vector<int> ans = rightViewDFS(root);
  // vector<int> ans = rightViewBFS(root);
  vector<int> ans = rightViewVariant1(root);
  printArr(ans);

  return 0;
}


// * run the code
// * g++ --std=c++20 07-right-view-bt.cpp -o output && ./output

