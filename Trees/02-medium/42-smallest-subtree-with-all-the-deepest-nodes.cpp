/*
* Leetcode - 865
* Smallest Subtree with all the Deepest Nodes

* Given the root of a binary tree, the depth of each node is the shortest distance to the root.
* Return the smallest subtree such that it contains all the deepest nodes in the original tree.
* A node is called the deepest if it has the largest depth possible among any node in the entire tree.
* The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.


* Example 1:
*                   3        
*               /       \     
*             5          1
*           /  \        /  \ 
*          6   '2'      0   8
*             /   \           
*           '7'   '4'

* Input       : root = [3,5,1,6,2,0,8,null,null,7,4]
* Output      : [2,7,4]
* Explanation : Deepest leaf nodes are [7, 4] and node '2' is smallest subtree among them

* Example 2:
*                    3        
*               /         \     
*             5            1
*           /  \          /  \ 
*          6   '2'       0   8
*             /   \     /      
*           '7'   '4'  '10'

* Input       : root = [3,5,1,6,2,0,8,null,null,7,4]
* Output      : [3,5,1,6,2,0,8,null,null,7,4]
* Explanation : Deepest leaf nodes are [7, 4, 10] and node '3' (root) is smallest subtree among them


* https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
*/

// ! Google

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "common.hpp"

using namespace std;

// * Maps the depth of each node {node: depth}
void build_depth_map(
    TreeNode *root, int d, int &max_depth,
    unordered_map<TreeNode *, int> &depth_map)
{
  if (!root)
    return;

  depth_map[root] = d;
  max_depth = max(max_depth, d); // * check max_depth

  build_depth_map(root->left, d + 1, max_depth, depth_map);
  build_depth_map(root->right, d + 1, max_depth, depth_map);
}

TreeNode *dfs(TreeNode *root, int &max_depth,
              unordered_map<TreeNode *, int> &depth_map)
{
  // * Found null or node with max depth
  if (!root || max_depth == depth_map[root])
    return root;

  TreeNode *left = dfs(root->left, max_depth, depth_map);
  TreeNode *right = dfs(root->right, max_depth, depth_map);

  // * Found the LCA of max depth nodes
  if (left && right)
    return root;

  return left != nullptr ? left : right;
}

pair<int, TreeNode*> dfs2(TreeNode *root)
{
  // * Found null or node with max depth
  if (!root)
    return {0, nullptr};

  auto [left_depth, left] = dfs2(root->left);
  auto [right_depth, right] = dfs2(root->right);

  // * Found the LCA of max depth nodes
  if (left_depth == right_depth) {
    return {1 + left_depth, root};
  }
  else if(left_depth > right_depth) { // * left depth is mor  e
    return {1 + left_depth, left};
  }
  return {1 + right_depth, right};    // * right depth is more
}

// * ------------------------- APPROACH: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N + N) = O(2N)
// * SPACE COMPLEXITY O(N) 
TreeNode* bruteForce(TreeNode* root) {
  // * 1. Build the depth map
  int max_depth = 0;
  unordered_map<TreeNode *, int> depth_mp;
  build_depth_map(root, 0, max_depth, depth_mp); // * O(N)

  // * For Debugging
  // cout << "Max Depth: " << max_depth << endl;
  // for (auto &[node, depth]: depth_mp) {
  //   cout << node->data << " " << depth << endl;
  // }

  // * 2. Return the LCA of max_depth nodes
  return dfs(root, max_depth, depth_mp); // * O(N)
}

// * ------------------------- APPROACH: OPTIMAL APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) [Recursion Stack] 
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
  // * 1. Return the LCA of max_depth nodes
  return dfs2(root).second; // * O(N)
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(3);
  // root->left = new TreeNode(5);
  // root->right = new TreeNode(1);
  // root->left->left = new TreeNode(6);
  // root->left->right = new TreeNode(2);
  // root->left->right->left = new TreeNode(7);
  // root->left->right->right = new TreeNode(4);
  // root->right->left = new TreeNode(0);
  // root->right->right = new TreeNode(8);

  // * testcase 1
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->right->left->left = new TreeNode(10);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  cout << "Answer: " << endl;
  // TreeNode* ans = bruteForce(root);
  TreeNode* ans = subtreeWithAllDeepest(root);
  levelOrderTraversal(ans);


  return 0;
}

// * Run the code
// * g++ --std=c++20 42-smallest-subtree-with-all-the-deepest-nodes.cpp -o output && ./output

