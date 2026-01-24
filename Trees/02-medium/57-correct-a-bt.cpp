/*
 * Leetcode - 1660
 * Correct a Binary Tree 
 * 
 * You have a binary tree with a small defect. There is exactly one invalid node where its right child incorrectly 
 * points to another node at the same depth but to the invalid node's right.
 * 
 * Given the root of the binary tree with this defect, root, return the root of the binary tree after removing this 
 * invalid node and every node underneath it (minus the node it incorrectly points to).
 * 
 * 
 * Example 1:
 *                  1
 *               /     \  
 *             2  --->  3
 * Input: root = [1,2,3], fromNode = 2, toNode = 3
 * Output: [1,null,3]
 * 
 * 
 * Example 2:
 *                  1
 *               /     \  
 *             2  --->  3
 *           /   
 *          4     
 * Input: root = [1,2,3], fromNode = 2, toNode = 3
 * Output: [1,null,3]
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}


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

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

void levelOrderTraversal(TreeNode *root) {
  if (!root)
    return;

  std::queue<TreeNode *> q;
  q.push(root);

  while(!q.empty()) {
    int n = q.size();
    // * traverse the whole level
    while (n--) {
      TreeNode *node = q.front();
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

TreeNode *dfs(TreeNode *root, unordered_set<int>&seen) {
  if (!root)
    return root;

  // * Remove the invalid node and it's descendants.
  if (root->right && seen.count(root->right->data)) {
    return nullptr;
  }

  seen.insert(root->data);
  root->right = dfs(root->right, seen);
  root->left = dfs(root->left, seen);
  return root;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
TreeNode *correctBinaryTree(TreeNode *root) {
  unordered_set<int> seen;
  dfs(root, seen);
  return root;
}

int main(void) {
  // * testcase 1
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = root->right; // * invalid node

  std::cout << "Before Correcting Tree" << std::endl;
  levelOrderTraversal(root);

  std::cout << "After Correcting Tree" << std::endl;
  TreeNode *ans = correctBinaryTree(root);
  levelOrderTraversal(ans);
  
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 57-correct-a-bt.cpp -o output && ./output
