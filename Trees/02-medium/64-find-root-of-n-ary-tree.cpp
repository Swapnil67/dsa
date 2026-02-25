/*
 * Leetcode - ?
 * Find Root of N-Ary Tree
 * 
 * You are given all the nodes of an N-ary tree as an array of Node objects, where each node has a unique value.
 * Return the root of the N-ary tree.
 * 
 * https://neetcode.io/problems/find-root-of-n-ary-tree/question?list=allNC
*/

// ! Google, Meta, Bloomberg

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "common.hpp"

using namespace std;

class Node {
public:
  int val;
  vector<Node*> children;

  Node(int v) {
    val = v;
  }
};

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * Use Set Data structure to save all the children
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
Node *findRoot(vector<Node *> tree) {
  unordered_set<Node *> seen;
  for (Node *node : tree) {
    for (Node *child : node->children) {
      seen.insert(child);
    }
  }

  Node *root = nullptr;
  for (Node *node : tree) {
    if (seen.count(node) == 0) {
      root = node;
      break;
    }
  }

  return root;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * Every node except the root appears exactly once as a parent and exactly once as a child. 
// * If we add each node's value as a parent and subtract each child's value, all non-root nodes will cancel out 
// * (added once, subtracted once). The root is only added as a parent but never subtracted as a child,
// * so the final sum equals the root's value.

// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
Node *findRoot(vector<Node *> tree) {
  int value_sum = 0;

  for (Node *node : tree) {
    value_sum += node->val;
    for (Node *child : node->children) {
      value_sum -= child->val;
    }
  }

  for (Node *node : tree) {
    if (node->val == value_sum) {
      return node;
    }
  }

  return nullptr;
}

int main(void) {
  // * Do this on leetcode
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 64-find-root-of-n-ary-tree.cpp -o output && ./output
