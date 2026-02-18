/*
* Leetcode - 226
* Invert Binary Tree
*
* Given the root of a binary tree, invert the tree, and return its root.
*
*
*                  4
*               /     \  
*             2        7
*           /  \     /   \  
*          1    3   6     9
*
* Example 1:
* Input: root = [4, 2, 7, 1, 3, 6, 9]
*
*                  4
*               /     \  
*             7        2
*           /  \     /   \  
*          9    6   3     1
*
* Output: [4, 7, 2, 9, 6, 3, 1]
*
* https://leetcode.com/problems/invert-binary-tree/description/
* https://www.naukri.com/code360/problems/invert-a-binary-tree_1281382
* https://www.geeksforgeeks.org/problems/mirror-tree/1
*/

// ! Amazon, Google, Meta, Microsoft

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

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

void levelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  // * Create the queue of TreeNode and push the root node
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    std::vector<int> level;
    int n = q.size();
    while (n--) {
      TreeNode *node = q.front();
      q.pop();                    // * pop the front node

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);

      level.push_back(node->data);
      std::cout << node->data << " ";
    }
    std::cout << std::endl;
  }
}


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Breadth First Search
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) [queue]
TreeNode *invertTreeBFS(TreeNode *root) {
  if (!root)
    return root;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    std::swap(node->left, node->right);
    
    if (node->left)
      q.push(node->left);

    if (node->right)
      q.push(node->right);
  }

  return root;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Depth First Search
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) [recursion stack]
TreeNode *invertTreeDFS(TreeNode *root) {
  if (!root)
    return nullptr;
  
  std::swap(root->left, root->right);
  invertTreeDFS(root->left);
  invertTreeDFS(root->right);
  return root;
}

int main(void) {
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);

  std::cout << "Tree Before Invert" << std::endl;
  levelOrder(root);
  
  // root = invertTreeBFS(root);
  root = invertTreeDFS(root);
  
  std::cout << "Tree After Invert" << std::endl;
  levelOrder(root);

  return 0;
}

// * run the code
// * g++ --std=c++17 17-invert-bt.cpp -o output && ./output
