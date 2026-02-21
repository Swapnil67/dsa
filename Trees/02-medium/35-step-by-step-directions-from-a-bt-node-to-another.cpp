/*
  * Leetcode - 2096
  * Step-By-Step Directions From a Binary Tree Node to Another

  * You are given the root of a binary tree with n nodes. 
  * Each node is uniquely assigned a value from 1 to n. 
  * You are also given an integer startValue representing the value of the start node s, and a different integer
  * destValue representing the value of the destination node t.

  * Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path
  * as a string consisting of only the uppercase letters 'L', 'R', and 'U'. 

  * Each letter indicates a specific direction:
  * - 'L' means to go from a node to its left child node.
  * - 'R' means to go from a node to its right child node.
  * - 'U' means to go from a node to its parent node.

  * Return the step-by-step directions of the shortest path from node s to node t.

  * Example 1:
  * Input: 
  *                  5        
  *               /     \     
  *             1        2
  *            /        /  \  
  *           3       6     4

  * Input       : root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
  * Output      : "UURL"
  * Explanation : The shortest path is: 3 → 1 → 5 → 2 → 6.


  * https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another
  * https://www.naukri.com/code360/problems/finding-paths_1281314
  * https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
*/

// ! Google, Amazon

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

TreeNode* find_lca(TreeNode* root, int start, int dest) {
  if (!root || root->data == start || root->data == dest)
    return root;

  TreeNode* left = find_lca(root->left, start, dest);
  TreeNode* right = find_lca(root->right, start, dest);

  if (left && right)
    return root;

  return left != nullptr ? left : right;
}

// * Root to Node
bool root_to_node(TreeNode *root, string &path, int target) {
  if (!root)
    return false;
  // cout << path << endl;

  // * Found the target node
  if (root->data == target) {
    return true;
  }

  // * If we found node in 'left' or 'right' return
  path.push_back('L');
  if (root_to_node(root->left, path, target)) {
    return true;
  }

  path.pop_back();
  path.push_back('R');
  if (root_to_node(root->right, path , target)) {
    return true;
  }

  path.pop_back();
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// ! Memory Limit Exceeded
// * 1. Find LCA for Src & Dest
// * 2. Find Path from LCA to Src
// * 3. Find Path from LCA to dest
// * TIME COMPLEXITY O(3N) ~ O(N)
// * SPACE COMPLEXITY O(N)
string bruteForce(TreeNode* root, int src, int dest) {
  // * 1. Find LCA for Src & Dest
  TreeNode *lca = find_lca(root, src, dest);
  // cout << "LCA : " << lca->data << endl;
  
  // * 2. Find Path from LCA to src
  string lca_to_src = "";
  root_to_node(lca, lca_to_src, src);
  // cout << "lca_to_src : " << lca_to_src << endl;
  
  // * 3. Find Path from LCA to Dest
  string lca_to_dest = "";
  root_to_node(lca, lca_to_dest, dest);
  // cout << "lca_to_dest : " << lca_to_dest << endl;

  string ans(lca_to_src.size(), 'U');
  ans += lca_to_dest;

  return ans;
}

// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * 1. Find Path from root to Src
// * 2. Find Path from root to dest
// * TIME COMPLEXITY O(2N) ~ O(N)
// * SPACE COMPLEXITY O(N)
string getDirections(TreeNode* root, int src, int dest) {
  // * 1. Find Path from root to src
  string root_to_src = "";
  root_to_node(root, root_to_src, src);
  // cout << "root_to_src : " << root_to_src << endl;
  
  // * 2. Find Path from root to Dest
  string root_to_dest = "";
  root_to_node(root, root_to_dest, dest);
  // cout << "root_to_dest : " << root_to_dest << endl;

  // * The LCA Will be point at which both directions changed
  int i = 0;
  while (root_to_src[i] == root_to_dest[i])
    i++;

  string ans(root_to_src.size() - i, 'U');
  ans += root_to_dest.substr(i, root_to_dest.size());

  return ans;
}

int main(void) {
  // * testcase 1
  // int startValue = 3, destValue = 6;
  // TreeNode *root = new TreeNode(5);
  // root->left = new TreeNode(1);
  // root->right = new TreeNode(2);
  // root->left->left = new TreeNode(3);
  // root->right->left = new TreeNode(6);
  // root->right->right = new TreeNode(4);

  // * testcase 2
  int startValue = 3, destValue = 6;
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(6);
  root->left->left->left = new TreeNode(3);
  root->right->right = new TreeNode(2);
  root->right->right->right = new TreeNode(4);

  // * testcase 3
  // int startValue = 2, destValue = 1;
  // TreeNode *root = new TreeNode(2);
  // root->left = new TreeNode(1);

  cout << "start: " << startValue << ", dest: " << destValue << endl;
  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  // string ans = bruteForce(root, startValue, destValue);
  string ans = getDirections(root, startValue, destValue);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 35-step-by-step-directions-from-a-bt-node-to-another.cpp -o output && ./output

