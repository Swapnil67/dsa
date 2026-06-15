
/*
* Top View of Binary tree

* Example 1:
* Input: 
*
*                   1
*               /     \  
*             2        3
*           /  \     /  \  
*          4    5   6    7  

* Output: ans = [4, 2, 1, 3, 7]

* https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
* https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401
*/

// ! Amazon, Microsoft, Adobe, Coinbase

#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

// * Vertical Order Traversal
vector<int> topView(TreeNode *root) {
  vector<int> ans;
  if (!root)
    return ans;
    
  // * { vertical, NodeValue }
  map<int, int> nodes;

  // * { vertical, TreeNode* }
  queue<pair<int, TreeNode *>> q;
  q.push({0, root});

  // * level order traversal
  while (!q.empty()) {
    auto [cur_ver, node] = q.front();
    q.pop();

    // cout << cur_ver << endl;
    if (!nodes.count(cur_ver)) {
      nodes[cur_ver] = node->data;     // * Add vertical level to map
    }

    // * Add left node to queue
    if (node->left) {
      q.push({cur_ver - 1, node->left});
    }

    // * Add right node to queue
    if (node->right) {
      q.push({cur_ver + 1, node->right});
    }
  }

  for (auto &it : nodes) {
    ans.push_back(it.second);
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

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "Top View of BT:" << endl;
  vector<int> ans = topView(root);
  printArr(ans);

  return 0;
}


// * run the code
// * g++ --std=c++20 05-top-view-bt.cpp -o output && ./output
