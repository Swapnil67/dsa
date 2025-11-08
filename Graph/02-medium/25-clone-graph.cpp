/*
 * Leetcode - 133
 * Clone Graph 
 * 
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.

 * https://leetcode.com/problems/clone-graph/
*/

// ! Google, Amazon, Meta

#include <vector>
#include <iostream>
#include <unordered_map>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }

  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

void dfs(Node *node, Node *clone_node,
         std::unordered_map<Node *, Node *> &nodes) {

  for (auto &ngbr : node->neighbors) {
    // * cannot find clone node of ngbr so we create new node
    if (nodes.find(ngbr) == nodes.end()) {
      Node *clone_ngbr = new Node(ngbr->val);
      nodes[ngbr] = clone_ngbr;
      clone_node->neighbors.push_back(clone_ngbr);
      dfs(ngbr, clone_ngbr, nodes);
    }
    else {
      // * assign already created ngbr node
      clone_node->neighbors.push_back(nodes[ngbr]);
    }
  }
}

Node *cloneGraph(Node *node) {
  if (!node)
    return node;

  // * clone the given node
  Node *clone = new Node(node->val);

  std::unordered_map<Node *, Node *> nodes;
  nodes[node] = clone;

  dfs(node, clone, nodes);

  return clone;
}

int main(void) {
  // * Input Graph
  Node *node_one = new Node(1);
  Node *node_two = new Node(2);
  Node *node_three = new Node(3);
  Node *node_four = new Node(4);

  std::vector<Node *> one_ngbr = {node_two, node_four};
  std::vector<Node *> two_ngbr = {node_one, node_three};
  std::vector<Node *> three_ngbr = {node_two, node_four};
  std::vector<Node *> four_ngbr = {node_one, node_three};

  node_one->neighbors = one_ngbr;
  node_two->neighbors = two_ngbr;
  node_three->neighbors = three_ngbr;
  node_four->neighbors = four_ngbr;
}