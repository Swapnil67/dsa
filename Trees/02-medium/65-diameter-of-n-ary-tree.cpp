/*
 * Leetcode - ?
 * Diameter of N-Ary Tree
 * 
 * Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.
 * 
 * The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree. 
 * This path may or may not pass through the root.
 * 
 * (Nary-Tree input serialization is represented in their level order traversal, each group of children 
 * is separated by the null value.)
 * 
 * https://neetcode.io/problems/diameter-of-n-ary-tree
*/

// ! Meta

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
// * g++ --std=c++20 65-diameter-of-n-ary-tree.cpp -o output && ./output
