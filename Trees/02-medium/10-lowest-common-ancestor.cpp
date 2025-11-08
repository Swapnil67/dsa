/*
* Leetcode - 236
* Lowest Common Ancestor of a Binary Tree

* Binary Tree:
*                   3
*               /       \  
*             5          1
*           /  \       /  \  
*          6    2     0   7
*              / \     
*             7  4

* Example 1:
* Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
* Output: 3

* Example 2:
* Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4
* Output: 5

* Example 3:
* Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 7, q = 4
* Output: 2

* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
* https://www.naukri.com/code360/problems/lca-of-binary-tree_920541
* https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
*/

#include <vector>
#include <iostream>

typedef struct TreeNode TreeNode;

struct TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
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

bool rootToNode(TreeNode* root, TreeNode* node, std::vector<int> &path) {
  if (!root)
    return false;

  // * Push the cur node to path vector
  path.push_back(root->data);

  // * Found the node
  if (root->data == node->data)
    return true;

  // * If we found node in 'left' or 'right' return
  if (rootToNode(root->left, node, path) ||
      rootToNode(root->right, node, path))
    return true;

  // * Remove the node from path vector
  path.pop_back();

  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Use root to Node 
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(2N)
TreeNode* bruteForce(TreeNode* root, TreeNode* p, TreeNode* q) {
  // * Find path for 'p' node
  std::vector<int> pPathVec;
  rootToNode(root, p, pPathVec);
  printArr(pPathVec);

  // * Find path for 'q' node
  std::vector<int> qPathVec;
  rootToNode(root, q, qPathVec);
  printArr(qPathVec);

  int lca = -1;
  int i = 0, j = 0;
  while (i < pPathVec.size() && j < qPathVec.size()) {
    // * Keep updating the Lowest Common Ancestor
    if (pPathVec[i] == qPathVec[j])
      lca = pPathVec[i];
    i++, j++;
  }

  return new TreeNode(lca);
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // * If cur node is 'p' or 'q' or null the return cur node
  if (!root || root->data == p->data || root->data == q->data)
    return root;
  
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  // * Found our answer
  if (left && right) {
    
    return root;
  }

  return left != nullptr ? left : right;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  
  // TreeNode *p = new TreeNode(5);
  // TreeNode *q = new TreeNode(1);

  TreeNode *p = new TreeNode(5);
  TreeNode *q = new TreeNode(2);

  // TreeNode *ans = bruteForce(root, p, q);
  TreeNode *ans = lowestCommonAncestor(root, p, q);
  std::cout << "LCA of " << p->data << " & " << q->data << " is:  " << ans->data << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-lowest-common-ancestor.cpp -o output && ./output