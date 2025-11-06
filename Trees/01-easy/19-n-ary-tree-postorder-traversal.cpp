/*
 * Leetcode - 590
 * 
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/
*/

// * Do this on leetcode

#include <vector>
#include <iostream>

// * Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
      val = _val;
      children = _children;
    }
};

class Solution {
public:
  void dfs(Node *root, std::vector<int> &res) {
    if (!root)
      return;

    for (Node *child : root->children) {
      dfs(child, res);
    }
    res.push_back(root->val);
  }

  std::vector<int> postorder(Node *root) {
    std::vector<int> res;
    dfs(root, res);
    return res;
  }
};