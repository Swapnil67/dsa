/*
* Leetcode - 958
* Check Completeness of a Binary Tree

* Given the root of a binary tree, determine if it is a complete binary tree.
* In a complete binary tree, every level, except possibly the last, is completely filled, and 
* all nodes in the last level are as far left as possible. 
* It can have between 1 and 2h nodes inclusive at the last level h.

* Example 1:
* Input: 
*                   1        
*               /      \     
*             2         3
*           /  \      /   \  
*          4    5    6    x

* Input: root = [1,2,3,4,5,6]
* Output: true

* Example 2:
* Input: 
*                   1        
*               /      \     
*             2         3
*           /  \      /   \  
*          4    5    x    7

* Input: root = [1,2,3,4,5,null,7]
* Output: false

* https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

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

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

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

bool isCompleteTreeBFS(TreeNode* root) {
  std::queue<TreeNode *> q;
  q.push(root);

  bool past = false;
  while(!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr) {
      past = true;
    }
    else {
      // * Did we saw any null nodes in past
      if (past == true)
        return false;
      
      q.push(node->left);
      q.push(node->right);
    }
  }

  return true;
}

int countNodes(TreeNode* root) {
  if (!root)
    return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

bool dfs(TreeNode* root, int i, int total_nodes) {
  if (!root)
    return true;

  if (i > total_nodes)
    return false;

  return dfs(root->left, (2 * i), total_nodes) &&
         dfs(root->right, (2 * i + 1), total_nodes);
}

bool isCompleteTreeDFS(TreeNode* root) {
  int total_nodes = countNodes(root);
  // std::cout << "Total Nodes " << total_nodes << std::endl;

  int i = 1;
  return dfs(root, i , total_nodes);
}

int main(void) {
  // * testcase 1
  // TreeNode* root = new TreeNode(1);
  // root->left = new TreeNode(2);
  // root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  // root->left->right = new TreeNode(5);
  // root->right->left = new TreeNode(6);

  // * testcase 2
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(7);

  std::cout << "Input Binary Tree:" << std::endl;
  levelOrderTraversal(root);

  // bool ans = isCompleteTreeBFS(root);
  bool ans = isCompleteTreeDFS(root);
  std::cout << "Is BT complete: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 26-check-if-complete-bt.cpp -o output && ./output

