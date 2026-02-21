/*
* Leetcode - 652
* Find Duplicate Subtrees

* Given the root of a binary tree, return all duplicate subtrees.
* For each kind of duplicate subtrees, you only need to return the root node of any one of them.
* Two trees are duplicate if they have the same structure with the same node values.

* Example 1:
* Input: 
*                   2       
*               /      \     
*             2         2
*           /         /  
*          3        3

* Input: root = [2,2,2,3,null,3,null]
* Output: [[2,3],[3]]

* Example 2:
* Input: 
*                  1        
*               /     \     
*             2        3
*           /        /   \  
*          4        2    4
*                  /  
*                 4   

* Input: root = [1,2,3,4,null,2,4,null,null,4]
* Output: [[2,4],[4]]

* https://leetcode.com/problems/find-duplicate-subtrees/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "common.hpp"

using namespace std;

void preorder(TreeNode *root, vector<TreeNode *> &subTree) {
  if (!root)
    return;

  subTree.push_back(root);
  preorder(root->left, subTree);
  preorder(root->right, subTree);
}

bool same(TreeNode *p, TreeNode *q) {
  if (!p && !q)
    return true;

  if (!p || !q)
    return false;

  return (p->data == q->data) &&
         same(p->left, q->left) &&
         same(p->right, q->right);
}

string dfs(
    TreeNode *node,
    vector<TreeNode *> &res,
    unordered_map<string, int>&mp)
{
  if (!node)
    return "n";

  string s = to_string(node->data) + "," +
                  dfs(node->left, res, mp) + "," +
                  dfs(node->right, res, mp);

  // * If we have seen this subtree earlier add to result
  if (mp[s] == 1)
    res.push_back(node);

  mp[s]++; // * Incr the subtree freq
  
  return s;
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(n^3)
// * SPACE COMPLEXITY O(n)
vector<TreeNode *> bruteForce(TreeNode *root) {
  vector<TreeNode *> ans;

  // * 1. Save all nodes into a vector
  vector<TreeNode *> subTree;
  preorder(root, subTree);

  // * 2. Compare each subtree with another
  int n = subTree.size();
  unordered_set<TreeNode *> seen;
  for (int i = 0; i < n; ++i) {
    if (seen.count(subTree[i]))
      continue;

    for (int j = i + 1; j < n; ++j) {
      if (seen.count(subTree[j]))
        continue;

      if (same(subTree[i], subTree[j])) {
        if (!seen.count(subTree[i])) {
          ans.push_back(subTree[i]);
          seen.insert(subTree[i]);
        }
        seen.insert(subTree[j]);
      }
    }
  }

  return ans;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
  vector<TreeNode *> res;
  unordered_map<string, int> mp;
  dfs(root, res, mp);

  // * For debugging (All Unique subtrees)
  // for(auto &[key, val]: mp) {
  //   cout << "'" << key  << "': " << val << endl;
  // }

  return res;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(4);
  root->right->right = new TreeNode(4);

  // * testcase 1
  // TreeNode *root = new TreeNode(2);
  // root->left = new TreeNode(1);
  // root->right = new TreeNode(11);
  // root->left->left = new TreeNode(11);
  // root->right->left = new TreeNode(1);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  // vector<TreeNode *> ans = bruteForce(root);
  vector<TreeNode *> ans = findDuplicateSubtrees(root);
  cout << "Duplicate Subtrees: " << endl;
  for (auto &tree : ans) {
    cout << "subtree: " << endl;
    levelOrderTraversal(tree);
  }

  return 0;
}

// * Run the code
// * g++ --std=c++20 28-find-duplicate-subtrees.cpp -o output && ./output

