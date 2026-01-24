
/*
* Lowest Common Ancestor of a Binary Tree III
*
*                    3
*               /        \  
*             5           1
*           /   \       /   \  
*          6     2     0     8
*              /  \     
*             7   4

* Example 1:
* Input:  p = 6, q = 4
* Output: 5

* https://www.naukri.com/code360/problems/lowest-common-ancestor-of-a-binary-tree-iii_1280134
*/

// * Solve this on NeetCode
// ! Meta, Amazon, Google, Microsoft, Apple, LinkedIn

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

typedef struct Node Node;

struct Node {
public:
  int data;
  Node *left;
  Node *right;
  Node *parent;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  }
};

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << "]" << std::endl;
}

void levelOrderTraversal(Node *root) {
  if (!root)
    return;

  std::queue<Node *> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();
    // * traverse the whole level
    while (n--) {
      Node *node = q.front();
      q.pop();

      std::cout << node->data << " ";

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }
    std::cout << std::endl;
  }
}

void tree_to_array(Node* root, std::vector<Node*> &nodes) {
  if (!root)
    return;
  
  nodes.push_back(root);
  tree_to_array(root->left, nodes);
  tree_to_array(root->right, nodes);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(h)
// * SPACE COMPLEXITY O(1)
Node* lowestCommonAncestor(Node* p_start, Node * q_start) {
  Node* p = p_start;
  Node* q = q_start;

  while (p != q) {
    if (p->parent) {
      p = p->parent;
    } else {
      p = q_start;
    }

    if (q->parent) {
      q = q->parent;
    } else {
      q = p_start;
    }
  }
  return p;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Variant 1
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
Node *lowestCommonAncestor2(std::vector<Node *> &nodes, Node *p_start, Node *q_start) {

  // * 1. Map child to it's parents
  std::unordered_map<Node*, Node*> child_to_parent_mp;
  for (auto &node : nodes) {
    if (node->left)
      child_to_parent_mp[node->left] = node;
    if (node->right)
      child_to_parent_mp[node->right] = node;
  }
  // for (auto &[c, p] : child_to_parent_mp) { // * For Debugging
  //   std::cout << c->data << " -> " << p->data << std::endl;
  // }

  // * 2. Same as LCA - 3
  Node* p = p_start;
  Node* q = q_start;

  while (p != q) {
    if (child_to_parent_mp.find(p) != child_to_parent_mp.end()) {
      p = child_to_parent_mp[p];
    } else {
      p = q_start;
    }

    if (child_to_parent_mp.find(q) != child_to_parent_mp.end()) {
      q = child_to_parent_mp[q];
    }
    else {
      q = p_start;
    }
  }
  return p;
}

int main(void) {
  // * Testcase 1
  Node *root = new Node(3);
  root->left = new Node(5);
  root->right = new Node(1);

  root->left->left = new Node(6);
  root->left->right = new Node(2);
  
  root->right->left = new Node(0);
  root->right->right = new Node(8);

  root->left->right->left = new Node(7);
  root->left->right->right = new Node(4);

  Node *p = root->left->left;
  Node *q = root->left->right->right;

  std::vector<Node*> nodes;
  tree_to_array(root, nodes);

  Node* lca = lowestCommonAncestor2(nodes, p, q);
  std::cout << "LCA: " << lca->data << std::endl;

  return 0;
}

// * run the code
// * g++ --std=c++20 46-lowest-common-ancestor-III.cpp -o output && ./output
