/*
* Leetcode - 100
* Same Tree

* https://leetcode.com/problems/same-tree/
*/

#include <queue>
#include <vector>
#include <iostream>

typedef struct TreeNode TreeNode;

struct TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  
  TreeNode(int val) {
    data = val;
    left = right = nullptr;
  }
};


// * Using Recursion DFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == nullptr || q == nullptr) {
    return (p == q);
  }

  return (p->data == q->data &&
          isSameTree(p->left, q->left) &&
          isSameTree(p->right, q->right));
}

// * Using Queue BFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
bool isSameTreeBFS(TreeNode *p, TreeNode *q) {
  if (!p && !q)
    return true;

  if (!p || !q)
    return false;

  std::queue<TreeNode *> q1, q2;
  q1.push(p);
  q2.push(q);

  while (!q1.empty() && !q2.empty()) {
    int n1 = q1.size();
    int n2 = q2.size();

    TreeNode* node1 = q1.front();
    TreeNode* node2 = q2.front();
    q1.pop(), q2.pop();

    if (node1->data != node2->data)
      return false;

    // * Both trees have left node
    if (node1->left != nullptr && node2->left != nullptr) {
      q1.push(node1->left);
      q2.push(node2->left);
    } else if (node1->left != nullptr || node2->left != nullptr) {
      // * One of tree does not have left node
      return false;
    }

    // * Both trees have right node
    if (node1->right != nullptr && node2->right != nullptr) {
      q1.push(node1->right);
      q2.push(node2->right);
    } else if (node1->right != nullptr || node2->right != nullptr) {
      // * One of tree does not have right node
      return false;
    }
  }
  return true;
}

int main(void) {
  // * testcase 1
  // * tree 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  
  // * tree 2
  // TreeNode *root2 = new TreeNode(1);
  // root2->left = new TreeNode(2);
  // root2->right = new TreeNode(3);

  // * testcase 2
  // * tree 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(1);
  
  // * tree 2
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(2);
  

  // bool ans = isSameTree(root, root2);
  bool ans = isSameTreeBFS(root, root2);
  std::cout << "Is same trees: " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 09-same-tree.cpp -o output && ./output

