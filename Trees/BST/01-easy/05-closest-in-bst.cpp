/*
* Closest Binary Search Tree Value
*
* https://www.naukri.com/code360/problems/closest-element-in-bst_920449
* https://www.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1
*/

// ! Adobe

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

// * TIME COMPLEXITY  O(logn)
// * SPACE COMPLEXITY O(1)
int findClosestElement(TreeNode *root, int k) {
  if (!root)
    return 0;

  int ans ;
  int closest_dist = INT_MAX;

  while (root) {
    int dist = std::abs(root->data - k);
    if (closest_dist >= dist && root->data < ans) {
      closest_dist = dist;
      ans = root->data;
    }

    if (dist == 0)
      return root->data;

    // * Binary search
    if (root->data < k) {
      root = root->right;
    } else {
      root = root->left;
    }
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
  int ans = findClosestElement(root, k);
  std::cout << "Closest node: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 05-closest-in-bst.cpp -o output && ./output
