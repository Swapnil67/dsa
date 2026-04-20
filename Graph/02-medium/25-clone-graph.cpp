/*
 * Leetcode - 133
 * Clone Graph
 *
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.

 * https://leetcode.com/problems/clone-graph/
 * https://neetcode.io/problems/clone-graph/
*/

// ! Google, Amazon, Meta

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// * Follow up question
class Graph {
public:
  vector<Node *> roots;
  Graph() {
    roots = vector<Node *>();
  }
};

void dfs(Node *&node,
         Node *&clone_node,
         unordered_map<Node *, Node *> &nodes_mp)
{
  // * Visit neighbours
  for (auto &ngbr : node->neighbors) {
    // * cannot find clone node of ngbr so we create new node
    if (nodes_mp.find(ngbr) == nodes_mp.end()) {
      Node *clone_ngbr = new Node(ngbr->val);
      nodes_mp[ngbr] = clone_ngbr;

      clone_node->neighbors.push_back(clone_ngbr);
      dfs(ngbr, clone_ngbr, nodes_mp);
    }
    else {
      // * assign already created ngbr node
      clone_node->neighbors.push_back(nodes_mp[ngbr]);
    }
  }
}

// * ------------------------- Approach: Optimal Approach -------------------------
// * N = Total no of nodes in graph
// * E = Total no of edges in graph
// * TIME COMPLEXITY O(N + E)
// * SPACE COMPLEXITY O(N)
Node *cloneGraph(Node *node) {
  if (!node)
    return node;

  // * clone the given node
  Node *clone = new Node(node->val);

  // * Create an unordered_map to prevent creating duplicate nodes
  unordered_map<Node *, Node *> nodes_mp;
  nodes_mp[node] = clone;

  dfs(node, clone, nodes_mp);

  return clone;
}

int main(void) {
  // * Input Graph
  Node *node_one = new Node(1);
  Node *node_two = new Node(2);
  Node *node_three = new Node(3);
  Node *node_four = new Node(4);

  vector<Node *> one_ngbr = {node_two, node_four};
  vector<Node *> two_ngbr = {node_one, node_three};
  vector<Node *> three_ngbr = {node_two, node_four};
  vector<Node *> four_ngbr = {node_one, node_three};

  node_one->neighbors = one_ngbr;
  node_two->neighbors = two_ngbr;
  node_three->neighbors = three_ngbr;
  node_four->neighbors = four_ngbr;
}

