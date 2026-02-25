/*
 * Leetcode - ?
 * Clone N-ary Tree
 * 
 * Given a root of an N-ary tree, return a deep copy (clone) of the tree.
 * Each node in the n-ary tree contains a val (int) and a list (List[Node]) of its children.
 * 
 * https://neetcode.io/problems/clone-n-ary-tree/question
*/

// ! Amazon

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
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
// * DFS 
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) - [Clone Tree Space]
Node* cloneTreeDFS(Node* root) {
  if (!root)
    return root;

  Node* clone = new Node(root->val);

  for (auto &child: root->children) {
    clone->children.push_back(cloneTreeDFS(child));
  }

  return clone;
}

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * BFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) - [Clone Tree Space]
Node* cloneTreeBFS(Node* root) {
  if (!root)
    return root;

  Node* new_root = new Node(root->val);
  queue<pair<Node*, Node*>> q;
  q.push({root, new_root});

  while (!q.empty()) {
    auto [old_node, new_node] = q.front();
    q.pop();

    for (auto &child_node: old_node->children) {
      Node* new_child_node = new Node(child_node->val); 
      new_node->children.push_back(new_child_node);
      q.push({child_node, new_child_node});
    }
  }

  return new_root;
}

int main(void) {
  // * Do this on leetcode
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 63-clone-n-ary-tree.cpp -o output && ./output
