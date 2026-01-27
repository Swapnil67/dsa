/*
* Closest Binary Search Tree Value
*
* https://www.naukri.com/code360/problems/closest-element-in-bst_920449
* https://leetcode.com/problems/closest-binary-search-tree-value/description/
* https://www.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
*/

// ! Adobe, Amazon, Google, Meta, Microsoft, Oracle

#include <vector>
#include <climits>
#include <iostream>

struct TreeNode {
  public:
  int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
      data = v;
      left = nullptr;
      right = nullptr;
    }

    TreeNode(int v, TreeNode* l, TreeNode* r) {
      data = v;
      left = l;
      right = r;
    }

    ~TreeNode() {
      if (left)
        delete left;
      if (right)
        delete right;
    }
};

void inorder(TreeNode* root, double target, double closest, int &ans) {
  if (!root)
    return;

  inorder(root->left, target, closest, ans);

  double distance = std::abs(root->data - target);
  if (distance == 0) {
    ans = root->data;
    return;
  }

  if (closest > distance || (closest == distance && root->data < ans)) {
    closest = distance;
    ans = root->data;
  }

  inorder(root->right, target, closest, ans);
}

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * n - nodes in binary tree
// * TIME COMPLEXITY  O(n)
// * SPACE COMPLEXITY O(n)
int bruteForce(TreeNode* root, double target) {
  double closest = INT_MAX;
  int ans = 0;
  inorder(root, target, closest, ans);
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * H = height of BST
// * TIME COMPLEXITY  O(logn) or O(H)
// * SPACE COMPLEXITY O(1)
int closestValue(TreeNode* root, double target) {
  if (!root)
    return 0;

  int ans;
  double closest = INT_MAX;
  while (root) {
    double dist = abs(root->data - target);
    if (dist == 0)
      return root->data;

    // * Case 1: Current distance is more closer than previous
    // * Case 2: Both distance are equal then we choose the lower answer
    if (closest > dist || (dist == closest && root->data < ans)) {
      closest = dist;
      ans = root->data;
    }

    root = target < root->data ? root->left : root->right;
  }

  return ans;
}

int main(void) {
  TreeNode *root = new TreeNode(20);
  root->left = new TreeNode(10);
  root->right = new TreeNode(35);
  
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(15);
  root->left->right->left = new TreeNode(13);

  root->right->left = new TreeNode(30);
  root->right->right = new TreeNode(42);

  int k = 32;

  std::cout << "k: " << k << std::endl;
  int ans = closestValue(root, k);
  std::cout << "Closest node: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-closest-in-bst.cpp -o output && ./output
