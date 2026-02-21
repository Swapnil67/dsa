/*
* Leetcode - 1530
* Number of Good Leaf Nodes Pairs

* You are given the root of a binary tree and an integer distance. 
* A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest 
* path between them is less than or equal to distance.

* Return the number of good leaf node pairs in the tree.

* Example 1:
* Input: 
*                  1        
*               /     \     
*             2        3

* Input       : root = [1,2,3,null,4], distance = 3
* Output      : 1
* Explanation : The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. 
*               This is the only good pair.

* Example 2:
* Input: 
*                  1        
*               /     \     
*             2        3
*           /   \    /   \   
*          4    5   6     7

* Input       : root = [1,2,3,4,5,6,7], distance = 3
* Output      : 2
* Explanation : The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not
*               good because the length of ther shortest path between them is 4.
*
*
* https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
*/

// ! Meta, Amazon, tiktok

// ! convert tree to UDG (Undirected Graph)

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "common.hpp"

using namespace std;

// * Builds a Adj list from graph & Save the leave nodes to set
void makeGraph(TreeNode *root, TreeNode *prev,
               unordered_set<TreeNode *> &leaves,
               unordered_map<TreeNode *, vector<TreeNode *>> &adj)
{
  if (!root)
    return;

  // * Save the leaf node to set
  if (!root->left && !root->right) {
    leaves.insert(root);
  }

  if (prev) {
    adj[root].push_back(prev);
    adj[prev].push_back(root);
  }

  makeGraph(root->left, root, leaves, adj);
  makeGraph(root->right, root, leaves, adj);
}

// ! TLE
int bfs_brute(int &distance, TreeNode *leaf,
              unordered_set<TreeNode *> &leaves,
              unordered_map<TreeNode *, vector<TreeNode *>> &adj)
{

  int pairs = 0;
  if (!leaf)
    return pairs;

  queue<pair<TreeNode *, int>> q;
  q.push({leaf, 0});

  unordered_set<TreeNode *> visited;
  visited.insert(leaf);

  while (!q.empty()) {
    auto [node, dist] = q.front();
    q.pop();

    if (node != leaf && leaves.count(node)) {
      if (dist <= distance) {
        pairs += 1;
      }
    }

    for (auto &ngbr : adj[node]) {
      if (!visited.count(ngbr)) {
        visited.insert(ngbr);
        q.push({ngbr, dist + 1});
      }
    }
  }

  return pairs;
}

// * BFS Traversal
int bfs(int distance, TreeNode *root,
        unordered_set<TreeNode *> &leaves,
        unordered_map<TreeNode *, vector<TreeNode *>> &adj)
{
  int good_pairs = 0;
  if (!root)
    return good_pairs;

  unordered_set<TreeNode *> visited;
  visited.insert(root);

  queue<TreeNode *> q;
  q.push(root);

  int level = 0;
  while (!q.empty()) {
    int n = q.size();
    while (n--) {
        TreeNode* node = q.front();
        q.pop();

        // * Found a leaf node
        if (leaves.count(node) && node != root) {
            good_pairs++;
        }

        // * Visit neighbours
        for (auto& ngbr : adj[node]) {
            if (!visited.count(ngbr)) {
              visited.insert(ngbr); // * Mark node as visited
              q.push(ngbr);
            }
        }
    }

    level += 1;

    if (level > distance)
        break;
  }

  return good_pairs;
}

// * ------------------------- APPROACH 1: OPTIMAL APPROACH -------------------------
// * convert tree to UDG (Undirected Graph)
// * Find shortest distance b/w all leaf nodes (BFS)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int countPairs(TreeNode* root, int distance) {
  int good_pairs = 0;
  if (!root)
    return good_pairs;

  // * 1. convert tree to a UDG
  unordered_map<TreeNode *, vector<TreeNode *>> adj;
  unordered_set<TreeNode *> leaves;
  makeGraph(root, NULL, leaves, adj);

  // * 2. Do BFS from leaf to other leaf nodes
  for (auto &leaf : leaves) {
    // cout << leaf->data << endl;
    // * BFS to another leaf node
    int cur_pairs = bfs(distance, leaf, leaves, adj);
    good_pairs += cur_pairs;
  }

  return good_pairs / 2;
}

int main(void) {
  // * testcase 1
  // int distance = 3;
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->right = new TreeNode(4);

  // * testcase 1
  int distance = 3;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "Input Binary Tree:" << endl;
  levelOrderTraversal(root);

  int ans = countPairs(root, distance);
  cout << "Number of Good Leaf Nodes Pairs: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 34-no-of-good-leaf-nodes-pairs.cpp -o output && ./output

