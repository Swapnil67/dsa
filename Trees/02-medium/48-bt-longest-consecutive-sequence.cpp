/*
* Leetcode - PAID
* Longest Consecutive Sequence In A Binary Tree

* Given a binary tree, return the length of the longest path which has consecutive integers in increasing order 
* from root to leaves. 

* A path is defined as a sequence of nodes which share an edge between them.

* Example 1:
* Input : root = [1,null,3,2,4,null,null,null,5]
*                  1        
*                    \     
*                     3
*                   /   \     
*                  2     4
*                          \
*                           5
* Output: 3

* Example 2:
* Input : root = [2,null,3,2,null,1]
*                  2        
*                    \     
*                     3
*                   /       
*                  2    
*                 /
*                1
* Output: 2

* https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
* https://neetcode.io/problems/binary-tree-longest-consecutive-sequence/question
* https://www.naukri.com/code360/problems/longest-consecutive-sequence-in-a-binary-tree_977251
* https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1
*/

// ! Google, Amazon, Tiktok, Walmart, IBM

#include <queue>
#include <vector>
#include <iostream>
#include "common.hpp"

using namespace std;

// * For every node we check if it's equal to its parent_val
void dfs(int cur, int &ans, int parent_val, TreeNode* root) {
  if (!root)
    return;
  
  // * Check if we have an increasing node [3 -> 4 -> 5]
  if (root->data - 1 == parent_val) {
    cur += 1;
  } else {
    cur = 1; // * reset the count
  }
  
  ans = max(ans, cur);
  dfs(cur, ans, root->data, root->left);
  dfs(cur, ans, root->data, root->right);
}

// * ------------------------- APPROACH: OPTIMAL APPROACH -------------------------
// * DFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(h) 
int longestConsecutive(TreeNode* root) {
  int ans = 0;
  if (!root)
    return ans;

  dfs(1, ans, -1, root);
  return ans;
}

int main(void) {
  // * testcase 1
  // TreeNode *root = new TreeNode(1);
  // root->right = new TreeNode(3);
  // root->right->left = new TreeNode(2);
  // root->right->right = new TreeNode(4);
  // root->right->right->right = new TreeNode(5);

  // * testcase 2
  TreeNode *root = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(1);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  int ans = longestConsecutive(root);
  cout << "Longest Consecutive Sequence: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 48-longest-consecutive-sequence-in-a-bt.cpp -o output && ./output

