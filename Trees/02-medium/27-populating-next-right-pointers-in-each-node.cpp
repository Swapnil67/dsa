/*
* Leetcode - 116
* Populating Next Right Pointers in Each Node

* https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef struct Node Node;

struct Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node* next;
  
  Node(int val) {
    data = val;
    left = right = next = nullptr;
  }
};

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * BFS using queue
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
Node *connect_bfs_brute(Node *root) {
  if (!root)
    return root;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    while (n) {
      Node *node = q.front();
      q.pop();

      // * Connect of cur level has next node
      if (n > 1)
        node->next = q.front();

      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);

      n--;
    }
  }

  return root;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * BFS + dummy nodes
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
Node *connect(Node *root) {
  if (!root)
    return root;

  Node* head = root;
  while (head) {
    Node *dummy = new Node(0);
    Node *temp = dummy;

    // * loop over the current level
    while (head) {
      if (head->left) {
        temp->next = head->left;
        temp = temp->next;
      }

      if (head->right) {
        temp->next = head->right;
        temp = temp->next;
      }

      head = head->next;
    }

    head = dummy->next;
  }

  return root;
}

int main(void) {
  // * testcase 1
  // * tree 1
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  // connect_bfs_brute(root);
  connect(root);

  return 0;
}

// * Run the code
// * g++ --std=c++17 27-populating-next-right-pointers-in-each-node.cpp -o output && ./output

