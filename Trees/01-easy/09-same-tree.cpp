/*
* Leetcode - 100
* Same Tree

* https://leetcode.com/problems/same-tree/
* https://www.naukri.com/code360/problems/check-identical-trees_799364
* https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

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
  if (!p || !q)
    return (p == q);

  return (p->data == q->data &&
          isSameTree(p->left, q->left) &&
          isSameTree(p->right, q->right));
}

// * Using Queue BFS
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY Worst Case = O(n)
bool isSameTreeBFS(TreeNode *p, TreeNode *q) {
  if (!p && !q) // * Two empty roots
    return true;

  if (!p || !q) // * One empty root
    return false;

  queue<TreeNode *> q1, q2;
  q1.push(p);
  q2.push(q);

  while (!q1.empty() && !q2.empty()) {
    TreeNode *node1 = q1.front();
    q1.pop();

    TreeNode *node2 = q2.front();
    q2.pop();

    if (node1->data != node2->data)
      return false;

    // * Both trees have left node
    if (node1->left && node2->left) {
      q1.push(node1->left);
      q2.push(node2->left);
    } else if (node1->left || node2->left) { // * One of tree does not have left node
      return false;
    }

    // * Both trees have right node
    if (node1->right && node2->right) {
      q1.push(node1->right);
      q2.push(node2->right);
    } 
    else if (node1->right || node2->right) { // * One of tree does not have right node
      return false;
    }
  }
  return true;
}

int main(void) {
  // * testcase 1
  // * tree 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  
  // * tree 2
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);

  // * testcase 2
  // * tree 1
  // TreeNode *root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(1);
  
  // * tree 2
  // TreeNode *root2 = new TreeNode(1);
  // root2->left = new TreeNode(1);
  // root2->right = new TreeNode(2);
  
  // bool ans = isSameTree(root, root2);
  bool ans = isSameTreeBFS(root, root2);
  cout << "Is same trees: " << ans << endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 09-same-tree.cpp -o output && ./output

