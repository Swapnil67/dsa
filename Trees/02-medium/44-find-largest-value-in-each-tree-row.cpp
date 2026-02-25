/*
* Leetcode - 515
* Find Largest Value in Each Tree Row

* Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

* Example 1:
* Input : root = [1,3,2,5,3,null,9]
*                  4        
*               /     \     
*             2        6
*           /  \      /
*          3    1    5

* Output: [1,3,9]

* https://leetcode.com/problems/find-largest-value-in-each-tree-row
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include "common.hpp"

using namespace std;

// * ------------------------- APPROACH: OPTIMAL APPROACH -------------------------
// * BFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<int> largestValues(TreeNode *root) {
  if (!root)
    return {};
    
  vector<int> ans;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int N = q.size();
    int cur_max = INT_MIN;
    while (N--) {
      auto node = q.front();
      q.pop();

      cur_max = max(cur_max, node->data);

      if (node->left) {
        q.push(node->left);
      }

      if (node->right) {
        q.push(node->right);
      }
    }
    ans.push_back(cur_max);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(3);
  // root->right = new TreeNode(2);
  // root->left->left = new TreeNode(5);
  // root->left->right = new TreeNode(3);
  // root->right->right = new TreeNode(9);

  // * testcase 2
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  vector<int> ans = largestValues(root);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 44-find-largest-value-in-each-tree-row.cpp -o output && ./output

