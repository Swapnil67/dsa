/*
* Leetcode - 979
* Distribute Coins in Binary Tree
*
* You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. 
* There are n coins in total throughout the whole tree.
*
* In one move, we may choose two adjacent nodes and move one coin from one node to another.
* A move may be from parent to child, or from child to parent.
*
* Return the minimum number of moves required to make every node have exactly one coin.
*
* Example 1:
* Input       : root = [3,0,0]
* Output      : 2
*
* Example 2:
* Input       : root = [0,3,0]
* Output      : 3
* 
* https://leetcode.com/problems/distribute-coins-in-binary-tree/description/
* https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1
*/

// ! Microsoft

#include <queue>
#include <vector>
#include <iostream>
#include "../common.hpp"

using namespace std;

int dfs(TreeNode *root, int &moves) {
  if (!root)
    return 0;

  int l_coins = dfs(root->left, moves);  // * coins from left
  int r_coins = dfs(root->right, moves); // * coins from right

  // * Here we'll do abs() becoz -ve moves indicates that its going from child to parent
  moves += std::abs(l_coins) + std::abs(r_coins); // * save the moves

  // * send the remaining candies to parent
  // * minus 1 becoz one candy it will keep for itself
  return (root->data + l_coins + r_coins) - 1; 
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * DFS - Bottom Up
// * h - height of tree
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(h) 
int distributeCoins(TreeNode *root) {
  int moves = 0;
  dfs(root, moves);
  return moves;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(0);
  root->right = new TreeNode(0);

  // * testcase 2
  // TreeNode *root = new TreeNode(0);
  // root->left = new TreeNode(3);
  // root->right = new TreeNode(0);

  std::cout << "Input BT" << std::endl;
  levelOrderTraversal(root);

  // * testcase 2
  int ans = distributeCoins(root);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 55-distribute-coins-in-bt.cpp -o output && ./output

